#include <QtWidgets>
#include <QtNetwork>

#include <stdlib.h>

#include "server.h"
#include <qlocalserver.h>
#include <qlocalsocket.h>
#include <QDebug>
#include <iostream>
#include <vector>
#include <sstream>
#include <QCoreApplication>
#include <QStringList>
#include <QDebug>

Server::Server(QWidget *parent)
    : QDialog(parent)
{
    connect_flag = 0;
    server = new QLocalServer(this);
    if (!server->listen("tmk_hmi_server")) {
        QMessageBox::critical(this, QString("tmk_hmi_server Server"),
                              QString("Unable to start the server: %1.")
                              .arg(server->errorString()));
        close();
        return;
    }
    qDebug() << QString("connect slot");
    connect(server, SIGNAL(newConnection()),this,SLOT(createConnection()));

}
int send_count = 0;
void Server::sendData(int addr,QString strs)
{
    if(1 == connect_flag)
    {
        QByteArray block;
        QDataStream out(&block, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_4_0);
        out << (quint32)0;
        if(++send_count > 10000)
            send_count = 0;
        out << QString("send%1:%2").arg(addr).arg(strs);
        out.device()->seek(0);
        out << (quint32)(block.size() - sizeof(quint32));
        socket->write(block);
    }
}
void Server::recvData()
{
    QByteArray rcv_data = socket->readAll();
    qDebug()<<"rcv_data:"<<rcv_data;
    getSocketData(&rcv_data);
}

void Server::createConnection()
{
    /*
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_0);
    out << (quint32)0;

    qDebug() << QString("discover new connection") ;
    out << QString("discover new connection");
    out.device()->seek(0);
    out << (quint32)(block.size() - sizeof(quint32));
    socket = server->nextPendingConnection();
    connect(socket, SIGNAL(readyRead()), this, SLOT(recvData()));
    //connect(sendButton,SIGNAL(clicked()),this,SLOT(sendData()));
    socket->write(block);
    socket->flush();
    qDebug() << QString("connect start");
    connect_flag = 1;*/
}

void Server::endConnection()
{
    socket->flush();
    //qDebug() << QString("send end");
    qDebug() << QString("disconnectFromServer");
    socket->disconnectFromServer();
}


bool Server::isNumberValid(const QString& number) {
    bool ok;
    number.toInt(&ok);
    return ok;
}

QVector<QString> Server:: extractNumbers(QString input) {
    QVector<QString> numbers;
    QStringList stringList = input.split(',');
    foreach (const QString& str, stringList) {
        //if (isNumberValid(str))
        {
            numbers.append(str);
        }
    }
    return numbers;
}
/*********************************************************************************************************
** 函数名称GetPcLinkData
** 函数描述: Pclink协议处理数据
** 输入参数：buf:命令缓存，len，数据长度
**           无
** 返回值  ：TRUE:处理成功，FALSE:处理失败
*********************************************************************************************************/
bool Server:: getSocketData(QByteArray* socketbuf)
{
    int start_addr;
    QString text_addr;
    QVector<QString> numbers;
    QString saveBuf = *socketbuf;
    if(socketbuf->startsWith("SendData"))
    {
        saveBuf.remove(0,8);
        numbers = extractNumbers(saveBuf);
        text_addr = numbers[0];

        if(isNumberValid(text_addr))
        {
            QString addr_str = numbers[0];
            start_addr = addr_str.toInt();

            for(int i = 0; i < numbers.size() - 1; ++i)
            {
                qDebug() << QString("start addr: %1").arg(start_addr + i);
                qDebug() << QString("out string: %1").arg(numbers[i + 1]);
                emit comm_updateInterfaceDataSignal(start_addr + i,numbers[i + 1]);
            }
        }else
        {
            return false;
        }


    }else
        if(socketbuf->startsWith("SendText"))
        {
            saveBuf.remove(0,8);
            QStringList parts = saveBuf.split(",");
            text_addr = parts[0];
            if(isNumberValid(text_addr))
            {
                start_addr = text_addr.toInt();
                saveBuf.remove(0,text_addr.size() + 1);
                emit comm_updateInterfaceDataSignal(start_addr,saveBuf);
            }else
            {
                return false;
            }


        }else
        {
            return false;
        }
    return true;
}



