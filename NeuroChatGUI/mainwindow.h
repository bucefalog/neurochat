#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_mbutton0_clicked();

    void on_mbutton1_clicked();

    void on_mbutton2_clicked();

    void setSelection(int filterId);


private:
    Ui::MainWindow *ui;

    QPixmap filterImages[3];
    QString filterNames[3];

};

#endif // MAINWINDOW_H
