#ifndef MYQLABEL_H
#define MYQLABEL_H

#include <QWidget>
#include <QLabel>
#include <QMouseEvent>
#include <QDebug>

class myQLabel : public QLabel
{
    Q_OBJECT
public:
    explicit myQLabel(QWidget *parent = nullptr);

    void mouseMoveEvent(QMouseEvent *ev);
    void mousePressEvent(QMouseEvent *ev);
    void leaveEvent(QEvent *);

    int x,y;

signals:
    void Mouse_Pressed();
    void Mouse_Pos();
    void Mouse_Left();

public slots:

};

#endif // MYQLABEL_H
