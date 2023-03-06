#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(MySlot()));
    timer->start(1000);

    ui->lbDigit->setPixmap(QPixmap(":/images/0.jpg"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::MySlot()
{
    switch(counter){
        case 0:
            ui->lbDigit->setPixmap(QPixmap(":/images/0.jpg"));
            counter = 1;
            break;
        case 1:
            ui->lbDigit->setPixmap(QPixmap(":/images/1.jpg"));
            counter = 2;
            break;
        case 2:
            ui->lbDigit->setPixmap(QPixmap(":/images/2.jpg"));
            counter = 3;
            break;
        case 3:
            ui->lbDigit->setPixmap(QPixmap(":/images/3.jpg"));
            counter = 4;
            break;
        case 4:
            ui->lbDigit->setPixmap(QPixmap(":/images/4.jpg"));
            counter = 5;
            break;
        case 5:
            ui->lbDigit->setPixmap(QPixmap(":/images/5.jpg"));
            counter = 6;
            break;
        case 6:
            ui->lbDigit->setPixmap(QPixmap(":/images/6.jpg"));
            counter = 7;
            break;
        case 7:
            ui->lbDigit->setPixmap(QPixmap(":/images/7.jpg"));
            counter = 8;
            break;
        case 8:
            ui->lbDigit->setPixmap(QPixmap(":/images/8.jpg"));
            counter = 9;
            break;
        case 9:
            ui->lbDigit->setPixmap(QPixmap(":/images/9.jpg"));
            counter = 0;
            break;
        default:
            ui->lbDigit->setPixmap(QPixmap(":/images/0.jpg"));
            counter = 0;
            break;
    }
}
