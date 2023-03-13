#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#define LedPin_1 15
#define LedPin_2 15

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_On_clicked();

    void on_On_2_clicked();

    void on_Off_clicked();

    void on_Off_2_clicked();

    void on_Quit_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
