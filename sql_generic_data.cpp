#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include "sqliteoperator.h"
#include "sql_generic_data.h"

QSqlDatabase database;
void readComDBData(QVector<lcd_show_data_f>& lcd_vector)
{
    //创建并打开SQLite数据库
       SqliteOperator sqlLcdComData;
       sqlLcdComData.openDb();

       // 创建数据表
       QString tabNameStr = QString("generic_data");
       sqlLcdComData.createTable(tabNameStr);

       // 判断数据表是否存在

       //qDebug() << "isTabelExist：" <<sqlLcdComData.isTableExist(tabNameStr);

       // 查询全部数据
       sqlLcdComData.queryTable(tabNameStr,lcd_vector);
       qDebug() << endl;
       /*for (int i = 0; i < lcd_vector.size(); i++) {
               qDebug() << QString("%1  %2  %3  %4 %5").arg(i).arg(lcd_vector[i].font).arg(lcd_vector[i].str).arg(lcd_vector[i].data).arg(lcd_vector[i].other);
               //qDebug() << endl;
           }*/
       //关闭数据库
       sqlLcdComData.closeDb();
       //writeTouchDBData(2, 3,103,111,"endtime", 1,"hei",18,"red","left","no");
}


void writeTouchDBData(int id, int page ,int addr,int data, QString str, int swi, QString font, int size, QString color, QString position, QString other)
{
    //创建并打开SQLite数据库
       SqliteOperator sqlTest;
       sqlTest.openDb();

       // 创建数据表
       QString str1 = QString("lcd_touch_data");
       sqlTest.createTable(str1);

       // 判断数据表是否存在

       //qDebug() << "isTabelExist：" <<sqlTest.isTableExist(str1);
       // 修改数据
       //sqlTest.modifyData(str1,id, page,addr,data,str, swi,font,size,color,position,other);
      // sqlTest.modifyData(str1,1, 3,102,100,"endtime", 1,"song",18,"red","left","no");
       sqlTest.replaceData(str1,id, page,addr,data,str, swi,font,size,color,position,other);
       // 查询全部数据
       QVector<lcd_show_data_f> lcd_vector;
       sqlTest.queryTable(str1,lcd_vector);
       qDebug() << endl;
       //关闭数据库
       sqlTest.closeDb();
}
/*
void readDBData(void)
{.0
    //创建并打开SQLite数据库
       SqliteOperator sqlTest;
       sqlTest.openDb();

       // 创建数据表
       QString str1 = QString("generic_data");
       sqlTest.createTable(str1);

       // 判断数据表是否存在

       qDebug() << "isTabelExist：" <<sqlTest.isTableExist(str1);

       // 插入单条数据
       lcd_show_data_f w2dbaTest1 = {1, 1,101,351,"starttime", 1,"song",16,"black","left","no"};
       lcd_show_data_f w2dbaTest2 = {2, 1,102,352,"endtime", 1,"song",18,"red","left","no"};
       sqlTest.singleInsertData(str1,w2dbaTest1);
       sqlTest.singleInsertData(str1,w2dbaTest2);

       // 插入多条数据
       QList<lcd_show_data_f> list;
       lcd_show_data_f w2dbaTest3 = {3, 2,103,353,"pgmtime", 1,"hei",16,"black","left","no"};
       lcd_show_data_f w2dbaTest4 = {4, 2,104,354,"sgmtime", 1,"hei",16,"black","left","no"};
       list.append(w2dbaTest3);
       list.append(w2dbaTest4);
       sqlTest.moreInsertData(str1,list);
       // 查询全部数据
       sqlTest.queryTable(str1);
       qDebug() << endl;

       // 修改数据
       sqlTest.modifyData(str1,2, 3,102,100,"endtime", 1,"song",18,"red","left","no");
       // 查询全部数据
       sqlTest.queryTable(str1);
       qDebug() << endl;

       // 删除数据
       sqlTest.deleteData(str1,2);
       // 查询全部数据
       sqlTest.queryTable(str1);
       qDebug() << endl;

       // 删除数据表
       sqlTest.deleteTable(str1);
       //关闭数据库
       sqlTest.closeDb();
}*/

