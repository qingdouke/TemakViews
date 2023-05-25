#include "data.h"
#include "qtimer.h"
#include <QDebug>

Data::Data(QObject *parent)
    : QObject{parent}
{
//    int res = sqlite3_open("/test/first.db",&pDb);
//    if(res != SQLITE_OK){
//        qDebug()<<"sqlite open faild......";
//    }
    //测试曲线
    num = 12;
    size = 1000;
    xdata.resize(num);
    data.resize(num);
    for(int i=0 ; i<num ; i++)
    {
        xdata[i].resize(size);
        data[i].resize(size);
    }
    startTime = "2023-3-28 08:42:44";
    dataInfoSize = num*2+3;
    dataInfo = new double[dataInfoSize];
    dataInfo[0] = 0.01;
    dataInfo[1] = 0;
    dataInfo[2] = 10;
    dataInfo[3] = -1;
    dataInfo[4] = 1;
    dataInfo[5] = -5;
    dataInfo[6] = 5;
    axisInfo = new QString[num];
    axisInfo[0] = "Temperature(°C)";
    axisInfo[1] = "Humidity(%)";
    status=1;
    endSize = size;
    for(int i=0 ; i<endSize ; i++)
    {
        xdata[0][i] = i*1.0/100*1.0;
        xdata[1][i] = i*1.0/100*1.0;
        xdata[2][i] = i*1.0/100*1.0;
        xdata[3][i] = i*1.0/100*1.0;
        xdata[4][i] = i*1.0/100*1.0;
        xdata[5][i] = i*1.0/100*1.0;
        xdata[6][i] = i*1.0/100*1.0;
        xdata[7][i] = i*1.0/100*1.0;
        xdata[8][i] = i*1.0/100*1.0;
        xdata[9][i] = i*1.0/100*1.0;
        xdata[10][i] = i*1.0/100*1.0;
        xdata[11][i] = i*1.0/100*1.0;
        data[0][i] = sin(i*1.0/100*1.0);
        data[1][i] = cos(i*1.0/100*1.0);
        data[2][i] = asin((i*1.0/100*1.0));
        data[3][i] = acos((i*1.0/100*1.0));
        data[4][i] = tan((i*1.0/100*1.0));
        data[5][i] = atan((i*1.0/100*1.0));
        data[6][i] = sin((i*1.0/100*1.0)+1);
        data[7][i] = cos((i*1.0/100*1.0)+1);
        data[8][i] = asin((i*1.0/100*1.0)+1);
        data[9][i] = acos((i*1.0/100*1.0)+1);
        data[10][i] = tan((i*1.0/100*1.0)+1);
        data[11][i] = atan((i*1.0/100*1.0)+1);
    }
}

Data::~Data(){
//    sqlite3_close(pDb);
}

void Data::dataFunction(int pageID)
{
    switch (pageID) {
    case 1:
    {
        while(isRunning)
        {
//            this->send_temperaturePv_signals();
            qDebug()<<"current ID:"<<pageID;
            QThread::msleep(1000);
        }
        break;
    }
    case 2:
    {
        while(isRunning)
        {
            qDebug()<<"current ID:"<<pageID;
            QThread::msleep(1000);
        }
        break;
    }
    case 3:
    {
        while(isRunning)
        {
//            this->send_curveData_signals();
            qDebug()<<"current ID:"<<pageID;
            QThread::msleep(1000);
        }
        break;
    }
    default:
        qDebug()<<"UnkonwPageID!"<<"current ID:"<<pageID;
        QThread::msleep(1000);
        break;
    }
}

//static int sql_callback(void *arg, int col, char **str, char **name)
//{
//    //恢复对象的类型
//    Data *pDb = static_cast<Data *>(arg);
//    pDb->callback_strs = str[0];
//    return SQLITE_OK;
//}

void Data::send_temperaturePv_signals()
{
//    QString sql = "SELECT TPV FROM Base WHERE ID=1;";
//    int res = sqlite3_exec(pDb,sql.toStdString().c_str(),sql_callback,this,nullptr);
//    if(res!=SQLITE_OK){
//        qDebug()<<"select faild......try restart......";
//        QThread::msleep(100);
//        return;
//    }
//    this->temperaturePv = callback_strs;
    emit updateTemperaturePv(this->temperaturePv);
}

void Data::send_curveData_signals()
{
    emit updateCurve(num,size,xdata,data,startTime,dataInfo,axisInfo,status);
}
