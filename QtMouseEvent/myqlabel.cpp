#include "myqlabel.h"

myQLabel::myQLabel(QWidget *parent) : QLabel(parent)
{

}

void myQLabel::mouseMoveEvent(QMouseEvent *ev)
{
    this->x = ev->x();
    this->y = ev->y();
    emit Mouse_Pos();
}

void myQLabel::mousePressEvent(QMouseEvent *ev)
{
    emit Mouse_Pressed();
}

void myQLabel::leaveEvent(QEvent *)
{
    emit Mouse_Left();
}
