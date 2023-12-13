#ifndef STORAGE_H
#define STORAGE_H

#include <iostream>
#include <string>
#include "Sign.h"

using namespace std;

class Store
{
private:
    Sign **array; // массив хранения данных
    int countElement;// подсчет кол-ва элементов в массиве

    int *arrayYear; // массив хранит год рождения
    int *arrayMonth; // массив хранит месяц рождения
    int *arrayDay; // массив хранит день рождения
    int *arrayFinally; // массив хранит итоговый возраст

public:
    Store(); // конструктор по умолчанию
    Store(int size); // конструктор с параметром
    Store(const Store &s); // конструктор копирования
    ~Store(); // деструктор

    void SortedArray(); // сортировка после ввода
    void FindSign(); // поиск по знаку
    void ExtractField(); // извлечь значения объекта
    void GetFiel(); // получить поля
    void Set(); // вставить значение объекта
    void Change(); // изменить значение
    void Delete(); // удалить значние
};

#endif
