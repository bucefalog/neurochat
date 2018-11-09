/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_7;
    QLabel *label;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *imageLayout;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_6;
    QPushButton *mbutton0;
    QLabel *label0;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_4;
    QPushButton *mbutton1;
    QLabel *label1;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_5;
    QPushButton *mbutton2;
    QLabel *label2;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_5;
    QVBoxLayout *selectedLayout;
    QLabel *iSelected;
    QLabel *lSelected;
    QSpacerItem *horizontalSpacer_6;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(676, 368);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QStringLiteral("Clarendon BT"));
        font.setPointSize(22);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        imageLayout = new QHBoxLayout();
        imageLayout->setSpacing(6);
        imageLayout->setObjectName(QStringLiteral("imageLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        imageLayout->addItem(horizontalSpacer_3);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        mbutton0 = new QPushButton(centralWidget);
        mbutton0->setObjectName(QStringLiteral("mbutton0"));
        mbutton0->setMinimumSize(QSize(150, 150));
        mbutton0->setMaximumSize(QSize(150, 150));
        QIcon icon;
        icon.addFile(QStringLiteral("C:/resources/filters/filter_0.png"), QSize(), QIcon::Normal, QIcon::Off);
        mbutton0->setIcon(icon);
        mbutton0->setIconSize(QSize(150, 150));

        verticalLayout_6->addWidget(mbutton0);

        label0 = new QLabel(centralWidget);
        label0->setObjectName(QStringLiteral("label0"));
        label0->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label0);


        imageLayout->addLayout(verticalLayout_6);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        imageLayout->addItem(horizontalSpacer);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        mbutton1 = new QPushButton(centralWidget);
        mbutton1->setObjectName(QStringLiteral("mbutton1"));
        mbutton1->setMinimumSize(QSize(150, 150));
        mbutton1->setMaximumSize(QSize(150, 150));
        QIcon icon1;
        icon1.addFile(QStringLiteral("C:/resources/filters/filter_1.png"), QSize(), QIcon::Normal, QIcon::Off);
        mbutton1->setIcon(icon1);
        mbutton1->setIconSize(QSize(150, 150));

        verticalLayout_4->addWidget(mbutton1);

        label1 = new QLabel(centralWidget);
        label1->setObjectName(QStringLiteral("label1"));
        label1->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label1);


        imageLayout->addLayout(verticalLayout_4);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        imageLayout->addItem(horizontalSpacer_2);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        mbutton2 = new QPushButton(centralWidget);
        mbutton2->setObjectName(QStringLiteral("mbutton2"));
        mbutton2->setMinimumSize(QSize(150, 150));
        mbutton2->setMaximumSize(QSize(150, 150));
        QIcon icon2;
        icon2.addFile(QStringLiteral("C:/resources/filters/filter_2.png"), QSize(), QIcon::Normal, QIcon::Off);
        mbutton2->setIcon(icon2);
        mbutton2->setIconSize(QSize(150, 150));

        verticalLayout_5->addWidget(mbutton2);

        label2 = new QLabel(centralWidget);
        label2->setObjectName(QStringLiteral("label2"));
        label2->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label2);


        imageLayout->addLayout(verticalLayout_5);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        imageLayout->addItem(horizontalSpacer_4);


        verticalLayout_3->addLayout(imageLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        selectedLayout = new QVBoxLayout();
        selectedLayout->setSpacing(6);
        selectedLayout->setObjectName(QStringLiteral("selectedLayout"));
        iSelected = new QLabel(centralWidget);
        iSelected->setObjectName(QStringLiteral("iSelected"));
        iSelected->setMinimumSize(QSize(50, 50));
        iSelected->setMaximumSize(QSize(50, 50));

        selectedLayout->addWidget(iSelected);

        lSelected = new QLabel(centralWidget);
        lSelected->setObjectName(QStringLiteral("lSelected"));
        lSelected->setAlignment(Qt::AlignCenter);

        selectedLayout->addWidget(lSelected);


        horizontalLayout_2->addLayout(selectedLayout);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);


        verticalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout_7->addLayout(verticalLayout_3);


        verticalLayout->addLayout(verticalLayout_7);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 676, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("MainWindow", "Click image to select the filter", nullptr));
        mbutton0->setText(QString());
        label0->setText(QApplication::translate("MainWindow", "Relaxed", nullptr));
        mbutton1->setText(QString());
        label1->setText(QApplication::translate("MainWindow", "Focused", nullptr));
        mbutton2->setText(QString());
        label2->setText(QApplication::translate("MainWindow", "Wondering", nullptr));
        iSelected->setText(QString());
        lSelected->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
