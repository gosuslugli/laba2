#ifndef SIGN_H
#define SIGN_H

#include <iostream>
#include <string.h>
using namespace std;

class Sign
{
private:
    string LnameFname; // фамилия имя
    string sign; // знак зодиака
    string birthday; // день рожденияs

public:
    Sign(); // конструктор по умолчанию
    Sign(string FnameLname, string sign, string birthday); // конструктор с параметром
    Sign(const Sign &s); // конструктор копирования
    ~Sign(); // деструктор

    void Extract(); // метод извлечения значения
    void Get(); // метод доступа к полям
    string GetBirthday(); // метод доступа дня рождения
    string GetLname(); // метод доступа фамилии имя
    string GetSign(); // метод доступа к знаку
    void Set(); // метод установки значения
    void Change(); // метод редактирования значений

    friend ostream &operator<< (ostream &stream, Sign &s); // перегрузка оператора извлеченния
    friend istream &operator>> (istream &stream, Sign &s); // перегрузка оператора вставки
};

#endif
