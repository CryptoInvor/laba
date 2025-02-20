

#include <iostream>
#include <vector>
#include <ctime>
#include<cstdlib>
using namespace std;

vector<int> fill(){
    srand(time(NULL));
    vector<int> s;
    cout << "Вектор состоит из следующих элементов: ";
    for (int i = 0; i < 50; i++) {
        s.push_back(rand() % 100 + 1);
        
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
    for (int i = 0; i < s.size(); i++) {
        sum += s[i];
    }
    sum = sum / s.size();
    cout << "среднее значение: " << sum << endl;
    s.insert(s.begin() + k, sum);
    return s;
}


vector<int> del(vector<int> s, int k) {
    int small = 9999999, big = 0, place = 0;
    if (k == 0) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] < small) {
                small = s[i];
            }
        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == small) {
                place = i;
            }
        }
        cout << "Наименьшее значение: " << small << endl;
        s.erase(s.begin() + place);
    }
    else {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] > big) {
                big = s[i];
            }
        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == big) {
                place = i;
            }
        }
        cout << "Наибольшее значение: " << big << endl;
        s.erase(s.begin() + place);
        
    }


    return s;
}






int main()
{
    setlocale(LC_CTYPE,"");
    int k, type;
    cout << "Введите положение элемента среднего значения: ";
    cin >> k;
    if (k < 0){
        cout << "Пожалуйста, введите положотиельное значение";
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
    element = fill();
    cout << "---------------------------" << endl;
    element = middle(element, k);
    cout << "---------------------------" << endl;
    element = del(element, type);
    cout << "---------------------------" << endl;
    cout << "Финальный вид вектора: ";
    for (int i = 0; i < 50; i++) {
        if (i != 49) {
            cout << element[i] << ", ";
        }
        else {
            cout << element[i] << endl;
        }
    }
    return 0;
}


