#include "file.h"

File::File(const QString& filePath):path(filePath) //определение конструктора
{
    QFileInfo file(filePath);//создание объекта QFileInfo, в который передается его имя
    size = file.size(); //вызов метода size() для нахождения размера файла
    status = file.exists(); //вызов метода exists() для определения факта существования файла
}

void File::Update() //обновление данных о файле при изменении его характеристик
{
    QFileInfo file(path); //создаем объект file, которму указываем текущий путь
    status = file.exists(); //устанавливаем текущий статус для этого объекта
    size = file.size(); //устанавливаем текущий размер для этого объекта
}

bool File::isChangedStatus() //проверка на изменение существования файла
{
    QFileInfo file(path);
    if (file.exists() != status) return true;
    else return false;
}

bool File::isChangedSize() //проверка на изменение размера файла
{
    QFileInfo file(path);
    if (file.size() != size) return true;
    else return false;
}
