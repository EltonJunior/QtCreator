#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPropertyAnimation>


#define BACKGROUDCOLOR (QColor(27,30,37))
#define DARKBACKGROUDCOLOR (QColor(00,00,00))

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    int lbHighBeamStatus = 0;
    int lbCortainUpDownStatus = 2;

private slots:
    void Mouse_current_pos();
    void Mouse_Pressed();
    void Mouse_left();

    void on_pbCurtain_toggled(bool checked);

private:
    Ui::Widget *ui;
    QPropertyAnimation *animation;
};
#endif // WIDGET_H
