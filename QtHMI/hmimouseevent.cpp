#include "hmimouseevent.h"

hmiMouseEvent::hmiMouseEvent(QWidget *parent) : QLabel(parent)
{

}

void hmiMouseEvent::mouseMoveEvent(QMouseEvent *ev)
{
    this->x = ev->x();
    this->y = ev->y();
    emit Mouse_Pos();
}

void hmiMouseEvent::mousePressEvent(QMouseEvent *ev)
{
    emit Mouse_Pressed();
}

void hmiMouseEvent::leaveEvent(QEvent *)
{
    emit Mouse_Left();
}
