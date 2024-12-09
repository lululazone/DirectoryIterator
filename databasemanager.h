#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H
#include <QSqlDatabase>

#include <QObject>
class DatabaseManager
{
public:
    DatabaseManager();
    QSqlDatabase db;
    QString deleteTable(QString type);
    QStringList getTable(QString type);
    void scanDisk(QString type);
    QString appendToTable(QString tableName, QString value);
    void initTables();
    QString complexQuery(QString queryInput,QString fileName);
};

#endif // DATABASEMANAGER_H
