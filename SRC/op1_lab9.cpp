#include <iostream>
#include <windows.h>
#include <fstream>
#include <stdio.h>
#include <string>

using namespace std;

string str, a[20], res[20], name;						// ������ �����, ������ �����, ������ ��� ���������� ����������, ��� �����
int n = 0, ns = 0, i = 0;								// ��������� ����, ���������� �����, ������� �����
fstream F;												// ����

//================== ������� ������ ����� � ������ ===================//
void read_file() {
	const char endl = '\n';                             // ������ ��� �������� ������

	cout << "������� ��� �����: ";
	cin >> name;

	// ��������� ���� � ������ ������
	F.open(name + ".TXT");
	// ���� ����� ���� ����������
	if (F) {
		// ���� ������ �����
		while (!F.eof()) {
			getline(F, str, endl);                      // ������� �������
			ns++;										// ������� ����� ++
			a[i] = str;									// ��������� �������� ������� ������
			i++;										// ������� ����� ++
		}
		F.close();
		// ����� ������� �����
		cout << "\n���� '" << name << ".TXT'\n------------------------\n";
		for (i = 0; i < ns; i++) {
			cout << "str[" << i + 1 << "] = " << a[i] << "\n";
		}
		cout << "\n";
	}
	// ���� ������ ����� ���
	else {
		cout << "\n����� '" << name << ".TXT' - �� ����������\n";
		exit(0);
	}
}
//====== ������� ����������� ����������� ����� � ������ ������� ======//
void short_word() {
	string temp = "";									// ������ ��� �������� ����
	string min = str;									// �������� ������������ �������� �������� ��������� ������ �����
	// ���� ��� ����������� ����������� ����� � ������ �������
	for (i = 0; i <= ns - 1; i++) {
		min = str;
		temp = "";
		for (int k = 0; k < a[i].length(); k++) {
			// ���� ���� ������ != ������, ������������ �����
			if (a[i][k] != ' ') {
				temp += a[i][k];
			}
			else {
				// ���� ������
				temp += a[i][k];
				// ���� ���������� ��� �����
				if (temp.length() < min.length()) {
					min = temp;
					res[i] = min;
					temp = "";
				}
				else if (temp.length() == min.length()) {
				    min = temp;
					res[i] += min;
					temp = "";
				}
				temp = "";
			}
		}
		// �������� ���������� �����
		if (temp != "") {
			if (temp.length() + 1 < min.length()) {
				min = temp;
				temp = "";
				res[i] = min;
			}
			else if (temp.length() + 1 == min.length()) {
				min = temp;
				temp = "";
				res[i] += min;
			}
		}
	}
}
//================= ������� �������� ���������� ���� =================//
void count() {
	int slovo = 0;										// ������ ������� ����� � ������� ����

	for (i = 0; i < ns; i++) {
		for (int k = 0; k < res[i].length(); k++) {
			// ���� ��������� ������� != ������ � �� ����� ����� �� ���� ����������, ������ ����� ����������
			if (res[i][k] != ' ' && slovo == 0) {
				slovo = 1;
				n++;
			}
			// ���� ���� ������� = ������, ����� �����������
			else if ((res[i][k] == ' ')) {
				slovo = 0;
			}
		}
	}
}
//=================== ������� ������ ������ � ���� ===================//
void save() {
	name = "shrt_" + name + ".TXT";
	name.c_str();

	ofstream file(name);
	if (file) {
		cout << "\n���� '" << name << "' - ��� ������� ������\n\n";
		cout << "\n/====== ��������� ======/\n";
		cout << "��� ���� '" << name << "'\n------------------------\n";
		for (i = 0; i < ns; i++) {
			file << res[i] << endl;
			cout << "a[" << i + 1 << "] = " << res[i] << "\n";
		}
		file << "\n���������� ����: " << n;
		cout << "a[" << ns + 1 << "] = \na[" << ns + 2 << "] = ���������� ���� : " << n << "\n\n";
		file.close();
	}
	else {
		cout << "\n���� '" << name << "' - �� ��� ������\n";
	}
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	read_file();
	short_word();
	count();
	save();
}