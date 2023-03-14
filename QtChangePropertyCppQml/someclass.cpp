#include "someclass.h"
#include <QDebug>

SomeClass::SomeClass(QObject *parent) : QObject(parent), m_someVar("000000")
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(MySlot()));
    timer->start(1000);

}

QString SomeClass::someVar()
{
    return m_someVar;
}

void SomeClass::setSomeVar(QString newVar)
{
    if( m_someVar != newVar )
    {
        m_someVar = newVar;
        emit someVarChanged();
    }
}

void SomeClass::callMe()
{
    qDebug() << "I'm being called";
}

void SomeClass::MySlot()
{
    qDebug() << "I'm being called from MySolt Timer" << counter;

    switch(counter){
        case 0:
            setSomeVar("0");
            counter = 1;
            break;
        case 1:
        setSomeVar("1");

            counter = 2;
            break;
        case 2:
        setSomeVar("2");

            counter = 3;
            break;
        case 3:
        setSomeVar("3");

            counter = 4;
            break;
        case 4:
        setSomeVar("4");

            counter = 5;
            break;
        case 5:
        setSomeVar("5");

            counter = 6;
            break;
        case 6:
        setSomeVar("6");

            counter = 7;
            break;
        case 7:
        setSomeVar("7");

            counter = 8;
            break;
        case 8:
        setSomeVar("8");

            counter = 9;
            break;
        case 9:
        setSomeVar("9");

            counter = 0;
            break;
        default:

            counter = 0;
            break;
    }
}
