#include <iostream>
#include <math.h>
using namespace std;

float accuracy;

//================ ������� �������� cos � ��� ������� ================//
double cos_Taylor(double a) {
    double n = 1.0;     //����� �������� ����
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

    cout << "������� ��������� �������� ������� : ";
    cin >> x1;
    if ((x1 - int(x1)) != 0) {
        cout << "\n/================================ Error ===================================/\n";
        cout << " ��������� �������� �� ������������� �������\n";
        exit(0);
    }

    cout << "������� �������� �������� ������� : ";
    cin >> xn;
    if (xn < x1 || (xn - int(xn)) != 0) {
        cout << "\n/================================ Error ===================================/\n";
        cout << " �������� �������� �� ������������� �������\n";
        exit(0);
    }

    cout << "������� ��� ������� : ";
    cin >> step;
    if (step > (xn - x1)) {
        cout << "\n/================================ Error ===================================/\n";
        cout << " ��� �� ������������� �������\n";
        exit(0);
    }

    cout << "������� �������� �������� ��� ���� ������� : ";
    cin >> accuracy;

    for (x = x1; x <= xn; x += step) {
        y_Taylor = cos_Taylor(x);
        cout << "----------------------------------------------------------------------------\n";
        cout << "��� � = " << x << "\n������ = " << y_Taylor << "\n";
    }
}