#ifndef SQLITEOPERATOR_H
#define SQLITEOPERATOR_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

typedef struct
{
    int id;
    int page;
    int addr;
    int data;
    QString str;
    int swi;
    QString font;
    int size;
    QString color;
    QString position;
    QString other;
}lcd_show_data_f;

class SqliteOperator
{
public:
    SqliteOperator();

    // 打开数据库
    bool openDb(void);
    // 创建数据表
    void createTable(QString& tableName);
    // 判断数据表是否存在
    bool isTableExist(QString& tableName);
    // 查询全部数据
    void queryTable(QString& tableName,QVector<lcd_show_data_f>& alldb);
    // 插入数据
    void singleInsertData(QString& tableName,lcd_show_data_f &singleData); // 插入单条数据
    void moreInsertData(QString& tableName,QList<lcd_show_data_f> &moreData); // 插入多条数据
    // 修改数据
    void modifyData(QString& tableName,int id, int page,int addr,int data, QString str, int swi, QString font, int size, QString color, QString position, QString other);
    void replaceData(QString& tableName,int id, int page ,int addr,int data, QString str, int swi, QString font, int size, QString color, QString position, QString other);
    // 删除数据
    void deleteData(QString& tableName,int id);
    //删除数据表
    void deleteTable(QString& tableName);
    // 关闭数据库
    void closeDb(void);

private:
    QSqlDatabase database;// 用于建立和数据库的连接
};

#endif //  SQLITEOPERATOR_H
