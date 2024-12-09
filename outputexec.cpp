#include "outputexec.h"

Outputexec::Outputexec(QString text, int cde) {
    outputText = text;
    code = cde;
}

QString Outputexec::toString()
{
    return outputText.append( ": ("+std::to_string(code)+")");
}
