#include <QtWidgets>
#include <QtNetwork>

#include <stdlib.h>

#include "tcp_server.h"
#include <QDebug>
#include <iostream>
#include <vector>
#include <sstream>
#include <QCoreApplication>
#include <QStringList>
#include <QDebug>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>

tcpServer::tcpServer(QWidget *parent)
    : QDialog(parent)
{
    connect_flag = 0;
    tcp_server = new QTcpServer(this);

    if (!tcp_server->listen(QHostAddress::LocalHost, 12345)) {
        QMessageBox::critical(this, "Server",
                              "Unable to start the server: " + tcp_server->errorString());
        close();
        return;
    }

    qDebug() << "Server started on IP: " << tcp_server->serverAddress().toString()
             << " and Port " << tcp_server->serverPort();

    connect(tcp_server, SIGNAL(newConnection()), this, SLOT(createConnection()));
}
int tcp_send_count = 0;
bool tcpServer::sendData(int addr,QString strs)
{

    if(1 == connect_flag)
    {
        /*QByteArray block;
        QDataStream out(&block, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_4_0);
        out << (quint32)0;
        if(++tcp_send_count > 10000)
            tcp_send_count = 0;
        //tcp_socket->write("adfadfasdfaa");
        out << QString("send%1:%2").arg(addr).arg(strs);
        out.device()->seek(0);        
        out << (quint32)(block.size() - sizeof(quint32));
        QString outstr = QString(block);
        qDebug() << QString("send data is %1").arg(outstr);
        tcp_socket->write(block);*/
        char sendbuf[1024] = { 0 };
        strcpy(sendbuf,"QtData");
        char databuf[32] = { 0 };
        sprintf(databuf,"%d,",addr);
        strcat(sendbuf,databuf);
        QByteArray ba = strs.toLatin1();
        char *strbuf = ba.data();
        strcat(sendbuf,strbuf);
        strcat(sendbuf,"SendEnd");
        tcp_socket->write(sendbuf);
        return true;
    }
    return false;
}
bool tcpServer::sendText(int addr,QString strs)
{

    if(1 == connect_flag)
    {
        /*QByteArray block;
        QDataStream out(&block, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_4_0);
        out << (quint32)0;
        if(++tcp_send_count > 10000)
            tcp_send_count = 0;
        //tcp_socket->write("adfadfasdfaa");
        out << QString("send%1:%2").arg(addr).arg(strs);
        out.device()->seek(0);
        out << (quint32)(block.size() - sizeof(quint32));
        QString outstr = QString(block);
        qDebug() << QString("send data is %1").arg(outstr);
        tcp_socket->write(block);*/
        char sendbuf[1024] = { 0 };
        strcpy(sendbuf,"QtText");
        char databuf[32] = { 0 };
        sprintf(databuf,"%d,",addr);
        strcat(sendbuf,databuf);
        QByteArray ba = strs.toLatin1();
        char *strbuf = ba.data();
        strcat(sendbuf,strbuf);
        strcat(sendbuf,"SendEnd");
        tcp_socket->write(sendbuf);
        return true;
    }
    return false;
}
QByteArray m_buffer_car;
void tcpServer::recvData()
{
    if(tcp_socket->bytesAvailable() <=0)
        return;
    QByteArray buffer = tcp_socket->readAll();    
    m_buffer_car.append(buffer);
    qDebug()<<"rcv_data:"<<m_buffer_car;
    while (m_buffer_car.size() > 17) {

        int startIndex = m_buffer_car.indexOf("Send");
        if (startIndex == -1) {
            // 如果没有找到符合条件的起始字符串，则退出循环
            m_buffer_car.clear();
            break;
        }

        // 查找第一个符合条件的结束字符串 "SendEnd"
        int endIndex = m_buffer_car.indexOf("SendEnd", startIndex);
        if (endIndex == -1) {
            // 如果没有找到符合条件的结束字符串，则退出循环
            break;
        }

        // 提取符合条件的字符串并进行处理
        QByteArray extractedData = m_buffer_car.mid(startIndex, endIndex - startIndex + 7); // 加上 "SendEnd" 的长度
        qDebug() << "Extracted data:" << extractedData;
        getSocketData(&extractedData);
        // 清除提取的字符串
        m_buffer_car.remove(0, endIndex + 7); // 加上 "SendEnd" 的长度
    }
    //clentLineEdit->setText(QString("getdata:%1").arg(QString(rcv_data)));
}

void tcpServer::createConnection()
{

    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_0);
    out << (quint32)0;

    qDebug() << QString("discover new connection") ;
    out << QString("discover new connection");
    out.device()->seek(0);
    out << (quint32)(block.size() - sizeof(quint32));
    tcp_socket = tcp_server->nextPendingConnection();
    connect(tcp_socket, SIGNAL(readyRead()), this, SLOT(recvData()));
    tcp_socket->write(block);
    tcp_socket->flush();
    qDebug() << QString("connect start");
    connect_flag = 1;
}

void tcpServer::endConnection()
{
    tcp_socket->flush();
    //qDebug() << QString("send end");
    qDebug() << QString("disconnectFromServer");
    //tcp_socket->disconnectFromServer();
}


bool tcpServer::isNumberValid(const QString& number) {
    bool ok;
    number.toInt(&ok);
    return ok;
}

QVector<QString> tcpServer::extractNumbers(QString input) {
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
bool tcpServer:: getSocketData(QByteArray* socketbuf)
{
    int start_addr;
    QString text_addr;
    QVector<QString> numbers;
    QString saveBuf = *socketbuf;
    if((socketbuf->startsWith("SendData")) && (socketbuf->endsWith("SendEnd")))
    {
        saveBuf.remove(0,8);
        saveBuf.remove(saveBuf.length() - 7 ,7);
        numbers = extractNumbers(saveBuf);
        text_addr = numbers[0];

        if(isNumberValid(text_addr))
        {
            QString addr_str = numbers[0];
            start_addr = addr_str.toInt();

            for(int i = 0; i < numbers.size() - 1; ++i)
            {
                //qDebug() << QString("start addr: %1").arg(start_addr + i);
                //qDebug() << QString("out string: %1").arg(numbers[i + 1]);
                emit comm_updateInterfaceDataSignal(start_addr + i,numbers[i + 1]);
            }
        }else
        {
            return false;
        }


    }else
        if((socketbuf->startsWith("SendText"))&& (socketbuf->endsWith("SendEnd")))
        {
            saveBuf.remove(0,8);
            saveBuf.remove(saveBuf.length() - 7 ,7);
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



