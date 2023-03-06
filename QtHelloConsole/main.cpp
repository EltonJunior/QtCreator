#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    /* One way of print at console is to put the string inside the command qDebug */
    qDebug() << "Hello World from QT by Elton \n";

    /* other way to do that is to create a variable using QString */

    QString myQtString = "Hello World from QT by Elton using string";

    qDebug() << myQtString.toLatin1();

    /* The qDebud has the same behavior of printf */

    return a.exec();
}
