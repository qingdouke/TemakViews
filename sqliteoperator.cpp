#include "sqliteoperator.h"

// 构造函数中初始化数据库对象，并建立数据库
SqliteOperator::SqliteOperator()
{
    if (QSqlDatabase::contains("qt_sql_default_connection"))
    {
        database = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        // 建立和SQlite数据库的连接
        database = QSqlDatabase::addDatabase("QSQLITE");
        // 设置数据库文件的名字
        database.setDatabaseName("MyDataBase.db");
    }
}

// 打开数据库
bool SqliteOperator::openDb()
{
    if (!database.open())
    {
        qDebug() << "Error: Failed to connect database." << database.lastError();
    }
    else
    {
        // do something
    }

    return true;
}

// 创建数据表
void SqliteOperator::createTable(QString& tableName)
{
    // 用于执行sql语句的对象
    QSqlQuery sqlQuery;
    // 构建创建数据库的sql语句字符串
    QString createSql = QString("CREATE TABLE %1 (\
                            id INT PRIMARY KEY NOT NULL,\
                            page INT,\
                            addr INT NOT NULL,\
                            data INT,\
                            str TEXT,\
                            swi INT,\
                            font TEXT,\
                            size INT,\
                            color TEXT,\
                            position TEXT,\
                            other TEXT)").arg(tableName);
    //createSql.insert(13 ,dbname);
    sqlQuery.prepare(createSql);
    // 执行sql语句
    if(!sqlQuery.exec())
    {
        //qDebug() << "Error: Fail to create table. " << sqlQuery.lastError();
    }
    else
    {
        qDebug() << "Table created!";
    }
}

// 判断数据库中某个数据表是否存在
bool SqliteOperator::isTableExist(QString& tableName)
{
    QSqlDatabase database = QSqlDatabase::database();
    if(database.tables().contains(tableName))
    {
        return true;
    }

    return false;
}

// 查询全部数据
void SqliteOperator::queryTable(QString& tableName ,QVector<lcd_show_data_f>& alldb)
{
    QSqlQuery sqlQuery;
    lcd_show_data_f tmpdata;
    lcd_show_data_f nulldata;
    nulldata.str = "null";
    nulldata.font = "null";
    nulldata.position = "null";
    nulldata.other = "null";

    if(!sqlQuery.exec(QString("SELECT * FROM %1").arg(tableName)))
    {
        qDebug() << "Error: Fail to query table. " << sqlQuery.lastError();
    }
    else
    {
        while(sqlQuery.next())
        {

            tmpdata.id = sqlQuery.value(0).toInt();
            tmpdata.page = sqlQuery.value(1).toInt();
            tmpdata.addr = sqlQuery.value(2).toInt();
            tmpdata.data = sqlQuery.value(3).toInt();
            tmpdata.str = sqlQuery.value(4).toString();
            tmpdata.swi = sqlQuery.value(5).toInt();
            tmpdata.font  = sqlQuery.value(6).toString();
            tmpdata.size = sqlQuery.value(7).toInt();
            tmpdata.color  = sqlQuery.value(8).toString();
            tmpdata.position  = sqlQuery.value(9).toString();
            tmpdata.other = sqlQuery.value(10).toString();
            while(alldb.size() < tmpdata.id)
            {
                alldb.push_back(nulldata);
            }

            if(tmpdata.id < alldb.size())
            {
                alldb[tmpdata.id] = tmpdata;
            }else
            {
                alldb.push_back(tmpdata);
            }

           /* qDebug()<<QString("id:%1   page:%2   addr:%3   data:%4   str:%5   swi:%6   font:%7   size:%8   color:%9   position:%10   other:%11")
                      .arg(tmpdata.id).arg(tmpdata.page).arg(tmpdata.addr).arg(tmpdata.data).arg(tmpdata.str).arg(tmpdata.swi)
                      .arg(tmpdata.font).arg(tmpdata.size).arg(tmpdata.color).arg(tmpdata.position).arg(tmpdata.other);*/
        }
    }
}

// 插入单条数据
void SqliteOperator::singleInsertData(QString& tableName,lcd_show_data_f &singledb)
{
    QSqlQuery sqlQuery;
    sqlQuery.prepare(QString("INSERT INTO %1 VALUES(:id,:page,:addr,:data,:str,:swi,:font,:size,:color,:position,:other)").arg(tableName));
    sqlQuery.bindValue(":id", singledb.id);
    sqlQuery.bindValue(":page", singledb.page);
    sqlQuery.bindValue(":addr", singledb.addr);
    sqlQuery.bindValue(":data", singledb.data);
    sqlQuery.bindValue(":str", singledb.str);
    sqlQuery.bindValue(":swi", singledb.swi);
    sqlQuery.bindValue(":font", singledb.font);
    sqlQuery.bindValue(":size", singledb.size);
    sqlQuery.bindValue(":color", singledb.color);
    sqlQuery.bindValue(":position", singledb.position);
    sqlQuery.bindValue(":other", singledb.other);
    if(!sqlQuery.exec())
    {
        qDebug() << "Error: Fail to insert data. " << sqlQuery.lastError();
    }
    else
    {
        // do something
    }
}

