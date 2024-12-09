#include "get.h"
#include "databasemanager.h"
#include "qdebug.h"

Get::Get() {}


Outputexec Get::execute(QStringList input, DatabaseManager dbManager)
{
    qDebug() << "Executing GET command";
    QStringList tableList = dbManager.getTable(commandMap[FindOption(input)]);
    if(tableList.isEmpty()){
        qDebug() << "No data found with this query";
        return *new Outputexec("No data found with this query",-1);
    }
    else{
        QString result="";
        foreach (QString item, tableList) {
            result += item + "\n";
        }
        qDebug() << result;
        return *new Outputexec(result,0);

    }
}

bool Get::command()
{

}

int Get::conditionIsValid(QList<QString> token)
{

}

int Get::handleError(int errorCode)
{

}

bool Get::command(Options cmdOption)
{

}


