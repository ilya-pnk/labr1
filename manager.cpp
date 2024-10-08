#include "manager.h"

void Manager::Monitoring() //метод, реализующий слежение за характеристиками файлов: размер и факт существования
{
    for (int i = 0; i < files.size(); i++)
    {
        File &file = files[i]; //создаем ссылку на объект File для доступа к элементам вектора files
        if (file.isChangedStatus()) //если в файле был изменен статус, то
        {
            file.Update(); //обновляем информацию о файле
            if (file.status) //если файл существует, то
            {
                emit FileCreated(file.path, file.size); //генерация сигнала
            }
            else { //иначе если файл не существует, то
                emit FileDeleted(file.path); //генерация сигнала
            }
        }

        else if (file.isChangedSize()) //если в файле был изменен размер, то
        {
            file.Update(); //обновляем информацию о файле
            emit FileSizeHasChanged(file.path, file.size); //генерация сигнала
        }
    }
}

void Manager::AddFiles(QString path) //метод добавления файлов для слежения за ними в основной программе
{
    File file(path); //создаем объект file, которому передаем путь текущего файла
    files.push_back(file); //добавляем его в вектор files с помощью метода push_back()
}
