#include <QCoreApplication>
#include "BCIDataStream.h"
#include <QtDebug>


#include <QTextStream>

#include "ConsoleThread.h"











int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTextStream cout(stdout);
    QTextStream cin(stdin);

    QString user;
    QString pass;

    cout << "USER: " << flush;
    cin >> user;

    enableEcho(false);
    cout << "PASS: " <<endl;
    cin >> pass;
    enableEcho(true);



//    system("pause");

    BCIDataStream dse(user,pass);
    dse.start();





    return a.exec();
}
