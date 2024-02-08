#include <iostream>
#include <math.h>
using namespace std;

float accuracy;

//================ Функция развития cos в ряд Тейлора ================//
float cos_Taylor(float a) {
    float sum = 1;
    float n = 1;
    float an = 1;
    while (an > accuracy) {
        an *= pow((-1), (n - 1)) * pow(a, 2) / (n * (n + 1));
        sum += an;
        n++;
    }
    return sum;
}

int main() {
    setlocale(LC_ALL, "Rus");

    double x, x1, xn, step, accuracy, y = 0, y_Taylor = 0, mistake = 0;

    cout << "----------------------------------------------------------------------------\n";
    cout << "Функция определена для аргумента Х > -1, меняющегося с шагом 0.5\n\n";
    cout << "    cos(x/2) / cos(x^2)   ,   -1<=x<=0\n";
    cout << "y = \n";
    cout << "    cos^2(x/2) * cos(2x)  ,   x>0\n";
    cout << "----------------------------------------------------------------------------\n\n";

    cout << "Введите начальное значение функции : ";
    cin >> x1;
    if ((x1 - int(x1)) != 0) {
        cout << "\n/================================ Error ===================================/\n";
        cout << " Начальное значение НЕ удовлетворяет условие\n";
        exit(0);
    }

    cout << "Введите конечное значение функции : ";
    cin >> xn;
    if (xn < x1 || (xn - int(xn)) != 0) {
        cout << "\n/================================ Error ===================================/\n";
        cout << " Конечное значение НЕ удовлетворяет условие\n";
        exit(0);
    }

    cout << "Введите шаг функции : ";
    cin >> step;
    if (step > (xn - x1)) {
        cout << "\n/================================ Error ===================================/\n";
        cout << " Шаг НЕ удовлетворяет условие\n";
        exit(0);
    }

    cout << "Введите точность расчётов для ряда Тейлора : ";
    cin >> accuracy;

    for (x = x1; x <= xn; x += step) {
        if (x >= -1 && x <= 0) {
            y = cos(x / 2) / cos(pow(x, 2));
            y_Taylor = cos_Taylor(x / 2) / cos_Taylor(pow(x, 2));
            mistake = y - y_Taylor;
        }
        else if (x > 0) {
            y = pow(cos(x / 2), 2) * cos(2*x);
            y_Taylor = pow(cos_Taylor(x / 2), 2) * cos_Taylor(2 * x);
            mistake = y - y_Taylor;
        }
        else {
            cout << "\n/================================ Error ===================================/\n";
            cout << " При X = " << x << ", функция не определена\n";
            continue;
        }
        cout << "\n----------------------------------------------------------------------------\n";
        cout << "При Х = " << x << ":\nФункция = " << y << "\nТейлор = " << y_Taylor << "\nПогрешность = " << mistake << "\n";
    }
}