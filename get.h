#ifndef GET_H
#define GET_H

#include "acommandwithbaseoption.h"
#include <QStringList>

class Get : public ACommandWithBaseOption
{
public:
    Get();



    // ACommand interface
public:
    Outputexec execute(QStringList input, DatabaseManager dbManager);
    bool command();
    int conditionIsValid(QList<QString> token);
    int handleError(int errorCode);

    // ACommandWithBaseOption interface
public:
    bool command(Options cmdOption);
};

#endif // GET_H
