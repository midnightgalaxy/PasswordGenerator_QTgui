#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>

#include "passwordgen.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void slot1() { QApplication::aboutQt(); }   // self explanatory
    void slot2(QString);                        // setting length
    void slot3();                               // show generated password

private:
    Ui::MainWindow *ui;
    Passwordgen gen;
    std::string pass;
    int length;
};

#endif // MAINWINDOW_H
