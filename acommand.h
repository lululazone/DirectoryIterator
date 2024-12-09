#ifndef ACOMMAND_H
#define ACOMMAND_H

#include "databasemanager.h"
#include "outputexec.h"
#include <QString>
class ACommand
{
public:
    ACommand();
    Outputexec execute(QStringList input,DatabaseManager dbManager);
    int conditionIsValid(QList<QString> token);
    int handleError(int errorCode);
};

#endif // ACOMMAND_H
