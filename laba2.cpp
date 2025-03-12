
#include <string>
#include <iostream>
using namespace std;

void print(int* array, int lenght) { // вывод массивов
    for (int j = 0; j < lenght; j++) {
        cout << array[j] << " ";
    }
    cout << endl;
}

int main(int argc, char* argv[])
{   
    
    
    string ab, a, b;
    setlocale(LC_CTYPE, "");
    int cas = stoi(argv[1]);
    
    switch (cas)
    {
    case 1: {
        int sub,x,y;
        int* x1;
        int* y1;
       

        cout << "Переменная а: "; // переменные до действий с указателями
        cin >> x;
        cout << "Переменная b: ";
        cin >> y;

        x1 = &x; //присваиваем указателям адрес переменной
        y1 = &y;
        *x1 = *x1 * 2;// удваиваем а
        sub = *x1;
        *x1 = *y1;
        *y1 = sub;// меняем a и b местами

        cout << "a: " << x << endl; // переменные после действий с указателями
        cout << "b: " << y << endl;
    }break;
    case 2:{
        srand(time(0));
        int arraylength; // длинны массивов
        cout << "длинна массивов: ";
        cin >> arraylength;
        if ((arraylength <= 0)) {
            cout << "длинна массивов должна быть положительным числом больше нуля"<< endl;
            return 0;
        }
        int counter1 = 0, counter2 = 0;
        int* array1{ new int[arraylength] };
        int* array2{ new int[arraylength] };

        for (int i = 0; i < arraylength; i++) {
            array1[i] = (rand() % 101) - 50;
            if (array1[i] < 0) counter1 += 1;
            array2[i] = (rand() % 101) - 50;
            if (array2[i] < 0) counter2 += 1;
            
        }
        cout << arraylength << endl;
        print(array1, arraylength);
        print(array2, arraylength);
        if (counter1 > counter2) {
            cout << "Первый массив имеет больше отрицательных элементов(" << counter1 << ")" << endl;
        }
        else if (counter2 > counter1) {
            cout << "Второй массив имеет больше отрицательных элементов(" << counter2 << ")" << endl;
        }
        else {
            cout << "Массивы имеют одинаковое количество отрицательных элементов(" << counter2 << ")" << endl;
        }
        }break;
    case 3:{
        srand(time(0));
        int arraylength; // длинны массивов
        cout << "длинна массива: ";
        cin >> arraylength;
        if ((arraylength <= 0)) {
            cout << "длинна массивов должна быть положительным числом больше нуля" << endl;
            return 0;
        }
        int* p_array{ new int[arraylength] };

        for (int i = 0; i < arraylength; i++) {
            p_array[i] = (rand() % 101) - 50;
        }
        print(p_array, arraylength);
        for (int i = 0; i < arraylength; i++) {
            if (p_array[i] > 0) p_array[i] = p_array[i] * p_array[i];
        }
        
        print(p_array, arraylength);

        }break;
    case 4:{
        
        struct coords {
            int X;
            int Y;
        };
        struct sphere {
            coords XY;
            int radius;
        };
        
        int spherenumber;
        cout << "количество окружностей: ";
        cin >> spherenumber;
        if (spherenumber <= 0) {
            cout << "количество окружностей должно быть положительным числом больше нуля" << endl;
            return 0;
        }
        sphere* array;
        array = new sphere[spherenumber];
        int x, y, rad;
        int biggest = 0, counter = 0;
        int *pos = new int[spherenumber];
        for (int i = 0; i < spherenumber; i++) {
            cout << "Окружность: " << i+1 << endl;
            cout << "Радиус: ";
            cin >> rad;
            if (rad < 0) {
                cout << "радиус должен быть положительным числом" << endl;
                return 0;
            }
            array[i].radius = rad;
            cout << "Х: ";
            cin >> x;
            array[i].XY.X = x;
            cout << "Y: ";
            cin >> y;
            array[i].XY.Y = y;
        }
        for (int i = 0; i < spherenumber; i++) {
            if (array[i].radius > biggest) {
                biggest = array[i].radius;
            }
        }
        for (int i = 0; i < spherenumber; i++) {
            if (array[i].radius == biggest) {
                pos[counter] = i;
                counter += 1;
            }
        }
        for(int i = 0; i < counter; i++){
        cout << "координаты наибольшей окружности: " << array[pos[i]].XY.X << ", " << array[pos[i]].XY.Y << endl;
        }
        }break;
    }

    
    
    return 0;
}