// 插入多条数据
void SqliteOperator::moreInsertData(QString& tableName,QList<lcd_show_data_f>& moredb)
{
    // 进行多个数据的插入时，可以利用绑定进行批处理
    QSqlQuery sqlQuery;
    sqlQuery.prepare(QString("INSERT INTO %1 VALUES(?,?,?,?,?,?,?,?,?,?,?)").arg(tableName));
    QVariantList idList,pageList,addrList,dataList,strList,swiList,fontList,sizeList,colorList,positionList,otherList;
    for(int i=0; i< moredb.size(); i++)
    {
        idList <<  moredb.at(i).id;
        pageList << moredb.at(i).page;
        addrList << moredb.at(i).addr;
        dataList << moredb.at(i).data;
        strList << moredb.at(i).str;
        swiList << moredb.at(i).swi;
        fontList << moredb.at(i).font;
        sizeList << moredb.at(i).size;
        colorList << moredb.at(i).color;
        positionList << moredb.at(i).position;
        otherList << moredb.at(i).other;
    }
    sqlQuery.addBindValue(idList);
    sqlQuery.addBindValue(pageList);
    sqlQuery.addBindValue(addrList);
    sqlQuery.addBindValue(dataList);
    sqlQuery.addBindValue(strList);
    sqlQuery.addBindValue(swiList);
    sqlQuery.addBindValue(fontList);
    sqlQuery.addBindValue(sizeList);
    sqlQuery.addBindValue(colorList);
    sqlQuery.addBindValue(positionList);
    sqlQuery.addBindValue(otherList);

    if (!sqlQuery.execBatch()) // 进行批处理，如果出错就输出错误
    {
        qDebug() << sqlQuery.lastError();
    }
}

// 修改数据
void SqliteOperator::modifyData(QString& tableName,int id, int page ,int addr,int data, QString str, int swi, QString font, int size, QString color, QString position, QString other)
{
    qDebug() << "start updated data!";
    QSqlQuery sqlQuery;
    sqlQuery.prepare(QString("UPDATE %1 SET page=?,addr=?,data=?,str=?,swi=?,font=?,size=?,color=?,position=?,other=? WHERE id=?").arg(tableName));
    //sqlQuery.prepare("UPDATE lcd_touch_data SET page=?,addr=?,data=?,str=?,swi=?,font=?,size=?,color=?,position=?,other=? WHERE id=?");

    sqlQuery.addBindValue(page);
    sqlQuery.addBindValue(addr);
    sqlQuery.addBindValue(data);
    sqlQuery.addBindValue(str);
    sqlQuery.addBindValue(swi);
    sqlQuery.addBindValue(font);
    sqlQuery.addBindValue(size);
    sqlQuery.addBindValue(color);
    sqlQuery.addBindValue(position);
    sqlQuery.addBindValue(other);
    sqlQuery.addBindValue(id);
    qDebug() << "exec updated data!";
    if(!sqlQuery.exec())
    {
        qDebug() << sqlQuery.lastError();
    }
    else
    {
        qDebug() << "updated data success!";
    }
}

// 增加或替换数据
void SqliteOperator::replaceData(QString& tableName,int id, int page ,int addr,int data, QString str, int swi, QString font, int size, QString color, QString position, QString other)
{
    //qDebug() << "start replace data!";
    QSqlQuery sqlQuery;
    sqlQuery.prepare(QString("REPLACE INTO %1 (id,page,addr,data,str,swi,font,size,color,position,other) VALUES (?,?,?,?,?,?,?,?,?,?,?)").arg(tableName));
    sqlQuery.addBindValue(id);
    sqlQuery.addBindValue(page);
    sqlQuery.addBindValue(addr);
    sqlQuery.addBindValue(data);
    sqlQuery.addBindValue(str);
    sqlQuery.addBindValue(swi);
    sqlQuery.addBindValue(font);
    sqlQuery.addBindValue(size);
    sqlQuery.addBindValue(color);
    sqlQuery.addBindValue(position);
    sqlQuery.addBindValue(other);
    //qDebug() << "exec replace data!";
    if(!sqlQuery.exec())
    {
        qDebug() << sqlQuery.lastError();
    }
    else
    {
        qDebug() << "replace data success!";
    }
}
// 删除数据
void SqliteOperator::deleteData(QString& tableName,int id)
{
    QSqlQuery sqlQuery;    
    sqlQuery.exec(QString("DELETE FROM %1 WHERE id = %2").arg(tableName).arg(id));
    if(!sqlQuery.exec())
    {
        qDebug()<<sqlQuery.lastError();
    }
    else
    {
        qDebug()<<"deleted data success!";
    }
}

//删除数据表
void SqliteOperator::deleteTable(QString& tableName)
{
    QSqlQuery sqlQuery;

    sqlQuery.exec(QString("DROP TABLE %1").arg(tableName));
    if(sqlQuery.exec())
    {
        qDebug() << sqlQuery.lastError();
    }
    else
    {
        qDebug() << "deleted table success";
    }
}

void SqliteOperator::closeDb(void)
{
    database.close();
}
