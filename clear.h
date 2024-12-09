#ifndef CLEAR_H
#define CLEAR_H

#include "acommand.h"
#include <QStringList>
class Clear : public ACommand
{
public:
    Clear();

    // ACommand interface
public:
    Outputexec execute(QStringList input,DatabaseManager dbManager);
    bool command();
    int conditionIsValid(QList<QString> token);
    int handleError(int errorCode);
};

#endif // CLEAR_H
