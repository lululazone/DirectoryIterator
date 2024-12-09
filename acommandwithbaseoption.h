#ifndef ACOMMANDWITHBASEOPTION_H
#define ACOMMANDWITHBASEOPTION_H

#include "acommand.h"
#include <qmap>
class ACommandWithBaseOption : public ACommand
{
public:
    ACommandWithBaseOption();
    void initialiseStringMap();
    enum Options {WHITELIST,BLACKLIST,FILTERS,SKIPPED_FILTERS,ERROR};
    virtual bool command(Options cmdOption) = 0;
    Options FindOption(QStringList input);
    QMap<Options,QString> commandMap;

private:

};

#endif // ACOMMANDWITHBASEOPTION_H
