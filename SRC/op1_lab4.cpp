#include <iostream>
using namespace std;

int main() {
	setlocale(LC_CTYPE, "Rus");
	int n1, nz, c = 0, k, s = 0;
	float n, m;

	cout << "������� N - ���������� �����\nN = ";
	cin >> n;
	if (n <= 0 || (n - int(n)) != 0) {
		cout << "\n----------------------------\nN - �� ������������� �������\n----------------------------\n";
		return 0;
	}
	n1 = n;
	nz = n;
	k = n;
	for (; k > 0; c++) {
		k /= 10;
	}

	cout << "\n������� M - ���������� ��������� ������ ����� N, M <= " << c << "\nM = ";
	cin >> m;
	if (m <= 0 || m > c || (m - int(m)) != 0) {
		cout << "\n----------------------------\nM - �� ������������� �������\n----------------------------\n";
		return 0;
	}

	for (int i = 1; i <= m; i++) {
		s += nz % 10;
		nz /= 10;
	}
	cout << "\n����� " << m << " ��������� ���� ����� " << n1 << " = " << s << "\n";
}