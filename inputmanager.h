#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include "acommand.h"
#include <QString>
#include <qmap>
class InputManager
{
public:
    InputManager();
    DatabaseManager dbManager;
    enum Commands {GET,ADD,PUSH,CLEAR,SEARCH,INDEXER,ERROR};
    void initialiseStringMap();
    void initialiseCommandMap();
    void initialiseDatabase();
    Outputexec process(QString input);
    QMap<QString,Commands> stringMap;
    QMap<Commands,ACommand> commandMap;
    QStringList parse(QString input);
    Commands findCommand(QString input);

};

#endif // INPUTMANAGER_H
