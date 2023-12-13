#include <iostream>
#include <string.h>
#include "Sign.h"

using namespace std;

// конструктор по умолчанию
Sign::Sign()
{
    this->LnameFname = "None";
    this->sign = "None";
    this->birthday = "None";

    cout << "Вызван конструктор по умолчанию класса Sign" << endl;
}

// конструктор с параметром
Sign::Sign(string LnameFname, string sign, string birthday)
{
    this->LnameFname = LnameFname;
    this->sign = sign;
    this->birthday = birthday;

    cout << "Вызван конструктор с параметром класса Sign" << endl;
}

// конструктор копирования
Sign::Sign(const Sign &s)
{
    this->LnameFname = s.LnameFname;
    this->sign = s.sign;
    this->birthday = s.birthday;

    cout << "Вызван конструктор копирования класса Sign" << endl;
}

// деструктор
Sign::~Sign()
{
    cout << "Вызван деструктор класса Sign" << endl;
}

// метод извлечения значений
void Sign::Extract()
{
    cout << *this;
}

// метод доступа к полям
void Sign::Get()
{
    // обнуляем поток ввода
    string buf;
    getline(cin, buf);

    string choice;
    cout << "\nЧто хотите получить?\n" <<
                "1 - Фамилия Имя\n" <<
                "2 - Знак зодиака\n" <<
                "3 - День рождения\n" <<
                "4 - Все поля" << endl;
    cout << "Выбор: ";
    cin >> choice;

    // обработка исключений
    try
    {
        for (int id = 0; id < choice.size(); id ++)
        {
            if (choice[id] >= 'A' && choice[id] <= 'Z') throw "Error";
        }
    }
    catch(const char*mssg)
    {
        cout << "Неверный ввод" << endl;
    }

    if (choice == "1") cout << "\nФамилия Имя: " << this->LnameFname << endl;
    else if (choice == "2") cout << "\nЗнак зодиака: " << this->sign << endl;
    else if (choice == "3") cout << "\nДень рождения: " << this->birthday << endl;
    else if (choice == "4") cout << "\nФамилия Имя: " << this->LnameFname << " | Знак зодиака: " << this->sign << " | День рождения: " << this->birthday << endl;
    else
    {
        cout << "Ошибка выбора" << endl;
        exit(0);
    }
}

// метод доступа к дню рождения
string Sign::GetBirthday()
{
    return this->birthday;
}

// метод доступа к фамилии имя
string Sign::GetLname()
{
    return this->LnameFname;
}

// метод доступа к знаку
string Sign::GetSign()
{
    return this->sign;
}

// метод вставки значения
void Sign::Set()
{
    cin >> *this;
}

// метод изменения значений
void Sign::Change()
{
    // обнуляем поток ввода
    string buf;
    getline(cin, buf);

    string choice;
    cout << "\nЧто хотите изменить?\n" <<
            "1 - Фамилия Имя\n" <<
            "2 - Знак зодиака\n" <<
            "3 - День рождения\n" << endl;
    cout << "Выбор: ";
    cin >> choice;

    try
    {
        for (int id = 0; id < choice.size(); id ++)
        {
            if (choice[id] >= 'A' && choice[id] <= 'Z') throw "Error";
        }
    }
    catch(const char*mssg)
    {
        cout << "Неверный ввод" << endl;
    }

    if (choice == "1")
    {
        getline(cin, choice);

        cout << "Фамилия Имя: ";
        getline(cin, this->LnameFname);
    }
    else if (choice == "2")
    {
        getline(cin, choice);

        cout << "Знак зодиака: ";
        getline(cin, this->sign);
    }
    else if (choice == "3")
    {
        getline(cin, choice);

        cout << "День рождения: ";
        getline(cin, this->birthday);

        for (int i = 0; i < birthday.size(); i++)
        {
            if (birthday[i] >= 'A' && birthday[i] <= 'Z')
            {
                cout << "Неверный ввод" << endl;
                exit(0);
            }

            if (birthday[i] == ',' || birthday[i] == '/' || birthday[i] == ':' || birthday[i] == ' ' || birthday[i] == ';')
            {
                cout << "Неверный ввод" << endl;
                exit(0);
            }
        }
    }
    else
    {
        cout << "Ошибка выбора" << endl;
        exit(0);
    }
}

ostream &operator<< (ostream &stream, Sign &s) // перегрузка оператора извлеченния
{
    stream << "\nВсе поля класса:" << endl;
    stream << s.LnameFname << endl;
    stream << s.sign << endl;
    stream << s.birthday << endl;

    return stream;
}

istream &operator>> (istream &stream, Sign &s) // перегрузка оператора вставки
{
    string buf;

    cout << "Вставка значений:" << endl;
    cout << "Фамилия имя: ";
    getline(stream, buf);
    s.LnameFname = buf;

    cout << "Знак зодиака: ";
    getline(stream, buf);
    s.sign = buf;

    cout << "День рождения: ";
    getline(stream, buf);
    s.birthday = buf;

    for (int i = 0; i < buf.size(); i++)
        {
            if (buf[i] >= 'A' && buf[i] <= 'Z')
            {
                cout << "Неверный ввод" << endl;
                exit(0);
            }

            if (buf[i] == ',' || buf[i] == '/' || buf[i] == ':' || buf[i] == ' ' || buf[i] == ';')
            {
                cout << "Неверный ввод" << endl;
                exit(0);
            }
        }

    return stream;
}
