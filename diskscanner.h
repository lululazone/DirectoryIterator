#ifndef DISKSCANNER_H
#define DISKSCANNER_H

#include "databasemanager.h"
#include "qobject.h"
#include "qthread.h"
class DiskScanner : public QObject
{
    Q_OBJECT
    QThread thread;
public:
    QSqlDatabase db;
    QString pathIn;
    DiskScanner();

public slots:
    void scanDisk(QString path,QSqlDatabase db);
    void threaded();
};

#endif // DISKSCANNER_H
