#include <iostream>
#include <string>
#include <algorithm>
#include "Storage.h"
#include "Sign.h"

using namespace std;

// конструктор по умолчанию
Store::Store()
{
    this->array = new Sign*[1]; // выделяем память под 1 элемент
    this->countElement = 0; // кол-во элементов = 0

    this->arrayYear = new int[1];
    this->arrayMonth = new int[1];
    this->arrayDay = new int[1];
    this->arrayFinally = new int[1];

    wcout << "Вызван конструктор по умолчанию класса Store" << endl;
}

// конструктор с параметром
Store::Store(int size)
{
    this->array = new Sign*[size]; // выделяем память под size элементов
    this->countElement = 0; // кол-во элементов = 0

    this->arrayYear = new int[1];
    this->arrayMonth = new int[1];
    this->arrayDay = new int[1];
    this->arrayFinally = new int[1];

    wcout << "Вызван конструктор c параметром класса Store" << endl;
}

// конструктор копирования
Store::Store(const Store &s)
{
    this->countElement = s.countElement; // копируем кол-во элементов
    this->array = new Sign*[this->countElement]; // создаем массив на кол-во элементов

    this->arrayYear = new int[1];
    this->arrayMonth = new int[1];
    this->arrayDay = new int[1];
    this->arrayFinally = new int[1];

    for (int id = 0; id < this->countElement; id++) this->array[id] = s.array[id]; // копируем элементы

    wcout << "Вызван конструктор копирования класса Store" << endl;
}

// деструктор
Store::~Store()
{
    delete array; // высвобождаем память
    delete arrayYear;
    delete arrayMonth;
    delete arrayDay;
    delete arrayFinally;

    wcout << L"Вызван деструктор класса Store" << endl;
}

// сортировка массива
void Store::SortedArray()
{
    int year = 2023; // текущий год
    int month = 12; // месяц
    int day = 31; // день

    // перебираем все элементы
    for (int id1 = 0; id1 < countElement; id1++)
    {
        string buf = array[id1]->GetBirthday(); // получаем текущий день рождения
        string data = ""; // буферная строка, будет хранить день рождения
        int flag = 0; // флаг для сбора дня, месяца, года

        // проходимся по строке дня рождения
        for (int i = 0; i < buf.size()+1; i++)
        {
            // если не разделитель, то собираем дату
            if (buf[i] != '.' && buf[i] != '\n' && buf[i] != '\0') data += buf[i];
            // иначе
            else
            {
                // если флаг = 0, добавляем день
                if (flag == 0) arrayDay[id1] = stoi(data);
                // если флаг = 1, добавляем месяц
                else if (flag == 1) arrayMonth[id1] = stoi(data);
                // если флаг = 2, добавляем год
                else if (flag == 2) arrayYear[id1] = stoi(data);

                data = ""; // обнуляем дату
                flag++; // увеличивае флаг
            }
        }
    }

    // формируем текущий возраст
    for (int i = 0; i < countElement; i++)
    {
        arrayFinally[i] = (year - arrayYear[i]) * 365 + (month - arrayMonth[i]) * 30 + (day - arrayDay[i]);
    }

    // метод сортировки пузырьком
    for (int id1 = 0; id1 < countElement; id1++) // кол-во итераций = кол-ву элементов
    {
        for (int id2 = 0; id2 < countElement - 1; id2++) // перебираем элементы не доходя до последнего
        {
            if (arrayFinally[id2] > arrayFinally[id2+1])  // если текущий больше последуещего, то меняем их местами
            {
                int buf_i = arrayFinally[id2];
                arrayFinally[id2] = arrayFinally[id2+1];
                arrayFinally[id2+1] = buf_i;

                Sign *buf = array[id2];
                array[id2] = array[id2+1];
                array[id2+1] = buf;
            }
        }
    }
}

// поиск по фамилии
void Store::FindSign()
{
    // очищаем буфер ввода
    string buf;
    getline(cin, buf);

    string findSign; // переменная хранин введеный знак
    wcout << L"\nЧтобы узнать информацию о людях, введите знак: ";
    cin >> findSign;

    int flagFind = 0; // флаг на найденность таких маршрутов

    wcout << L"\n~Информация о людях~" << endl;

    for (int id = 0; id < countElement; id++) // перебираем все элементы
    {
        // если мы нашли такой знак
        if (array[id]->GetSign() == findSign)
        {
            flagFind = 1; // меняев флаг
            cout << array[id]->GetLname() << endl; // выводим человека
        }
    }

    if (!flagFind) wcout << L"\nЛюдей с такой фамилией нет!" << endl; // если не нашли
}

// извлечение значения
void Store::ExtractField()
{
    for (int id = 0; id < countElement; id++) array[id]->Extract(); // извлекаем значения из всех элементов
}

// получение полей
void Store::GetFiel()
{
    // очищаем буфер ввода
    string buf;
    getline(cin, buf);
    string choice;

    wcout << L"\nВведите номер элемента, поля которого вы хотите вывести: ";
    cin >> choice;

    // проверка на правильность ввода (работа с исключительной ситуацией)
    try
    {
        // если есть буква, кидаем ошибку
        for (int id = 0; id < choice.size(); id++) if (isalpha(choice[id])) throw "Error";

        if (!all_of(choice.begin(), choice.end(), ::isdigit)) throw "Error";
    }
    catch(const char*mssg)
    {
        wcout << "Неверный ввод!" << endl;
    }

    // если выбор элемента превышает значения кол-ва элементов или меньше 0, то ошибка
    if (choice > to_string(countElement) or choice < "0")
    {
        wcout << "Ошибка ввода" << endl;
        exit(0);
    }

    else
    {
        int idChoice = stoi(choice);
        array[idChoice]->Get();
    }
}

// метод установки значения
void Store::Set()
{
    // очищаем буфер ввода
    string buf;
    getline(cin, buf);

    Sign *sign = new Sign();
    sign->Set();
    array[countElement++] = sign;

    this->SortedArray();
}

// метод изменения значения
void Store::Change()
{
    setlocale(LC_CTYPE, "Russian");
    // очищаем буфер ввода
    string buf;
    getline(cin, buf);

    wcout << L"\nВыберете номер элемента, данные которого хотите изменить: ";
    string choice;
     cin >> choice;

    try
    {
        // если есть буква
        for (int id = 0; id < choice.size(); id++) if (isalpha(choice[id])) throw "Error";
        if (choice > to_string(countElement) or choice < "0") throw "Error";
    }
    catch(const char*mssg)
    {
        wcout << "Ошибка ввода!" << endl;
        exit(0);
    }

    array[stoi(choice)]->Change();
}

// метод удаления
void Store::Delete()
{
    // очищаем буфер ввода
    string buf;
    getline(cin, buf);

    wcout << L"Выберете номер элемента, данные которого хотите удалить: ";
    string choice;
    cin >> choice;

    try
    {
        for (int id = 0; id < choice.size(); id++) if (isalpha(choice[id])) throw "Error";
        if (choice > to_string(countElement) or choice < "0") throw "Error";
    }
    catch(const char*mssg)
    {
        wcout << L"Ошибка ввода!" << endl;
        exit(0);
    }

    // удаление значений
    for (int id = stoi(choice); id < countElement - 1; id++) array[id] = array[id+1];
    countElement--;
}
