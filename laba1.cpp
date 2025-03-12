#include <iostream>
#include <string>
using namespace std;


float add(float x, float y){ // сумма
    return x + y;
}


float substract(float x, float y){ // вычитание
    return x - y;
}


float multiply(float x, float y){ // умножение
    return x * y;
}


float divide(float x, float y, string problem, string error){ // деление
    if (y != 0) { // проверка на деление на ноль
        return x / y;
    }
    else {
        cout << "Невозможно делить на ноль" << endl;
        cout << problem << endl;
        for (int i = 0; i < (problem.length() - 1); i++) {
            error += " ";
        }
        cout << error + "^" << endl;
        cin >> x;
        exit;

    }
    
}


int main(int argc, char *argv[])
{
    setlocale(LC_CTYPE, "");
    int flag = 0;
    string mathproblem,subproblem,subproblem2,error = "";
    for (int i = 1; i < argc; i++) { // запись аргументов в строку
        if (i <= 3) {
            mathproblem += argv[i];
        }
    }

    for (int i = 0; i < mathproblem.length(); i++) { // анализ аргументов
        bool problem = !((mathproblem[i] != '0') && (mathproblem[i] != '1') && (mathproblem[i] != '2') && (mathproblem[i] != '3') && (mathproblem[i] != '4') && (mathproblem[i] != '5') && (mathproblem[i] != '6') && (mathproblem[i] != '7') && (mathproblem[i] != '8') && (mathproblem[i] != '9'));
        if (problem && (flag == 0)) {
            subproblem += mathproblem[i];
        }
        else if ((flag == 0)) { // определение мат. операции
            if (mathproblem[i] == '+') { flag = 1; }
            else if (mathproblem[i] == '-'){ flag = 2;}
            else if (mathproblem[i] == '*'){ flag = 3;}
            else if (mathproblem[i] == '/'){ flag = 4; }
            else { flag = -1; }
            
        }
        else if ((i != 0) && (problem)) {
            subproblem2 += mathproblem[i];
        }
         else if (!(problem) && (flag != 0)) { // обработка ошибки записи выражения
            cout << "Выражение записано неверно" << endl;
            cout << mathproblem << endl;
            for (int j = 0; j < (i - 1); j++) {
                error += " ";
            }
            cout << error + "^" << endl;
            cin >> mathproblem;
            return 0;
        }
    }
    if ((subproblem == "")) {// обработка ошибки записи выражения
        cout << "Выражение записано неверно" << endl;
        cout << mathproblem << endl;
        cout << "^" << endl;
        cin >> mathproblem;
        return 0;
    } else if ((subproblem2 == "")) {
        cout << "Выражение записано неверно" << endl;
        cout << mathproblem << endl;
        for (int i = 0; i < (mathproblem.length() - 1); i++) {
            error += " ";
        }
        cout << error + "^" << endl;
        cin >> mathproblem;
        return 0;
    }
    float x = stof (subproblem); // перевод строки в число
    float y = stof (subproblem2);
    switch (flag) // выполнение мат. операции
    {
    case 1:
        cout << mathproblem + " = ";
        cout << add(x, y) << endl;
        break;
    case 2:
        cout << mathproblem + " = ";
        cout << substract(x, y) << endl;
        break;
    case 3:
        cout << mathproblem + " = ";
        cout << multiply(x, y) << endl;
        break;
    case 4:
        float test = divide(x, y, mathproblem, error);
        cout << mathproblem + " = ";
        cout << divide(x, y, mathproblem, error) << endl;
        break;
    }



    cin >> mathproblem; // ожидание ввода для предотвращения преждевременного закрытия программы
    return 0;    
}

