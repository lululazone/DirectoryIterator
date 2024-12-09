#ifndef SEARCH_H
#define SEARCH_H

#include "acommand.h"
#include <QStringList>
class Search : public ACommand
{
public:
    Search();

    // ACommand interface
public:
    QMap<QString,QStringList> dialectMap;
    Outputexec execute(QStringList input, DatabaseManager dbManager);
    bool command();
    int conditionIsValid(QList<QString> token);
    int handleError(int errorCode);
};

#endif // SEARCH_H
