#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sharedmemory.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString file = "C:/resources/filters/filter_";
    QString extension = ".png";
    for(int i=0;i<3;i++){
        filterImages[i] = QPixmap(file+QString::number( i )+ extension);
    }

    filterNames[0] = "Relaxed";
    filterNames[1] = "Focused";
    filterNames[2] = "Wondering";


//    ui->lImage0->setPixmap(pix0.scaled(150,150,Qt::KeepAspectRatio));
//    ui->lImage1->setPixmap(pix1.scaled(150,150,Qt::KeepAspectRatio));
//    ui->lImage2->setPixmap(pix2.scaled(150,150,Qt::KeepAspectRatio));


//    ui->

}

MainWindow::~MainWindow()
{
    closeSharedMemory();
    delete ui;
}



void MainWindow::on_mbutton0_clicked()
{
    setSelection(0);
}

void MainWindow::on_mbutton1_clicked()
{
    setSelection(1);
}


void MainWindow::on_mbutton2_clicked()
{
    setSelection(2);
}

void MainWindow::setSelection(int filterId){



    ui->iSelected->setPixmap(filterImages[filterId].scaled(50,50,Qt::KeepAspectRatio));
    ui->lSelected->setText(filterNames[filterId]);
    smWriteId(filterId);

}


