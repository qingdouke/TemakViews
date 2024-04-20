#ifndef TCP_SERVER_H
#define TCP_SERVER_H

#include <QDialog>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>


QT_BEGIN_NAMESPACE
class QLabel;
class QPushButton;
class QTcpServer;
class QLineEdit;

QT_END_NAMESPACE

class tcpServer : public QDialog
{
    Q_OBJECT

public:
    tcpServer(QWidget *parent = 0);
    int connect_flag;
    void sendData(int,QString);
    void sendText(int,QString);
private slots:
    void recvData();
    void createConnection();
    void endConnection();
    bool getSocketData(QByteArray* socketbuf);
    bool isNumberValid(const QString& number);
    QVector<QString>  extractNumbers(QString input);
private:
    int send_count;
    int recv_count;
    QTcpServer *tcp_server;
    QTcpSocket *tcp_socket;
signals:
    void updateInterfaceNumberSignal(int,QString);
    void comm_updateInterfaceDataSignal(int,QString);
};

#endif
