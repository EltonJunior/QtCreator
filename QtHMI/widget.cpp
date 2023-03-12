#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

//    ui->frameCurtainMenu->setGeometry(QRect(0,0,800,0));
//    ui->lbCortainUpDown->setGeometry(QRect(330,0,140,40));

    QPalette pal=this->palette(); //"this" is my derived button class
    pal.setColor(QPalette::Window, BACKGROUDCOLOR); //#1A1E25
    this->setAutoFillBackground(true);
    this->setPalette(pal);

    connect(ui->lbHighBeam, SIGNAL(Mouse_Pos()), this, SLOT(Mouse_current_pos()));
    connect(ui->lbHighBeam, SIGNAL(Mouse_Pressed()), this, SLOT(Mouse_Pressed()));
    connect(ui->lbHighBeam, SIGNAL(Mouse_Left()), this, SLOT(Mouse_left()));

    connect(ui->lbCortainUpDown, SIGNAL(Mouse_Pos()), this, SLOT(Mouse_current_pos()));
    connect(ui->lbCortainUpDown, SIGNAL(Mouse_Pressed()), this, SLOT(Mouse_Pressed()));
    connect(ui->lbCortainUpDown, SIGNAL(Mouse_Left()), this, SLOT(Mouse_left()));

    ui->lbtripValue->setStyleSheet("QLabel { color : white; }");
    ui->lbtripUnit->setStyleSheet("QLabel { color : gray; }");
    ui->lbCaloriesValue->setStyleSheet("QLabel { color : white; }");
    ui->lbCaloriesUnit->setStyleSheet("QLabel { color : gray; }");

//    ui->frameKCAL->setGeometry(QRect(40,110,140,60));
//    ui->frameMI->setGeometry(QRect(40,30,140,60));

        ui->label_3->setStyleSheet("QLabel { color : white; }");
            ui->label_2->setStyleSheet("QLabel { color : white; }");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::Mouse_current_pos()
{
    //ui->lbMouse_Current_Pos->setText(QString("X = %1, Y = %2").arg(ui->lbMouse->x).arg(ui->lbMouse->y));
    ui->label_3->setText("Mouse Moving");

    ui->label_2->setText( QString(" X = %1, Y = %2 ").arg(ui->lbHighBeam->x).arg(ui->lbCortainUpDown->x) );
}

void Widget::Mouse_Pressed()
{
    ui->label_3->setText("Mouse Pressed");

        if( (ui->lbHighBeam->x != 0) && (lbHighBeamStatus == 1) )
        {
            lbHighBeamStatus = 0;
            ui->lbHighBeam->setPixmap(QPixmap(":/images/lights_off.png"));
        }
        else if( (ui->lbHighBeam->x != 0) &&  (lbHighBeamStatus == 0)  )
        {
            lbHighBeamStatus = 1;
            ui->lbHighBeam->setPixmap(QPixmap(":/images/lights_on.png"));
        }

        if( (ui->lbCortainUpDown->x != 0) && (lbCortainUpDownStatus == 2) )
        {
            lbCortainUpDownStatus = 3;
            ui->lbCortainUpDown->setPixmap(QPixmap(":/images/top_curtain_drag_back.png"));
            on_pbCurtain_toggled(1);
        }
        else if( (ui->lbCortainUpDown->x != 0) &&  (lbCortainUpDownStatus == 3)  )
        {
            lbCortainUpDownStatus = 2;
            ui->lbCortainUpDown->setPixmap(QPixmap(":/images/top_curtain_drag.png"));
            on_pbCurtain_toggled(0);
        }






}

void Widget::Mouse_left()
{
    ui->label_3->setText("Mouse Left");
    ui->lbHighBeam->x = 0;
    ui->lbCortainUpDown->x = 0;
}


//void Widget::on_pbHighBeam_toggled(bool checked)
//{
//    if(checked)
//    {
//        ui->pbHighBeam->setIcon(QIcon("/home/eltonjunior/Projects/QT_Projects/teste/images/lights_on.png"));
//    }else{
//        ui->pbHighBeam->setIcon(QIcon("/home/eltonjunior/Projects/QT_Projects/teste/images/lights_off.png"));
//    }
//}

