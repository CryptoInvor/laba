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
    string size;
    string weigth;
    string price;
};

string read(int number) {
        setlocale(LC_CTYPE, "");
        ifstream in("note.txt"); // окрываем файл для чтения
        if (in.is_open())
        {
            string line = "";
            getline(in, line);
            int length = stoi(line) + (stoi(line) * 4) ;
            for (int i = 0; i < length; i++) {
                if (i == number) {
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
    bool repeat = false;
    for (int i = 0; i < len; i++) {
        names.push_back("");
    }
    names[0] = array[0].name;
    pos.push_back(0);
    if (len > 1) {
        for (int i = 0; i < len-1; i++) {
            for (int j = i; j < len - 1; j++) {
                cout << "names[i] " << names[i] << endl;
                cout << "array[j+1].name " << array[j + 1].name << endl;
                cout << "(names[i] == array[j + 1].name)" << (names[i] == array[j + 1].name) << endl;
                if (names[i] == array[j + 1].name) {
                    repeat = true;
                    break;
                }
            }
            if (!repeat) {
                names.push_back(array[i].name);
            }
            else {
                repeat = false;
            }
        }

        for (int i = 0; i < len; i++) {
            for (int j = i; j < len - 1; j++) {
                if (names[i] == array[j + 1].name) {
                    pos.push_back(j + 1);
                }
            }
        }
    }
    for (int i = 0; i < names.size(); i++) {
        cout << names[i] << endl;
        for (int j = 0; j < pos.size(); j++) {
            if (names[i] == array[pos[j]].name) {
                cout << "   Ноутбук " << pos[j] + 1 << endl;
            }
        }
    }
}

void size(laptop* array, int len) {}

void weigth(laptop* array, int len) {}

void price(laptop* array, int len) {}

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
    int len = stoi(read(0));
    laptop* array;
    array = new laptop[len];
    while (count2 < len) {
        count += 1;
        if (count == 1) {
            array[count2].name = read(count);
        }
        else if (count == 2) {
            array[count2].size = read(count);
        }
        else if (count == 3) {
            array[count2].weigth = read(count);
        }
        else if (count == 4) {
            array[count2].price = read(count);
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