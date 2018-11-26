#include <QCoreApplication>
#include "ConsoleThread.h"

#include <QTextStream>


#include <Windows.h>


void enableEcho(bool enable)
{

    HANDLE stdinHandle = GetStdHandle(STD_INPUT_HANDLE);
    DWORD  mode;

    GetConsoleMode(stdinHandle, &mode);

    if (!enable)
    {
        mode &= ~ENABLE_ECHO_INPUT;
    }
    else
    {
        mode |= ENABLE_ECHO_INPUT;
    }

    SetConsoleMode(stdinHandle, mode);

}

ConsoleThread::ConsoleThread(BCIDataStream* stream){
    dse = stream;
}

void ConsoleThread::run()
{
    QTextStream cout(stdout);
    QTextStream cin(stdin);

    //loop getting commands
    int option;
    QString inputString;
    while(true){
        cout << endl << endl;
        cout <<"Choose an option: \n"
            << endl
            << "1 - Print values\n"
            << "2 - Record values\n"
            << "3 - classify\n"
            << "0 - exit\n"
            << endl
            << "Selection: " << flush;

        cin >> inputString ;

        bool ok;
        option = inputString.toInt(&ok);

        if(!ok) option = -1;

        switch(option){
        case 1:
            dse->printData();
            break;
        case 2:
            cout << endl << "Enter state to record: " << flush;
            cin >>inputString;
            dse->record(inputString);
            break;
        case 3:
            dse->classify();
            break;
        case 0:
            dse->doNothing();
            QCoreApplication::quit();
            return;

        default:
            cout << "ERROR - not a valid option" << endl << flush;
            break;
        }

        if(0 < option && option < 4) system(" pause");
        dse->doNothing();

    }
}

