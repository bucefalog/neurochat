#include "mainwindow.h"
#include <QApplication>

#include <QMessageBox>
#include "sharedmemory.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    if(initSharedMemory()!=0) {
        QMessageBox::critical(nullptr,"Error","Unable to create shared memory space");
        return -1;
    }


    MainWindow w;
    w.show();

    return a.exec();
}
