#include "databasemanager.h"
#include "qsqlerror.h"
#include "qsqlquery.h"
#include "qsqlrecord.h"
#include "diskscanner.h"
DatabaseManager::DatabaseManager() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./qtdb.db");
    if(db.open()){
        qDebug() << "Database open";
        initTables();
    }
}

QString DatabaseManager::deleteTable(QString type)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./qtdb.db");
    if(db.open()){
        QSqlQuery query;
        query.prepare("DELETE FROM "+type);
        if(!query.exec()){
            return "failed to delete table: "+type;
        }
    }
    return "failed to connect to the database";
}

QStringList DatabaseManager::getTable(QString type)
{
    if(type == ""){
        return *new QStringList();
    }
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./qtdb.db");
    if(db.open()){
        QSqlQuery query;
        query.prepare("SELECT * FROM "+type);
        query.exec();
        QStringList result;
        if(!query.exec()){
            return result;
        }
        int id = query.record().indexOf("name");
        while(query.next()){
            result.append(query.value(id).toString());
        }
        return result;
    }
    return {"failed to connect to the database"};
}

void DatabaseManager::scanDisk(QString type)
{
    DiskScanner threaded;
    QStringList pathList = getTable(type);
    if (pathList.isEmpty()){
        return;
    }
    foreach (QString path, pathList) {
        threaded.scanDisk(path, db);
    }
}

void DatabaseManager::initTables()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./qtdb.db");
    if(db.open()){
        QSqlDatabase db = QSqlDatabase::database("QSQLITE");
        QSqlQuery query;
        query.prepare("CREATE TABLE IF NOT EXISTS 'WHITELIST' ( \
                      id INTEGER PRIMARY KEY AUTOINCREMENT, \
                      name TEXT NOT NULL)");
            query.exec();
        query.prepare("CREATE TABLE IF NOT EXISTS 'BLACKLIST' ( \
                      id INTEGER PRIMARY KEY AUTOINCREMENT, \
                      name TEXT NOT NULL)");
            query.exec();
        query.prepare("CREATE TABLE IF NOT EXISTS 'FILTERS'( \
                      id INTEGER PRIMARY KEY AUTOINCREMENT, \
                      name TEXT NOT NULL)");
            query.exec();
        query.prepare("CREATE TABLE IF NOT EXISTS 'SKIPPED_FILTERS' ( \
                      id INTEGER PRIMARY KEY AUTOINCREMENT, \
                      name TEXT NOT NULL)");
            query.exec();

    }
}
