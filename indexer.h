#ifndef INDEXER_H
#define INDEXER_H

#include "acommand.h"
#include <QStringList>
#include <QMap>
class Indexer : public ACommand
{
public:
    Indexer();
    enum IndexerOption {STATUS,START,STOP,PAUSE,RESUME,ERROR};

    QMap<IndexerOption, std::function<QString()>> actions;
    QMap<QString,IndexerOption> stringMap;
    void initializeActions();
    void initializeStringMap();
    QString start();
    QString stop();
    QString status();
    QString pause();
    QString resume();

    // ACommand interface
public:
    Outputexec execute(QStringList input, DatabaseManager dbManager);
    bool command();
    int conditionIsValid(QList<QString> token);
    int handleError(int errorCode);
};

#endif // INDEXER_H
