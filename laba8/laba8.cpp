#include <fstream>
#include <map>
#include <iostream>
#include <string>

using namespace std;


void serach_char(map<string, int> text) {
    map<string, int>::iterator it = text.begin();
    string o;
    char chr;
    cout << "Введите искомое слово: ";
    cin >> chr;
    while (it != text.end()) {
        if (it->first[0] == chr) {
            cout << it->first << " : " << it->second << endl;
        }
        ++it;
    }
    cin >> o;
}


void sort_max(map<string, int> text){
    map<string, int>::iterator it = text.begin();
    string o;
    system("cls");
    cout << "Наибольшее количество повторов: " << endl;
    int bigger = 0;
    while (it != text.end()) {
        if (it->second > bigger) {
            bigger = it->second;
        }
        ++it;
    }
    it = text.begin();
    while (it != text.end()) {
        if (it->second == bigger) {
            cout << it->first << " : " << it->second << endl;
        }
        ++it;
    }
    cin >> o;
}



void sort_min(map<string, int> text){
    map<string, int>::iterator it = text.begin();
    string o;
    system("cls");
    cout << "Наименьшее количество повторов: " << endl;
    int smaller = 999999999;
    while(it != text.end()) {
        if (it->second < smaller) { 
            smaller = it->second;
        }
        ++it;
    }
    it = text.begin();
    while (it != text.end()) {
        if (it->second == smaller) {
            cout << it->first << " : " << it->second << endl;
        }
        ++it;
    }
    cin >> o;
}


void search_name(map<string, int> text){
    string name;
    system("cls");
    cout << "Введите искомое слово: ";
    cin >> name;
    if (text.count(name) == 1) {
        cout << name << " : " << text[name] << endl;
    }
    else {
        cout << "Такого слова нет в словаре" << endl;
    }
    cin >> name;
}


void search_num(map<string, int> text) {
    map<string, int>::iterator it = text.begin();
    string o;
    int num;
    system("cls");
    cout << "Введите искомое число: ";
    cin >> num;
    if (num == 0) {
        cout << "Введите положительное число больше нуля" << endl;
    }
    while (it != text.end()) {
        if (it->second == num) {
                cout << it->first << " : " << num << endl;
                cin >> o;
                return;
        }
        ++it;
    }
    cout << "Слова с таким количеством повторений нет в словаре" << endl;
    cin >> o;
}


void show(map<string, int> text) {
    system("cls");
    map<string, int>::iterator it = text.begin();
    string o;
    while (it != text.end()) {
        cout << it->first << " : " << it->second << endl;
        ++it;
    }
    cin >> o;
}


void write(map<string, int> text){
    system("cls");
    map<string, int>::iterator it = text.begin();
    char inp;
    cout << "Хотите записать словарь в файл? Y/N" << endl;
    cin >> inp;
    if ((inp == 'Y') || (inp == 'y')) {
        ofstream out;          // поток для записи
        out.open("note1.txt");      // открываем файл для записи
        if (out.is_open())
        {
            while (it != text.end()) {
                out << it->first << " : " << it->second << endl;
                ++it;
            }
        }
        out.close();
        cin.clear();
        cout << "Запись прошла успешно" << endl;
        cin >> inp;
    }
}


int main()
{
    setlocale(LC_CTYPE, "");
    map<string, int> text;
    string input;
    string line;
    ifstream in("note.txt"); // окрываем файл для чтения
    if (in.is_open())
    {
        while (in >> line)
        {
            text.insert(pair<string, int>(line, 0));
        }
    }
    in.close();

    in.open("note.txt");
    if (in.is_open())
    {
        while (in >> line)
        {
            text[line] += 1;
        }
    }
    in.close();


    bool exit = false;
    while (exit == 0) {
        system("cls");
        cout << "Доступные парамерты поиска: " << endl;
        cout << "1) по имени(введите name)" << endl;
        cout << "2) по числу(введите num)" << endl;
        cout << "3) наибольший элемент(введите max)" << endl;
        cout << "4) наименьший элемент(введите min) " << endl;
        cout << "5) показать весь словарь(введите show) " << endl;
        cout << "Для завершения работы программы напишите 'выход' или 'exit' " << endl;
        if ((input == "exit") || (input == "выход") || (input == "Выход") || (input == "Exit")) { 
            write(text);
            break; 
        }
        cin >> input;
        if (input == "name") {
            search_name(text);
            input = "";
        }
        else if (input == "num") {
            search_num(text);
            input = "";
        }
        else if (input == "max") {
            sort_max(text);
            input = "";
        }
        else if (input == "min") {
            sort_min(text);
            input = "";
        }
        else if (input == "show") {
            show(text);
            input = "";
        }
        
    }
    return 0;
}


