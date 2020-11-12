#include <iostream>
#include <fstream>
#include <string>

using namespace std;
#ifndef FUNCTIONSFORTI_H
#define FUNCTIONSFORTI_H

string readingFile();
bool poVozr(int* arr, int dlina);
void generateOneTI(int* arr, int dlina);
void writingFile(string str);
void generateAndWritingPerest(int* arr, int dlina);
void fillMas(string str, int* arr);
string createPerest(int nachEl, int* tableInvers, int dlina);
bool isEmpty(int ind, int* arr);
void sdvigToRight(int* arr, int indNach, int dlina);

#endif
