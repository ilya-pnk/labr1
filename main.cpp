#include <QCoreApplication>
#include <QObject>
#include "manager.h"
#include <QTimer>

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "RUS");
    QCoreApplication a(argc, argv);
    Manager manager;
    ConsoleLogger printer;

    manager.AddFiles("C:\\lab1\\1.txt");
    manager.AddFiles("C:\\lab1\\2.txt");
    manager.AddFiles("C:\\lab1\\3.txt");

    // Подключение сигналов к слотам
    QObject::connect(&manager, &Manager::FileCreated, &printer, &ConsoleLogger::PrintFileCreated);
    QObject::connect(&manager, &Manager::FileDeleted, &printer, &ConsoleLogger::PrintFileDeleted);
    QObject::connect(&manager, &Manager::FileSizeHasChanged, &printer, &ConsoleLogger::PrintFileSizeChange);

    // Создание таймера для периодического вызова метода Monitoring()
    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, &manager, &Manager::Monitoring); //Когда timeout - истекает время таймера вызывается слот - Monitoring
    timer.start(100); // Запуск таймера с интервалом 100 миллисекунд

    return a.exec();
}
