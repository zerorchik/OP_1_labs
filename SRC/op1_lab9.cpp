#include <iostream>
#include <windows.h>
#include <fstream>
#include <stdio.h>
#include <string>

using namespace std;

string str, a[20], res[20], name;						// строка файла, массив файла, массив для результата сортировки, имя файла
int n = 0, ns = 0, i = 0;								// количесво слов, количество строк, счетчик цикла
fstream F;												// файл

//================== Функция чтения файла в строку ===================//
void read_file() {
	const char endl = '\n';                             // маркер для переноса строки

	cout << "Введите имя файла: ";
	cin >> name;

	// открываем файл в режиме чтения
	F.open(name + ".TXT");
	// если такой файл существует
	if (F) {
		// цикл чтения строк
		while (!F.eof()) {
			getline(F, str, endl);                      // считать строчку
			ns++;										// счётчик строк ++
			a[i] = str;									// присвоить элементу массива строку
			i++;										// счётчик цикла ++
		}
		F.close();
		// вывод массива строк
		cout << "\nФайл '" << name << ".TXT'\n------------------------\n";
		for (i = 0; i < ns; i++) {
			cout << "str[" << i + 1 << "] = " << a[i] << "\n";
		}
		cout << "\n";
	}
	// если такого файла нет
	else {
		cout << "\nФайла '" << name << ".TXT' - не существует\n";
		exit(0);
	}
}
//====== Функция определения наименьшего слова в каждой строчке ======//
void short_word() {
	string temp = "";									// строка для хранения слов
	string min = str;									// присвоим минимальному значению значение последней строки файла
	// цикл для определения наименьшего слова в каждой строчке
	for (i = 0; i <= ns - 1; i++) {
		min = str;
		temp = "";
		for (int k = 0; k < a[i].length(); k++) {
			// если след символ != пробел, перезаписать букву
			if (a[i][k] != ' ') {
				temp += a[i][k];
			}
			else {
				// если пробел
				temp += a[i][k];
				// если обнаружено мин слово
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
		// проверка последнего слова
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
//================= Функция подсчёта количества слов =================//
void count() {
	int slovo = 0;										// маркер наличия слова и счётчик слов

	for (i = 0; i < ns; i++) {
		for (int k = 0; k < res[i].length(); k++) {
			// если следующий элемент != пробел и до этого слово не было обнаружено, теперь слово обнаружено
			if (res[i][k] != ' ' && slovo == 0) {
				slovo = 1;
				n++;
			}
			// если след элемент = пробел, слово закончилось
			else if ((res[i][k] == ' ')) {
				slovo = 0;
			}
		}
	}
}
//=================== Функция записи масива в файл ===================//
void save() {
	name = "shrt_" + name + ".TXT";
	name.c_str();

	ofstream file(name);
	if (file) {
		cout << "\nФайл '" << name << "' - был успешно создан\n\n";
		cout << "\n/====== РЕЗУЛЬТАТ ======/\n";
		cout << "Мин файл '" << name << "'\n------------------------\n";
		for (i = 0; i < ns; i++) {
			file << res[i] << endl;
			cout << "a[" << i + 1 << "] = " << res[i] << "\n";
		}
		file << "\nКоличество слов: " << n;
		cout << "a[" << ns + 1 << "] = \na[" << ns + 2 << "] = Количество слов : " << n << "\n\n";
		file.close();
	}
	else {
		cout << "\nФайл '" << name << "' - не был создан\n";
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