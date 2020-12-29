#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(std::make_unique<Ui::MainWindow>())
    //, ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // first value is sender, that is slider
    // second value is Signal with value slider want to change
    // third value is receiver is progessBar
    // fourth value is SLOT is value set for progressBar
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), ui->progressBar, SLOT(setValue(int)));
    //Wdisconnect(ui->horizontalSlider, SIGNAL(valueChanged(int)), ui->progressBar, SLOT(setValue(int)));
}

MainWindow::~MainWindow()
{
    //delete ui;
}

