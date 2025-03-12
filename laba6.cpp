

#include <iostream>
#include <vector>
#include <ctime>
#include<cstdlib>
using namespace std;

vector<int> fill(){
    srand(time(NULL));
    vector<int> s;
    cout << "Вектор состоит из следующих элементов: ";
    for (int i = 0; i < 50; i++) { // случайное генерирование и вывод всех элементов вектора
        s.push_back(rand() % 10 + 1);
        
        if (i != 49) {
            cout << s[i] << ", ";
        }
        else {
            cout << s[i] << endl;
        }
    }
    return s;
}


vector<int> middle(vector<int> s, int k) {
    int sum = 0;
    for (int i = 0; i < s.size(); i++) { // подсчет среднего арифметического
        sum += s[i];
    }
    sum = sum / s.size();
    cout << "среднее значение: " << sum << endl; // вывод и удаление среднего арифметического
    s.insert(s.begin() + (k-1), sum);
    return s;
}


vector<int> del(vector<int> s, int k) {
    int small = 9999999, big = 0, count = 0, holder = 0;
    vector<int> place;
    if (k == 0) { // поиск наименьшего значения
        for (int i = 0; i < s.size(); i++) {
            if (s[i] < small) {
                small = s[i];
            }
        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == small) {
                place.push_back(i);
                count += 1;
            }
        }
        cout << "Наименьшее значение: " << small << endl; // вывод и удаление наименьшего 
        for (int o = 0; o < count; o++) {
            holder = place[o] - o;
            s.erase(s.begin() + holder);
        }
        
    }
    else {
        for (int i = 0; i < s.size(); i++) { // поиск наибольшего значения
            if (s[i] > big) {
                big = s[i];
            }
        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == big) {
                place.push_back(i);
                count += 1;
            }
        }
        cout << "Наибольшее значение: " << big << endl; // вывод и удаление наибольшего значения
        for (int o = 0; o < count; o++) {
            s.erase(s.begin() + place[o]);
        }
        
    }


    return s;
}






int main()
{
    setlocale(LC_CTYPE,"");
    int k, type; // инициализация и ввод переменных
    cout << "Введите положение элемента среднего значения: ";
    cin >> k;
    if (k < 0){
        cout << "Пожалуйста, введите положотиельное значение"; // обработка ошибки
        return 0;
    }
    cout << "Введите 0 для удаления минимального элемента, 1 для удаления максимального элеменита: ";
    cin >> type;
    if ((type != 0) && (type != 1)) {
        cout << "Пожалуйста, введите 0 или 1";
        return 0;
    }
    cout << "---------------------------" << endl;
    vector<int> element;
    element = fill(); // заполенение вектора случайными значениями
    cout << "---------------------------" << endl;
    element = middle(element, k); // удаление среднего арифметического всех значений вектора
    cout << "---------------------------" << endl;
    element = del(element, type); // удаление минимального или максимального элемента
    cout << "---------------------------" << endl;
    cout << "Финальный вид вектора: ";
    for (int i = 0; i < element.size(); i++) { // вывод всех элементов вектора
        if (i != element.size() - 1) {
            cout << element[i] << ", ";
        }
        else {
            cout << element[i] << endl;
        }
    }
    return 0;
}


