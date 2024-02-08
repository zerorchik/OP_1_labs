#include <iostream>
#include <math.h>
using namespace std;

float accuracy;

//================ Функция развития cos в ряд Тейлора ================//
double cos_Taylor(double a) {
    double n = 1.0;     //номер елементу ряду
    double sum = 0.0;
    int i = 1;
    do {
        sum += n;
        n *= -1.0 * a * a / ((2 * i - 1) * (2 * i));
        i++;
    } while (fabs(n) > accuracy);
    return sum;
}

int main() {
    setlocale(LC_ALL, "Rus");

    double x, x1, xn, step, accuracy, y_Taylor = 0;

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
        y_Taylor = cos_Taylor(x);
        cout << "----------------------------------------------------------------------------\n";
        cout << "При Х = " << x << "\nТейлор = " << y_Taylor << "\n";
    }
}