#include <iostream>
#include <fstream>
#include <string>
#include "functionsForTI.h"
using namespace std;

int main() {
	int number = stoi(readingFile());
	int* invers = new int[number] {0};
	int* perest = new int[number] {0};
	string allTI{ "" };
	/*for (int i{ 0 }; i < number; ++i) {
		cout << invers[i];
	}
	cout << endl;*/
	//пока наша таблица не будет идти по возрастанию с конца 
	//(что и будет самой последней таблицей инверсии)
	while (!(poVozr(invers, number))) {
		generateOneTI(invers, number);
		for (int i{ 0 }; i < number; ++i) {
			allTI += to_string(invers[i]) + ' ';
		}
		allTI += '\n';
		/*for (int i{ 0 }; i < number; ++i) {
			cout << invers[i];
		}
		cout << endl;*/
	}
	//cout << allTI << endl;
	writingFile(allTI);
	generateAndWritingPerest(perest, number);
}
