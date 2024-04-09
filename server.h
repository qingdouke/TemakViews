#ifndef SERVER_H
#define SERVER_H

#include <QDialog>
#include <qlocalserver.h>
#include <qlocalsocket.h>


QT_BEGIN_NAMESPACE
class QLabel;
class QPushButton;
class QLocalServer;
class QLineEdit;

QT_END_NAMESPACE

class Server : public QDialog
{
    Q_OBJECT

public:
    Server(QWidget *parent = 0);
    int connect_flag;
    void sendData(int,QString);
private slots:
    void recvData();
    void createConnection();
    void endConnection();
    bool getSocketData(QByteArray* socketbuf);
    bool isNumberValid(const QString& number);
private:
    int send_count;
    int recv_count;
    QLocalServer *server;
    QLocalSocket *socket;
signals:
    void updateInterfaceNumberSignal(int,QString);
    void comm_updateInterfaceDataSignal(int,QString);
};

#endif
