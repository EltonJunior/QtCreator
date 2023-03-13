#include "mainwindow.h"
#include "ui_mainwindow.h"

int value = 0;
int btnStatus = 0;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    FILE *sysfs_handle = NULL;

    if( (sysfs_handle = fopen("sys/class/gpio14/value","w")) != NULL )
    {
        value = value ? 0 : 1;

        char str_value[2];

        snprintf(str_value,(2*sizeof(char)),"%d",value);

        fwrite(str_value,sizeof(char),2,sysfs_handle);
        fclose(sysfs_handle);
    }

    if(value)
    {
        ui->pushButton->setIcon(QPixmap(":/images/led-off.png"));
        btnStatus = 1;
    }
    else
    {
        ui->pushButton->setIcon(QPixmap(":/images/led-on.png"));
        btnStatus = 0;
    }
}

