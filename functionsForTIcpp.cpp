#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string readingFile() {
	ifstream file("input.txt");
	string str{ "" };
	while (!file.eof()) {
		getline(file, str);
	}
	file.close();
	return str;
}

bool poVozr(int* arr, int dlina) {
	for (int i{ dlina - 1 }; i > 0; --i) {
		if (arr[i] >= arr[i - 1]) {
			return false;
		}
	}
	return true;
}

void generateOneTI(int* arr, int dlina) {
	int ind = dlina - 1;
	bool notMax = true;

	while (notMax) {
		int ch = arr[ind] + 1;
		if (ch > dlina - 1 - ind) {
			arr[ind] = 0;
			ind = ind - 1;
		}
		else {
			arr[ind] = ch;
			notMax = false;
		}
	}
}

void writingFile(string str) {
	ofstream file("inversii.txt");
	file << str;
	file.close();
}

void generateAndWritingPerest(int* arr, int dlina) {
	ifstream file1("inversii.txt");
	//очистка файла
	ofstream file2("perestanovki.txt", ios::out | ios::trunc);
	file2.close();
	//открытие файла для записи в конец
	ofstream file3("perestanovki.txt", ios::app);

	string str{ "" };
	while (!file1.eof()) {
		getline(file1, str);

		fillMas(str, arr);
		/*for (int i{0}; i < 4; ++i) {
			cout << arr[i] << " ";
		}
		cout << endl;*/

		string curPerest = createPerest(dlina, arr, dlina);
		//cout << curPerest << endl;
		file3 << curPerest << '\n';
	}
	file1.close();
	file3.close();
}
//заполнение массива, даже с учетом того, что в строке могут быть не
//однозначные числа
void fillMas(string str, int* arr) {
	int lenght = str.size(), ind{ 0 };

	for (int i{ 0 }; i < lenght;) {
		int ind2{ i }, step{ 1 }, step2{ 0 };
		string subStr{ "" };
		bool space{ true };

		while (str[ind2] != ' ') {
			++step2;
			step = step2;

			subStr += str[ind2];
			++ind2;
			space = false;
		}

		if (!space) {
			arr[ind] = stoi(subStr.c_str());
			++ind;
		}

		i += step;
	}
}
//создание перестановки по таблице инверсий
string createPerest(int nachEl, int* tableInvers, int dlina) {
	string perestStroka{ "" };
	int* perest = new int[dlina] {0};

	for (int i{ dlina - 1 }; i >= 0; --i) {
		int indVstavka = tableInvers[i];
		//если место не пустое, то надо сдвинуть елементы, а потом вставить
		if (!isEmpty(indVstavka, perest)) {
			sdvigToRight(perest, indVstavka, dlina);
		}
		perest[indVstavka] = nachEl;
		--nachEl;
	}
	for (int i{ 0 }; i < dlina; ++i) {
		perestStroka += to_string(perest[i]) + ' ';
	}
	return perestStroka;
}

bool isEmpty(int ind, int* arr) {
	if (arr[ind] != 0) {
		return false;
	}
	return true;
}

void sdvigToRight(int* arr, int indNach, int dlina) {
	for (int i{ dlina - 1 }; i > indNach; --i) {
		arr[i] = arr[i - 1];
	}
}