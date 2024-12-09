#include "acommandwithbaseoption.h"

ACommandWithBaseOption::ACommandWithBaseOption() {
    initialiseStringMap();
}

void ACommandWithBaseOption::initialiseStringMap()
{
    commandMap[BLACKLIST] = "BLACKLIST";
    commandMap[FILTERS] = "FILTERS";
    commandMap[SKIPPED_FILTERS] = "SKIPPED_FILTERS";
    commandMap[WHITELIST] = "WHITELIST";
    commandMap[ERROR] = "";
}

ACommandWithBaseOption::Options ACommandWithBaseOption::FindOption(QStringList input)
{
    for(int i = 0; i<input.count(); i++){
        if(commandMap.key(input[i]) != NULL){
            return commandMap.key(input[i]);
        }
    }
    return ERROR;
}
