
#include <string>
#include <iostream>
using namespace std;


void print(int* array, int lenght) { // вывод всех элементов массива с их адресами и поиск наименьшего элемента
    int smallest = 9999999;
    for (int j = 0; j < lenght; j++) {
        if (array[j] < smallest) { smallest = array[j]; }
        cout << array[j] << " : " << &array[j] << endl; // вывод элемента и адреса
    }
    for (int j = 0; j < lenght; j++) {
        if (array[j] == smallest) {
            cout << "наименьший элемент: " << array[j] << " " << &array[j] << endl; // вывод наименьшего элемента с адресом
        }
    }
}


void scan(int* array, int rows, int columns) { // вывод каждой строки двумерного массива с проверкой на возрастание
    int exception = 0;
        if (columns == 1) {
            for (int j = 0; j < columns; j++) {
                cout << array[j] << " ";
            }
        }
        else {
            for (int j = 0; j < columns - 1; j++) {
                cout << array[j] << " ";
                if(j == (columns-2)){ cout << array[j+1] << " "; }
                if ((array[j] < array[j + 1])) {

                }
                else {
                    exception += 1;
                }
            }
        }
        if (exception == 0) {
            cout << "|| числа идут в порядке возрастания" << endl;
        }
        else {
            cout << "|| порядок возрастания нарушен" << endl;
        }
    }



int main(int argc, char* argv[])
{
    setlocale(LC_CTYPE, "");
    string flag = "";
    flag += argv[1];
    int problem = stoi(flag);
    switch (problem) {
    case 1: {
        srand(time(0));
        int arraylength; // выбор длинны массива
        cout << "длинна массива: ";
        cin >> arraylength;
        if ((arraylength <= 0)) { // обработка ошибки
            cout << "длинна массива должна быть положительным числом больше нуля" << endl;
            return 0;
        }
        int* array{ new int[arraylength] };
        for (int i = 0; i < arraylength; i++) { // заполнение массива случайными элементами
            array[i] = rand() % 101 - 50;
        }
        print(array, arraylength);






    }break;
    case 2: {
        srand(time(0));
        int rows; // ряды
        int columns; // колонный
        cout << "кол-во рядов: ";
        cin >> rows;
        if ((rows <= 0)) { // обработка ошибки
            cout << "количество рядов должно быть положительным числом больше нуля" << endl;
            return 0;
        }
        cout << "кол-во колонн: ";
        cin >> columns;
        if ((columns <= 0)) {// обработка ошибки
            cout << "количество колонн должно быть положительным числом больше нуля" << endl;
            return 0;
        }
        else if (rows == columns) {// обработка ошибки
            cout << "количество колонн не должно совпадать с количеством рядов" << endl;
            return 0;
        }
        int** array{ new int* [rows] }; // создание двумерного массива
        for (int i = 0; i < rows; i++) {
            array[i] = new int[columns] {};
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                array[i][j] = rand() % 102 - 50; // заполнение двумерного массива случайными числами от -50 до 50
            }
        }
        for (int i = 0; i < rows; i++) {
            scan(array[i], rows, columns);
        }

    }break;
    }
    return 0;
}


