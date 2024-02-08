#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

string str;
int len;											// длина строки

//===================== Функция создания строки ======================//
void create() {
	cout << "Введите строку: \n";
	// получаем строчку (аналог cin >>)
	getline(cin, str);
	// измеряем длину строки
	len = str.length();
}
//============== Функция удаления лишних (пробелов,.?!) ==============//
void del_space() {
	int slovo;										// маркер наличия слова

	for (int i = 0; i < str.length(); i++) {
		// если строчка начинается c (пробела,.?!), убираем его и сдвигаем строчку на 1 символ влево
		if (str[0] == ' ' || str[0] == ',' || str[0] == '.' || str[0] == '?' || str[0] == '!') {
			// "erase()" - для удаления символов со строчки
			str.erase(0, 1);
			len = str.length();
		}
		// если 2 (пробела,.?!) плодряд, убираем последний и сдвигаем строчку на 1 символ влево
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
		// если строчка заканчивается (пробелом,), убираем
		if (str[len - 1] == ' ' || str[len - 1] == ',') {
			str.erase(len - 1, 1);
			len = str.length();
		}
	}
	cout << "\n\n/======================= КОНЕЧНЫЙ РЕЗУЛЬТАТ =======================/\n";
	cout << "УДАЛЕНЫ ЛИШНИЕ ПРОБЕЛЫ: \n" << str << "\n";
}
//================= Функция удаления слов с 1 буквы ==================//
void del_w() {
	string slen;									// строка и массив - маркер пробелов
	string s1 = "01";                               // массив для добаления "1" в slen
	string s2 = "10";                               // массив для добавления "0" в slen
	int lenth;										// длина строки, длина массива - маркера пробелов и счётчик слов

	// пока первое слово из 1 буквы, убираем его
	while (str[1] == ' ') {
		str.erase(0, 2);
		len = str.length();
	}

	for (int i = 0; i < len; i++) {
		// если элемент - НЕ (пробел,.?!)
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
		// если элемент - (пробел,.?!)
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
	cout << "\nУДАЛЕНЫ СЛОВА С 1 БУКВЫ: \n" << str << "\n";
}
//================= Функция подсчёта количества слов =================//
void count() {
	int slovo = 0, n = 0;							// маркер наличия слова и счётчик слов

	for (int i = 0; i < len; i++) {
		// если следующий элемент != (пробел,.?!) и до этого слово не было обнаружено, теперь слово обнаружено
		if ((str[i] != ' ' && slovo == 0) || (str[i] != ',' && slovo == 0) || (str[i] != '.' && slovo == 0) || (str[i] != '?' && slovo == 0) || (str[i] != '!' && slovo == 0)) {
			slovo = 1;
			n++;
		}
		// если след элемент = (пробел,.?!), слово закончилось
		else if ((str[i] == ' ') || (str[i] == ',') || (str[i] == '.') || (str[i] == '?') || (str[i] == '!')) {
			slovo = 0;
		}
	}
	cout << "\nКОЛИЧЕСТВО СЛОВ: " << n << "\n\n";
}

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	create();
	del_space();
	del_w();
	count();
}