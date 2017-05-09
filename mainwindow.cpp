#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("PasswordGenerator");
    length = 20;
    clipboard = QApplication::clipboard();
    //this->setFixedSize(500, 400);
    ui->checkBox->setChecked(true);
    ui->checkBox_2->setChecked(true);
    ui->checkBox_3->setChecked(true);
    ui->checkBox_4->setChecked(true);
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
    gen.changeParameters(length, ui->checkBox->isChecked(), ui->checkBox_2->isChecked(),
                         ui->checkBox_3->isChecked(), ui->checkBox_4->isChecked());
    gen.genPassword(pass, length);
    ui->lineEdit_2->setText(pass.c_str());
}

void MainWindow::slot4()
{
    clipboard->setText(pass.c_str());
}
