#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("PasswordGenerator v1.0");
    length = 20;
    clipboard = QApplication::clipboard();
    //this->setFixedSize(500, 400);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slot2(QString x)
{
    length = atoi(x.toStdString().c_str());
}

void MainWindow::slot3()
{
    pass = "";
    gen.genPassword(pass, length);
    ui->lineEdit_2->setText(pass.c_str());
}

void MainWindow::slot4()
{
    clipboard->setText(pass.c_str());
}
