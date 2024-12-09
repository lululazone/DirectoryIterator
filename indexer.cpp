#include "indexer.h"

Indexer::Indexer() {

    initializeActions();
}

void Indexer::initializeActions()
{
    actions[START] = [this]() { return start(); };
    actions[STOP] = [this]() { return stop(); };
    actions[STATUS] = [this]() { return stop(); };
    actions[PAUSE] = [this]() { return stop(); };
    actions[RESUME] = [this]() { return stop(); };

}

void Indexer::initializeStringMap()
{
    stringMap["START"] = START;
    stringMap["STOP"] = STOP;
    stringMap["STATUS"] = STATUS;
    stringMap["PAUSE"] = PAUSE;
    stringMap["RESUME"] = RESUME;
}

QString Indexer::start()
{
    return "start";
}

QString Indexer::stop()
{
    return "stop";
}

QString Indexer::status()
{
    return "status";
}

QString Indexer::pause()
{
    return "pause";
}

QString Indexer::resume()
{
    return "resume";
}

Outputexec Indexer::execute(QStringList input, DatabaseManager dbManager)
{
    for(int i = 0; i<stringMap.count(); i++){
        if(stringMap.contains(input[0])){
            actions[stringMap[input[0]]];
        }
    }
}

bool Indexer::command()
{

}

int Indexer::conditionIsValid(QList<QString> token)
{

}

int Indexer::handleError(int errorCode)
{

}
