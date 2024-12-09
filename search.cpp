#include "search.h"

Search::Search() {
    dialectMap["options"] = {"LAST_MODIFIED","CREATED","MAX_SIZE","MIN_SIZE","SIZE","EXT"};
}

Outputexec Search::execute(QStringList input, DatabaseManager dbManager)
{

}

bool Search::command()
{

}

int Search::conditionIsValid(QList<QString> token)
{

}

int Search::handleError(int errorCode)
{

}
