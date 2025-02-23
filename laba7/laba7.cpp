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

string read(int number, int count) {
        setlocale(LC_CTYPE, "");
        ifstream in("note.txt"); // окрываем файл для чтения
        if (in.is_open())
        {
            string line = "";
            getline(in, line);
            int length = 1 + (stoi(line) * 4) ;
            for (int i = 0; i < length; i++) {
                if (i == number + (count * 4)) {
                    return line;
                }
                else {
                    getline(in, line);
                }
            
            }

        }
        in.close();
    return "";
}

void name(laptop* array, int len){
    vector<string> names;
    vector<int> pos;
    int rep = 0, pos1 = 0;
    bool repeat = false;
    for (int i = 0; i < len; i++) {
        names.push_back(array[i].name);
    }
 
    for (int i = 0; i < names.size(); i++) {
         for (int j = i; j < names.size()-1; j++) {
             if (names[i] == names[j + 1]) {

                 rep += 1;
                 pos.push_back(j + 1);
             }
         }
         if (rep == names.size()-1) {
             break;

         }
         else {
             i += rep;
             rep = 0;
         }
    }

    for (int i = 0; i < pos.size(); i++) {
        names.erase(names.begin() + (pos[i] - i));
    }

    for (int i = 0; i < names.size(); i++) {
        cout << names[i] << endl;
        for (int j = 0; j < len; j++) {
            if (names[i] == array[j].name) {
                cout << "   Ноутбук " << j + 1 << endl;
            }
        }
    }
}

void size(laptop* array, int len) {
    vector<string> names;
    vector<int> pos;
    int rep = 0, pos1 = 0;
    bool repeat = false;
    for (int i = 0; i < len; i++) {

        names.push_back(array[i].size1);
    }

    for (int i = 0; i < names.size(); i++) {
        for (int j = i; j < names.size() - 1; j++) {
            if (names[i] == names[j + 1]) {
                rep += 1;
                pos.push_back(j + 1);
            }
        }
        if (rep == names.size() - 1) {
            break;
        }
        else {
            i += rep;
            rep = 0;
        }
    }

    for (int i = 0; i < pos.size(); i++) {
        names.erase(names.begin() + (pos[i] - i));
        
    }

    for (int i = 0; i < names.size(); i++) {
        cout << names[i] << endl;
        for (int j = 0; j < len; j++) {
            if (names[i] == array[j].size1) {
                cout << "   Ноутбук " << j + 1 << endl;
            }
        }
    }
}

void weigth(laptop* array, int len) {
    vector<string> names;
    vector<int> pos;
    int rep = 0, pos1 = 0;
    bool repeat = false;
    for (int i = 0; i < len; i++) {
        names.push_back(array[i].weigth);
    }

    for (int i = 0; i < names.size(); i++) {
        for (int j = i; j < names.size() - 1; j++) {
            if (names[i] == names[j + 1]) {

                rep += 1;
                pos.push_back(j + 1);
            }
        }
        if (rep == names.size() - 1) {
            break;

        }
        else {
            i += rep;
            rep = 0;
        }
    }

    for (int i = 0; i < pos.size(); i++) {
        names.erase(names.begin() + (pos[i] - i));
    }

    for (int i = 0; i < names.size(); i++) {
        cout << names[i] << endl;
        for (int j = 0; j < len; j++) {
            if (names[i] == array[j].weigth) {
                cout << "   Ноутбук " << j + 1 << endl;
            }
        }
    }
}

void price(laptop* array, int len) {
    vector<string> names;
    vector<int> pos;
    int rep = 0, pos1 = 0;
    bool repeat = false;
    for (int i = 0; i < len; i++) {
        names.push_back(array[i].price);
    }

    for (int i = 0; i < names.size(); i++) {
        for (int j = i; j < names.size() - 1; j++) {
            if (names[i] == names[j + 1]) {

                rep += 1;
                pos.push_back(j + 1);
            }
        }
        if (rep == names.size() - 1) {
            break;

        }
        else {
            i += rep;
            rep = 0;
        }
    }

    for (int i = 0; i < pos.size(); i++) {
        names.erase(names.begin() + (pos[i] - i));
    }

    for (int i = 0; i < names.size(); i++) {
        cout << names[i] << endl;
        for (int j = 0; j < len; j++) {
            if (names[i] == array[j].price) {
                cout << "   Ноутбук " << j + 1 << endl;
            }
        }
    }
}

void search(laptop* array, int len) {
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

            case 1: name(array, len);  break;
            case 2: size(array, len);  break;
            case 3: weigth(array, len);  break;
            case 4: price(array, len);  break;
            case 5: return;       break;
            }

            _getch();
        }


    }


    _getch();
}

int main()
{   
    setlocale(LC_CTYPE, "");
    
    int count = 0, count2 = 0;
    int len = stoi(read(0, 0));
    laptop* array;
    array = new laptop[len];
    while (count2 < len) {
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
    //std::this_thread::sleep_for(std::chrono::milliseconds(15000));
    int counter = 1, chosen_option = counter;
    vector<string> options;

    options.push_back("Поиск по параметру");
    options.push_back("Выход");

    while (chosen_option != 2)
    {

        system("cls");



        for (size_t i = 0; i < options.size(); ++i)
        {
            if ((i + 1) == counter) cout << "> " << options[i] << endl;
            else                    cout << options[i] << endl;
        }



        char pressed = _getch();

        if (pressed == 'w' && counter != 1)
            counter--;
        if (pressed == 's' && counter != options.size())
            counter++;

        if (pressed == '\r' || pressed == '\n') {
            chosen_option = counter;
            system("cls");

            switch (chosen_option)
            {

            case 1: search(array, len);  break;
            case 2: return 0;       break;

            }

            _getch();
        }


    }


    _getch();
}