#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->checkBox->isChecked()) {
        QMessageBox::information(this, "title", "Yess user likes apples");
    }
}

void MainWindow::on_checkBox_stateChanged(int arg1)
{
    // Moi khi checkbox duoc nhan vao
    if(ui->checkBox->isChecked()) {
        QMessageBox::information(this, "title", "Yess user likes apples");
    }
}
