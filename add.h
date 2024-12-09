#ifndef ADD_H
#define ADD_H

#include "acommandwithbaseoption.h"
#include <QStringList>
class Add : public ACommandWithBaseOption
{
public:
    Add();

    // ACommand interface
public:
    Outputexec execute(QStringList input,DatabaseManager dbManager);
    bool command();
    int conditionIsValid(QStringList token);
    int handleError(int errorCode);

    // ACommandWithBaseOption interface
public:
    bool command(Options cmdOption);
};

#endif // ADD_H
