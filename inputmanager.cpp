#include "inputmanager.h"
#include "add.h"
#include "clear.h"
#include "get.h"
#include "indexer.h"
#include "push.h"
#include "qdebug.h"
#include "qobject.h"
#include "search.h"

InputManager::InputManager() {

    initialiseStringMap();
    initialiseCommandMap();


}

void InputManager::initialiseStringMap()
{
    stringMap[QString("CLEAR")] = CLEAR;
    stringMap[QString("SEARCH")] = SEARCH;
    stringMap[QString("ADD")] = ADD;
    stringMap[QString("GET")] = GET;
    stringMap[QString("PUSH")] = PUSH;
    stringMap[QString("INDEXER")] = INDEXER;
}

void InputManager::initialiseCommandMap()
{
    commandMap[GET] = *new Get();
    commandMap[INDEXER] = *new Indexer();
    commandMap[ADD] = *new Add();
    commandMap[PUSH] = *new Push();
    commandMap[SEARCH] = *new Search();
    commandMap[CLEAR] = *new Clear();
}

void InputManager::initialiseDatabase()
{
    dbManager = *new DatabaseManager();
}


Outputexec InputManager::process(QString input){

    if(input.isEmpty())
        return *new Outputexec("Input is empty",-2);
    QStringList splittedList = parse(input);
    qDebug() << splittedList;
    for(int i =0; i<splittedList.count(); i++){
        qDebug() << "Testing with" + splittedList[i];
        Commands cmd = findCommand(splittedList[i]);
        qDebug() << cmd;
        if(cmd != ERROR){
            //splittedList.removeAt(i);
            return commandMap[cmd].execute(splittedList,dbManager);
        }
        else{
            return *new Outputexec("No commands found",-4);
        }

    }
    return *new Outputexec("No commands found",-3);

}


QStringList InputManager::parse(QString input){
    return input.split(" ");
}


InputManager::Commands InputManager::findCommand(QString input){
    QString upperCase = input.toUpper();
    if(stringMap.contains(input)){
        return stringMap.value(input);
    }
    else{
        return ERROR;
    }
}


