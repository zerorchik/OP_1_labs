#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

string str;
int len;											// ����� ������

//===================== ������� �������� ������ ======================//
void create() {
	cout << "������� ������: \n";
	// �������� ������� (������ cin >>)
	getline(cin, str);
	// �������� ����� ������
	len = str.length();
}
//============== ������� �������� ������ (��������,.?!) ==============//
void del_space() {
	int slovo;										// ������ ������� �����

	for (int i = 0; i < str.length(); i++) {
		// ���� ������� ���������� c (�������,.?!), ������� ��� � �������� ������� �� 1 ������ �����
		if (str[0] == ' ' || str[0] == ',' || str[0] == '.' || str[0] == '?' || str[0] == '!') {
			// "erase()" - ��� �������� �������� �� �������
			str.erase(0, 1);
			len = str.length();
		}
		// ���� 2 (�������,.?!) �������, ������� ��������� � �������� ������� �� 1 ������ �����
		if ((str[i] == ' ' && str[i + 1] == ' ') || (str[i] == ',' && str[i + 1] == ',') || (str[i] == '.' && str[i + 1] == '.') || (str[i] == '?' && str[i + 1] == '?') || (str[i] == '!' && str[i + 1] == '!') ||
			(str[i] == ' ' && str[i + 1] == ',') || (str[i] == ' ' && str[i + 1] == '.') || (str[i] == ' ' && str[i + 1] == '?') || (str[i] == ' ' && str[i + 1] == '!') ||
			(str[i] == ',' && str[i + 1] == ' ') || (str[i] == ',' && str[i + 1] == '.') || (str[i] == ',' && str[i + 1] == '?') || (str[i] == ',' && str[i + 1] == '!') ||
			(str[i] == '.' && str[i + 1] == ' ') || (str[i] == '.' && str[i + 1] == ',') || (str[i] == '.' && str[i + 1] == '?') || (str[i] == '.' && str[i + 1] == '!') ||
			(str[i] == '?' && str[i + 1] == ' ') || (str[i] == '?' && str[i + 1] == ',') || (str[i] == '?' && str[i + 1] == '.') || (str[i] == '?' && str[i + 1] == '!') ||
			(str[i] == '!' && str[i + 1] == ' ') || (str[i] == '!' && str[i + 1] == ',') || (str[i] == '!' && str[i + 1] == '.') || (str[i] == '!' && str[i + 1] == '?')) {
			str.erase(i, 1);
			i = (i - 1);
			len = str.length();
		}
		// ���� ������� ������������� (��������,), �������
		if (str[len - 1] == ' ' || str[len - 1] == ',') {
			str.erase(len - 1, 1);
			len = str.length();
		}
	}
	cout << "\n\n/======================= �������� ��������� =======================/\n";
	cout << "������� ������ �������: \n" << str << "\n";
}
//================= ������� �������� ���� � 1 ����� ==================//
void del_w() {
	string slen;									// ������ � ������ - ������ ��������
	string s1 = "01";                               // ������ ��� ��������� "1" � slen
	string s2 = "10";                               // ������ ��� ���������� "0" � slen
	int lenth;										// ����� ������, ����� ������� - ������� �������� � ������� ����

	// ���� ������ ����� �� 1 �����, ������� ���
	while (str[1] == ' ') {
		str.erase(0, 2);
		len = str.length();
	}

	for (int i = 0; i < len; i++) {
		// ���� ������� - �� (������,.?!)
		if (str[i] != ' ') {
			slen.append(s1, 1);
			lenth = slen.length();
			if (i > 2) {
				if (lenth >= 3) {
					slen.erase(0, lenth - 3);
				}
				lenth = slen.length();
			}
		}
		// ���� ������� - (������,.?!)
		if (str[i] == ' ' || str[i] == ',' || str[i] == '.' || str[i] == '?' || str[i] == '!') {
			slen.append(s2, 1);
			lenth = slen.length();
			if (i > 2) {
				slen.erase(0, lenth - 3);
				if (slen.compare("010") == 0) {
					str.erase(i - 1, 2);
					i -= 2;

					slen.erase(0);
					slen.append(s2, 1);

					lenth = slen.length();
					len = str.length();
				}
			}
		}
	}
	if (slen.compare("01") == 0) {
		str.erase(len - 1, 2);
		len = str.length();
	}
	cout << "\n������� ����� � 1 �����: \n" << str << "\n";
}
//================= ������� �������� ���������� ���� =================//
void count() {
	int slovo = 0, n = 0;							// ������ ������� ����� � ������� ����

	for (int i = 0; i < len; i++) {
		// ���� ��������� ������� != (������,.?!) � �� ����� ����� �� ���� ����������, ������ ����� ����������
		if ((str[i] != ' ' && slovo == 0) || (str[i] != ',' && slovo == 0) || (str[i] != '.' && slovo == 0) || (str[i] != '?' && slovo == 0) || (str[i] != '!' && slovo == 0)) {
			slovo = 1;
			n++;
		}
		// ���� ���� ������� = (������,.?!), ����� �����������
		else if ((str[i] == ' ') || (str[i] == ',') || (str[i] == '.') || (str[i] == '?') || (str[i] == '!')) {
			slovo = 0;
		}
	}
	cout << "\n���������� ����: " << n << "\n\n";
}

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	create();
	del_space();
	del_w();
	count();
}