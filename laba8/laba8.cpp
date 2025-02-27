#include <fstream>
#include <map>
#include <iostream>
#include <string>

using namespace std;


void search_char(map<string, int> text) {
    system("cls");
    map<string, int>::iterator it = text.begin();
    string o;
    char chr;
    cout << "Введите искомую букву: ";
    cin >> chr;
    while (it != text.end()) {
        if (it->first[0] == chr) {
            cout << it->first << " : " << it->second << endl; // поиск и вывод по первой букве слова
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
        if (it->second > bigger) {// поиск наибольшего количества повторений
            bigger = it->second;
        }
        ++it;
    }
    it = text.begin();
    while (it != text.end()) {
        if (it->second == bigger) {
            cout << it->first << " : " << it->second << endl; // вывод наибольшего количества повторений
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
        if (it->second < smaller) { // поиск наименьшего количества повторений
            smaller = it->second;
        }
        ++it;
    }
    it = text.begin();
    while (it != text.end()) {
        if (it->second == smaller) {
            cout << it->first << " : " << it->second << endl; // вывод наименьшего количества повторений
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
        cout << name << " : " << text[name] << endl; // вывести определенное слово
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
                cout << it->first << " : " << num << endl; // вывод всех слов с конкретным значением повторений
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
        cout << it->first << " : " << it->second << endl; // показать все элементы словаря
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
                out << it->first << " : " << it->second << endl; // записываем из вектора в файл
                ++it;
            }
        }
        out.close();
        cin.clear();
        cout << "Запись прошла успешно" << endl;
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
            text.insert(pair<string, int>(line, 0)); // запись из файла в вектор
        }
    }
    in.close();

    in.open("note.txt");
    if (in.is_open())
    {
        while (in >> line)
        {
            text[line] += 1; // подсчет повторений
        }
    }
    in.close();


    bool exit = false;
    while (exit == 0) {
        system("cls"); // реализация меню выбора типа сортировки
        cout << "Введите номер выбранного параметра" << endl;
        cout << "Доступные парамерты поиска: " << endl;
        cout << "1) по имени" << endl;
        cout << "2) по первой букве слова " << endl;
        cout << "3) по числу" << endl;
        cout << "4) наибольший элемент" << endl;
        cout << "5) наименьший элемент" << endl;
        cout << "6) показать весь словарь" << endl;
        cout << "Для завершения работы программы напишите 'выход' или 'exit' " << endl;
        cin >> input;
        if ((input == "exit") || (input == "выход") || (input == "Выход") || (input == "Exit")) {
            write(text);
            break;
        }
        int choise = stoi(input);
        switch (choise) {
        case 1: { search_name(text); }break;// сортировать по имени
        case 2: { search_char(text); }break;// сортировать по первой букве
        case 3: { search_num(text); }break;// сортировать по числу
        case 4: { sort_max(text); }break;// сортировать по максимальному количеству повторений
        case 5: { sort_min(text); }break;// сортировать по минимальному количеству повторений
        case 6: { show(text); }break;// показать все
            input = "";
        }
        
    }
    return 0;
}


