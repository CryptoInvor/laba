#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <conio.h>
#include <chrono>
#include <thread>



using namespace std;

struct laptop {
    string name;
    string size1;
    string weigth;
    string price;
};


string read(int number, int count) { // чтение определённого элемента из файла
        setlocale(LC_CTYPE, "");
        ifstream in("input.txt"); // окрываем файл для чтения
        if (in.is_open())
        {
            string line = "";
            getline(in, line);
            int length = 1 + (stoi(line) * 4) ;
            for (int i = 0; i < length; i++) {
                if (i == number + (count * 4)) {
                    return line; // возвращаем запрошенную строку
                }
                else {
                    getline(in, line); // ищем запрошенную строку дальше
                }
            
            }

        }
        in.close();
    return "";
}


void show(laptop* array, int len, int type) { // показывает все ноутбуки
    switch (type) {
    case 1: {
        for (int i = len-1; i < len; i++) {
            cout << "       " << array[i].size1 << endl;
            cout << "       " << array[i].weigth << endl;
            cout << "       " << array[i].price << endl;
        }
    }break;
    case 2: {
        for (int i = len - 1; i < len; i++) {
            cout << "       " << array[i].name << endl;
            cout << "       " << array[i].weigth << endl;
            cout << "       " << array[i].price << endl;
        }
    }break;
    case 3: {
        for (int i = len - 1; i < len; i++) {
            cout << "       " << array[i].name << endl;
            cout << "       " << array[i].size1 << endl;
            cout << "       " << array[i].price << endl;
        }
    }break;
    case 4: {
        for (int i = len - 1; i < len; i++) {
            cout << "       " << array[i].name << endl;
            cout << "       " << array[i].size1 << endl;
            cout << "       " << array[i].weigth << endl;
        }
    }break;
    case 0: {
        for (int i = 0; i < len; i++) {
            cout << "Ноутбук " << i + 1 << endl;
            cout << "   " << array[i].name << endl;
            cout << "   " << array[i].size1 << endl;
            cout << "   " << array[i].weigth << endl;
            cout << "   " << array[i].price << endl;
        }
    }break;
    }
}



void sort(laptop* array, int len, int type) { // сортирует по цене
    vector<string> names;
    vector<string> originalNames;
    vector<int> pos;
    int rep = 0, pos1 = 0;
    bool repeat = false;
    switch (type) { // выбор типа сортировки
    case 1: {
        for (int i = 0; i < len; i++) { // запись названий в вектор
            names.push_back(array[i].name);
            originalNames.push_back(array[i].name);
        }
    }break;
    case 2: {
        for (int i = 0; i < len; i++) { // запись размеров в вектор
            names.push_back(array[i].size1);
            originalNames.push_back(array[i].size1);
        }
    }break;
    case 3: {
        for (int i = 0; i < len; i++) { // запись веса в вектор
            names.push_back(array[i].weigth);
            originalNames.push_back(array[i].weigth);
        }
    }break;
    case 4: {
        for (int i = 0; i < len; i++) { // запись цены в вектор
            names.push_back(array[i].price);
            originalNames.push_back(array[i].price);
        }
    }break;
    }
    

    for (int i = 0; i < names.size()-1; i++) { // поиск повторений
        for (int j = i; j < names.size()-1; j++) {
            if (names[i] == names[j + 1]) {
                rep += 1;
                pos.push_back(j + 1);
            }
        }
        if (rep == names.size() - 1) {
            break;

        }
        else if(names[i] == names[i+1]) {
            i += 1;
            rep = 0;
        }
    }

    for (int i = 0; i < pos.size(); i++) { // удаление повторений
        names.erase(names.begin() + (pos[i] - i));
    }

    for (int i = 0; i < names.size(); i++) { // вывод отсортированного списка ноутбуков
        cout << names[i] << endl;
        for (int j = 0; j < len; j++) {
            if (names[i] == originalNames[j]) {
                cout << "   Ноутбук " << j + 1 << endl;
                show(array, j+1, type);
            }
        }
    }
}


void search(laptop* array, int len) { // выбор типа поиска
    setlocale(LC_CTYPE, "");
    int counter = 1, chosen_option = counter;
    vector<string> options;

    options.push_back("Поиск по имени");
    options.push_back("Поиск по размерам");
    options.push_back("Поиск по весу");
    options.push_back("Поиск по цене");
    options.push_back("Показать всё");
    options.push_back("Выход");

    while (chosen_option != 6)
    {
        system("cls");

        for (size_t i = 0; i < options.size(); ++i)
        {
            if ((i + 1) == counter) cout << "> " << options[i] << endl;
            else                    cout << options[i] << endl;
        }

        char pressed = _getch();

        if (pressed == 'w' && counter != 1){
            counter--;
    }
        if (pressed == 's' && counter != options.size()){
            counter++;
        }

        if (pressed == '\r' || pressed == '\n') {
            chosen_option = counter;
            system("cls");

            switch (chosen_option)
            {

            case 1: sort(array, len, 1);  break;
            case 2: sort(array, len, 2);  break;
            case 3: sort(array, len, 3);  break;
            case 4: sort(array, len, 4);  break;
            case 5: show(array, len, 0);  break;
            case 6: return;       break;
            }

            _getch();
        }


    }


    _getch();
}
void menu(laptop* array, int len) {
    //std::this_thread::sleep_for(std::chrono::milliseconds(15000));
    int counter = 1, chosen_option = counter;
    vector<string> options;

    options.push_back("Поиск по параметру");
    options.push_back("Выход");

    while (chosen_option != 2)// реализация удобного меню
    {

        system("cls"); // отчистка консоли



        for (size_t i = 0; i < options.size(); ++i) // принт опций
        {
            if ((i + 1) == counter) cout << "> " << options[i] << endl;
            else                    cout << options[i] << endl;
        }



        char pressed = _getch(); // считывание нажатия клавиши

        if (pressed == 'w' && counter != 1) // реализация движения вверх и вниз
            counter--;
        if (pressed == 's' && counter != options.size())
            counter++;

        if (pressed == '\r' || pressed == '\n') {
            chosen_option = counter;
            system("cls");

            switch (chosen_option) // исполнение выбранной опции
            {

            case 1: search(array, len);  break;
            case 2: return;       break;

            }

            _getch();
        }


    }


    _getch();
}


int main(int argc, char* argv[])
{   
    

        setlocale(LC_CTYPE, "");

        int count = 0, count2 = 0;
        int len = stoi(read(0, 0));
        laptop* array;
        array = new laptop[len];
        while (count2 < len) { // чтение из файла
            count += 1;
            if (count == 1) {
                array[count2].name = read(count, count2);
            }
            else if (count == 2) {
                array[count2].size1 = read(count, count2);
            }
            else if (count == 3) {
                array[count2].weigth = read(count, count2);
            }
            else if (count == 4) {
                array[count2].price = read(count, count2);
                count2 += 1;
                count = 0;
            }

        }

    string number = argv[1];
    switch (stoi(number)){ // выбор одного из двух заданий по первому аргументу
    case 1: {
        menu(array, len); // меню для выбора типа сортировки
    }break;
    case 2: {
        ofstream out;          // поток для записи
        out.open("output.txt");      // открываем файл для записи
        if (out.is_open())
        {
            for (int i = len - 1; i >= 0; i--) { // записываем
                out << array[i].price << " ";
                out << array[i].weigth << " ";
                out << array[i].size1 << " ";
                out << array[i].name << " ";
            }
            out << len << endl;
        }
        out.close();
    }break;
    }
}