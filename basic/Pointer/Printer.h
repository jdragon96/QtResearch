#ifndef PRINTER_H
#define PRINTER_H

#include <QString>
#include <QDebug>

#include <functional>

class Printer
{
public:
    Printer(QString prev, QString post, std::function<void()> func)
    {
        qInfo() << prev;
        func();
        qInfo() << post;
    }
};

#endif // PRINTER_H
