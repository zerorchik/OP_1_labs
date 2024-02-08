#include <iostream>
#include <math.h>
using namespace std;

float accuracy;

//================ ������� �������� cos � ��� ������� ================//
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
    cout << "������� ���������� ��� ��������� � > -1, ����������� � ����� 0.5\n\n";
    cout << "    cos(x/2) / cos(x^2)   ,   -1<=x<=0\n";
    cout << "y = \n";
    cout << "    cos^2(x/2) * cos(2x)  ,   x>0\n";
    cout << "----------------------------------------------------------------------------\n\n";

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
            cout << " ��� X = " << x << ", ������� �� ����������\n";
            continue;
        }
        cout << "\n----------------------------------------------------------------------------\n";
        cout << "��� � = " << x << ":\n������� = " << y << "\n������ = " << y_Taylor << "\n����������� = " << mistake << "\n";
    }
}