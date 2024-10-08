#ifndef MANAGER_H
#define MANAGER_H
#include <QObject>
#include <QVector>
#include "file.h"
#include "consolelogger.h"

class Manager:public QObject //класс Manager, наследуемый от QObject, для реализации наблюдения за файлами
{
    Q_OBJECT //макрос для корректной реализации сигнально-слотной связи
public:
    Manager() {}
    void Monitoring(); //метод, реализующий слежение за характеристиками файлов: размер и факт существования
    void AddFiles(QString path); //метод добавления файлов в приватный вектор

private:
    QVector<File> files; //Вектор files для хранения информации о файлах
signals:
    void FileSizeHasChanged(QString path, int size); //генерируется, когда происходит изменение размера в файле
    void FileCreated(QString path, int size); //генерируется, когда происходит изменение существования файла
    void FileDeleted(QString path); //генерируется, когда происходит изменение существования файла
};

#endif // MANAGER_H
