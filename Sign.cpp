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

    wcout << "Вызван конструктор по умолчанию класса Sign" << endl;
}

// конструктор с параметром
Sign::Sign(string LnameFname, string sign, string birthday)
{
    this->LnameFname = LnameFname;
    this->sign = sign;
    this->birthday = birthday;

    wcout << L"Вызван конструктор с параметром класса Sign" << endl;
}

// конструктор копирования
Sign::Sign(const Sign &s)
{
    this->LnameFname = s.LnameFname;
    this->sign = s.sign;
    this->birthday = s.birthday;

    wcout << L"Вызван конструктор копирования класса Sign" << endl;
}

// деструктор
Sign::~Sign()
{
    wcout << L"Вызван деструктор класса Sign" << endl;
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
    wcout << L"\nЧто хотите получить?\n" <<
                L"1 - Фамилия Имя\n" <<
                L"2 - Знак зодиака\n" <<
                L"3 - День рождения\n" <<
                L"4 - Все поля" << endl;
    wcout << L"Выбор: ";
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
        wcout << L"Неверный ввод" << endl;
    }

    if (choice == "1") cout << L"\nФамилия Имя: " << this->LnameFname << endl;
    else if (choice == "2") cout << L"\nЗнак зодиака: " << this->sign << endl;
    else if (choice == "3") cout << L"\nДень рождения: " << this->birthday << endl;
    else if (choice == "4") cout << L"\nФамилия Имя: " << this->LnameFname << " | Знак зодиака: " << this->sign << " | День рождения: " << this->birthday << endl;
    else
    {
        wcout << L"Ошибка выбора" << endl;
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
    wcout << L"\nЧто хотите изменить?\n" <<
            L"1 - Фамилия Имя\n" <<
            L"2 - Знак зодиака\n" <<
            L"3 - День рождения\n" << endl;
    wcout << "Выбор: ";
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
        wcout << L"Неверный ввод" << endl;
    }

    if (choice == "1")
    {
        getline(cin, choice);

        wcout << L"Фамилия Имя: ";
        getline(cin, this->LnameFname);
    }
    else if (choice == "2")
    {
        getline(cin, choice);

        wcout << L"Знак зодиака: ";
        getline(cin, this->sign);
    }
    else if (choice == "3")
    {
        getline(cin, choice);

        wcout << L"День рождения: ";
        getline(cin, this->birthday);

        for (int i = 0; i < birthday.size(); i++)
        {
            if (birthday[i] >= 'A' && birthday[i] <= 'Z')
            {
                wcout << L"Неверный ввод" << endl;
                exit(0);
            }

            if (birthday[i] == ',' || birthday[i] == '/' || birthday[i] == ':' || birthday[i] == ' ' || birthday[i] == ';')
            {
                wcout << L"Неверный ввод" << endl;
                exit(0);
            }
        }
    }
    else
    {
        wcout << L"Ошибка выбора" << endl;
        exit(0);
    }
}

ostream &operator<< (ostream &stream, Sign &s) // перегрузка оператора извлеченния
{
    stream << L"\nВсе поля класса:" << endl;
    stream << s.LnameFname << endl;
    stream << s.sign << endl;
    stream << s.birthday << endl;

    return stream;
}

istream &operator>> (istream &stream, Sign &s) // перегрузка оператора вставки
{
    setlocale(LC_CTYPE, "Russian");
    string buf;

    wcout << L"Вставка значений:" << endl;
    wcout << L"Фамилия имя: ";
    getline(stream, buf);
    s.LnameFname = buf;

    wcout << L"Знак зодиака: ";
    getline(stream, buf);
    s.sign = buf;

    wcout << L"День рождения: ";
    getline(stream, buf);
    s.birthday = buf;

    for (int i = 0; i < buf.size(); i++)
        {
            if (buf[i] >= 'A' && buf[i] <= 'Z')
            {
                wcout << L"Неверный ввод" << endl;
                exit(0);
            }

            if (buf[i] == ',' || buf[i] == '/' || buf[i] == ':' || buf[i] == ' ' || buf[i] == ';')
            {
                wcout << L"Неверный ввод" << endl;
                exit(0);
            }
        }

    return stream;
}
