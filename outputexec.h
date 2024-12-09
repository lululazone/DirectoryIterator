#ifndef OUTPUTEXEC_H
#define OUTPUTEXEC_H

#include <QString>
class Outputexec
{
public:
    Outputexec(QString outputText, int code);
    int code;
    QString outputText;
    QString toString();
};

#endif // OUTPUTEXEC_H
