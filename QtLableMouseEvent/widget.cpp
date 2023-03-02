#include "widget.h"
#include "ui_widget.h"

#include "myqlabel.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->lbMouse, SIGNAL(Mouse_Pos()), this, SLOT(Mouse_current_pos()));
    connect(ui->lbMouse, SIGNAL(Mouse_Pressed()), this, SLOT(Mouse_Pressed()));
    connect(ui->lbMouse, SIGNAL(Mouse_Left()), this, SLOT(Mouse_left()));


    connect(ui->lbBtnOnOff, SIGNAL(Mouse_Pos()), this, SLOT(Mouse_current_pos()));
    connect(ui->lbBtnOnOff, SIGNAL(Mouse_Pressed()), this, SLOT(Mouse_Pressed()));
    connect(ui->lbBtnOnOff, SIGNAL(Mouse_Left()), this, SLOT(Mouse_left()));


    ui->lbBtnOnOff->setPixmap(QPixmap(":/images/btn_Off.png"));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::Mouse_current_pos()
{
    ui->lbMouse_Current_Pos->setText(QString("X = %1, Y = %2").arg(ui->lbMouse->x).arg(ui->lbMouse->y));
    ui->lbMouse_Current_Event->setText("Mouse Moving");

    ui->label->setText( QString(" X = %1 ").arg(ui->lbBtnOnOff->x) );
}

void Widget::Mouse_Pressed()
{
    ui->lbMouse_Current_Event->setText("Mouse Pressed");

    if( (ui->lbBtnOnOff->x != 0) && (lbBtnOnOffStatus == 1) )
    {
        lbBtnOnOffStatus = 0;
        ui->lbBtnOnOff->setPixmap(QPixmap(":/images/btn_Off.png"));
    }
    else if( (ui->lbBtnOnOff->x != 0) &&  (lbBtnOnOffStatus == 0)  )
    {
        lbBtnOnOffStatus = 1;
        ui->lbBtnOnOff->setPixmap(QPixmap(":/images/btn_On.png"));
    }



}

void Widget::Mouse_left()
{
    ui->lbMouse_Current_Event->setText("Mouse Left");
    ui->lbBtnOnOff->x = 0;
}


