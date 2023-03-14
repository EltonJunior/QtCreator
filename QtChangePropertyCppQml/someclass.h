#ifndef SOMECLASS_H
#define SOMECLASS_H

#include <QObject>
#include <QtCore>

class SomeClass : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString someVar READ someVar WRITE setSomeVar NOTIFY someVarChanged)
public:
    explicit SomeClass(QObject *parent = nullptr);
 //   Q_INVOKABLE void anotherFunction();
    QString someVar();

    QTimer *timer;
    int counter = 0;

signals:
    void someVarChanged();

public slots:
    void setSomeVar( QString );
    void callMe();
    void MySlot();

private:
    QString m_someVar;

};

#endif // SOMECLASS_H
