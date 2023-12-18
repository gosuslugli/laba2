#include <iostream>
#include "Storage.h"
#include "Sign.h"
#include "TextScan.h"
#include <string>
#include <Windows.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Store store; // объект, где будут храниться данные

    // цикл меню
    while (1)
    {
        string choice; // переменная выбора пользователя

        wcout << L"\n~~~МЕНЮ~~~" << endl;
        wcout << L"1 - Поиск по знаку\n"
             << L"2 - Извлечь поля объекта\n"
             << L"3 - Получить определенные поля\n"
             << L"4 - Вставить значение\n"
             << L"5 - Изменить значение\n"
             << L"6 - Удалить значение\n"
             << L"7 - Вывести ?, потом ! предложения" << endl;
        wcout << L"Выбор: ";
        cin >> choice; // ввод выбора
        wcout << "\n" << endl;

        // обработка ввода (исключительные ситуации)
        try
        {
            // проверяем все символы
            for (int id = 0; id < choice.size()+1; id++)
            {
                // если буква, кидаем ошибку
                if (isalpha(choice[id])) throw "Error";
            }

            // если выбор не лежит в диапазоне, кидаем ошибку
            if (choice > "7" || choice < "1") throw "Error";
        }
        catch(const char*mssg) // обработка ошибки
        {
            wcout << L"Ошибка ввода" << endl;
            exit(0);
        }

        // проверка выбора пользователя
        if (choice == "1") store.FindSign();
        else if (choice == "2") store.ExtractField();
        else if (choice == "3") store.GetFiel();
        else if (choice == "4") store.Set();
        else if (choice == "5") store.Change();
        else if (choice == "6") store.Delete();
        else if (choice == "7") TextScaner();
        else {wcout << L"Ошибка ввода" << endl; exit(0);}
    }
}
