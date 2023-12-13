#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include "TextScan.h"

using namespace std;

void TextScaner()
{
    fstream file; // создаем поток ввода
    file.open("Text.txt"); // открытие файла

    if (!file.is_open()) // если файл не открылся
    {
        cout << "Ошибка открытия файла!" << endl;
        exit(0);
    }

    else
    {
        string line; // строка, в которую будут считываться значения из файла

        while (!file.eof()) // пока не конец файла
        {
            string bufLine;
            getline(file, bufLine); // считываем строку
            line += bufLine + '\n';
        }

        string Suggestion; // хранение предложения
        queue<string> storeSug; // хранение предложений

        for (int id = 0; id < line.size()+1; id++)
        {
            Suggestion += line[id];
            // если конец предложения
            if (line[id] == '.' || line[id] == '!' || line[id] == '?' || line[id] == '\0')
            {
                if (line[id] == '?') storeSug.push(Suggestion);
                Suggestion.clear();
            }
        }
        Suggestion.clear();
        for (int id = 0; id < line.size()+1; id++)
        {
            Suggestion += line[id];
            // если конец предложения
            if (line[id] == '.' || line[id] == '!' || line[id] == '?' || line[id] == '\0')
            {
                if (line[id] == '!') storeSug.push(Suggestion);
                Suggestion.clear();
            }
        }

        while (!storeSug.empty())
        {
            cout << storeSug.front() << endl;
            storeSug.pop();
        }
    }

    file.close(); // закрываем файл
}