void Widget::on_pbCurtain_toggled(bool checked)
{
    if(checked)
    {
        animation = new QPropertyAnimation(ui->frameCurtainMenu, "geometry");
        animation->setDuration(200);
        animation->setStartValue(ui->frameCurtainMenu->geometry());
        animation->setEndValue(QRect(0,0,800,220));
        animation->setLoopCount(1);
        animation->start();
        ui->frameCurtainMenu->setGeometry(QRect(0,0,800,220));

        animation = new QPropertyAnimation(ui->lbCortainUpDown, "geometry");
        animation->setDuration(200);
        animation->setStartValue(ui->lbCortainUpDown->geometry());
        animation->setEndValue(QRect(330,220,150,41));
        animation->setLoopCount(1);
        animation->start();
        ui->lbCortainUpDown->setGeometry(QRect(330,220,140,40));

        animation = new QPropertyAnimation(ui->frameKCAL, "geometry");
        animation->setDuration(200);
        animation->setStartValue(ui->frameKCAL->geometry());
        animation->setEndValue(QRect(180,230,140,60));
        animation->setLoopCount(1);
        animation->start();
        ui->frameKCAL->setGeometry(QRect(180,230,140,60));

        animation = new QPropertyAnimation(ui->frameMI, "geometry");
        animation->setDuration(200);
        animation->setStartValue(ui->frameMI->geometry());
        animation->setEndValue(QRect(20,230,140,60));
        animation->setLoopCount(1);
        animation->start();
        ui->frameMI->setGeometry(QRect(20,230,140,60));

    }else{

        animation = new QPropertyAnimation(ui->frameCurtainMenu, "geometry");
        animation->setDuration(200);
        animation->setStartValue(ui->frameCurtainMenu->geometry());
        animation->setEndValue(QRect(0,0,800,0));
        animation->setLoopCount(1);
        animation->start();
        ui->frameCurtainMenu->setGeometry(QRect(0,0,800,0));

        animation = new QPropertyAnimation(ui->lbCortainUpDown, "geometry");
        animation->setDuration(200);
        animation->setStartValue(ui->lbCortainUpDown->geometry());
        animation->setEndValue(QRect(330,0,150,41));
        animation->setLoopCount(1);
        animation->start();
        ui->lbCortainUpDown->setGeometry(QRect(330,0,140,40));

        animation = new QPropertyAnimation(ui->frameKCAL, "geometry");
        animation->setDuration(200);
        animation->setStartValue(ui->frameKCAL->geometry());
        animation->setEndValue(QRect(40,110,140,60));
        animation->setLoopCount(1);
        animation->start();
        ui->frameKCAL->setGeometry(QRect(40,110,140,60));

        animation = new QPropertyAnimation(ui->frameMI, "geometry");
        animation->setDuration(200);
        animation->setStartValue(ui->frameMI->geometry());
        animation->setEndValue(QRect(40,30,140,60));
        animation->setLoopCount(1);
        animation->start();
        ui->frameMI->setGeometry(QRect(40,30,140,60));

    }
}

//void Widget::setUP_Curtain(void)
//{
//    ui->frameCurtainMenu->setStyleSheet("background-color: rgb(0, 0, 0);");

//    ui->frameslide->setStyleSheet("background-color: rgb(255, 255, 255);");

//    ui->pbCurtain->setIcon(QIcon("/home/eltonjunior/Projects/QT_Projects/teste/images/top_curtain_drag.png"));
//    QPalette pbCurtainPalette = ui->pbCurtain->palette();
//    pbCurtainPalette.setColor(QPalette::Button, BACKGROUDCOLOR);
//    ui->pbCurtain->setPalette(pbCurtainPalette);
//    ui->pbCurtain->setAutoFillBackground(true);
//    ui->pbCurtain->repaint();

//    ui->pbInfo->setIcon(QIcon("/home/eltonjunior/Projects/QT_Projects/teste/images/info.png"));
//    QPalette pbInfoPalette = ui->pbInfo->palette();
//    pbInfoPalette.setColor(QPalette::Button, DARKBACKGROUDCOLOR);
//    ui->pbInfo->setPalette(pbInfoPalette);
//    ui->pbInfo->setAutoFillBackground(true);
//    ui->pbInfo->repaint();

//    ui->pbList->setIcon(QIcon("/home/eltonjunior/Projects/QT_Projects/teste/images/list.png"));
//    QPalette pbListPalette = ui->pbList->palette();
//    pbListPalette.setColor(QPalette::Button, DARKBACKGROUDCOLOR);
//    ui->pbList->setPalette(pbListPalette);
//    ui->pbList->setAutoFillBackground(true);
//    ui->pbList->repaint();

//    ui->pbSetting->setIcon(QIcon("/home/eltonjunior/Projects/QT_Projects/teste/images/settings.png"));
//    QPalette pbSettingPalette = ui->pbSetting->palette();
//    pbSettingPalette.setColor(QPalette::Button, DARKBACKGROUDCOLOR);
//    ui->pbSetting->setPalette(pbSettingPalette);
//    ui->pbSetting->setAutoFillBackground(true);
//    ui->pbSetting->repaint();

//}

//void Widget::LbImagesInit(void){

//    ui->lbBikeWheel->setPixmap(QPixmap("/home/eltonjunior/Projects/QT_Projects/teste/images/bike-rearwheel.png"));
//    ui->lbtrip->setPixmap(QPixmap("/home/eltonjunior/Projects/QT_Projects/teste/images/trip.png"));
//    ui->lbCalories->setPixmap(QPixmap("/home/eltonjunior/Projects/QT_Projects/teste/images/calories.png"));

//}
