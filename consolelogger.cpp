#include "consolelogger.h"
#include <QString>
#include <QDebug>

void ConsoleLogger::PrintFileCreated(QString path, int size) //метод для печати изменения статуса файла
{
    qDebug()<<"Файл: "<< path <<" существует, его размер: "<< size <<"\n";
}

void ConsoleLogger::PrintFileDeleted(QString path) //метод для печати изменения статуса файла
{
    qDebug()<<"Файл: "<< path <<" не существует.\n";
}

void ConsoleLogger::PrintFileSizeChange(QString path, int size) //метод для печати изменения размера файла
{
    qDebug()<<"Файл: "<< path <<" был изменен, его новый размер: "<< size <<"\n";
}
