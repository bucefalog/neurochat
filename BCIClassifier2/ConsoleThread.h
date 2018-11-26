#ifndef CONSOLETHREAD_H
#define CONSOLETHREAD_H

#include <QObject>
#include <QThread>
#include "BCIDataStream.h"


void enableEcho(bool enable);

class ConsoleThread : public QThread
{
    Q_OBJECT

public:
    ConsoleThread(BCIDataStream * stream);

    void run() override;

    BCIDataStream* dse;

};

#endif // CONSOLETHREAD_H
