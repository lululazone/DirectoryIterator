#ifndef PUSH_H
#define PUSH_H

#include "acommand.h"
#include <QStringList>
class Push : public ACommand
{
public:
    Push();

    // ACommand interface
public:
    Outputexec execute(QStringList input, DatabaseManager dbManager);
    bool command();
    int conditionIsValid(QList<QString> token);
    int handleError(int errorCode);
};

#endif // PUSH_H
