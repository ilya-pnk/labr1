#ifndef CONSOLELOGGER_H
#define CONSOLELOGGER_H
#include <QString>
#include <QObject>
#include "file.h"

class ConsoleLogger:public QObject //класс ConsoleLogger для вывода изменений в файле в консоль
{
    Q_OBJECT
public:
    ConsoleLogger() {}
public slots:
    void PrintFileCreated(QString path, int size); //метод для печати изменения статуса файла
    void PrintFileDeleted(QString path); //метод для печати изменения статуса файла
    void PrintFileSizeChange(QString path, int size); //метод для печати изменения размера файла
};

#endif // CONSOLELOGGER_H
