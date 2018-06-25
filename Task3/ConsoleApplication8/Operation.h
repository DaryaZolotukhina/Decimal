#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <conio.h>
#include <sstream>
#include <math.h>
#include <iostream>
#include <string>
#include <iomanip>
#include "Company.h"
#include "HelpUtils.h"
using namespace std;


template <class Type>
class Task {
public:
	vector<Type> vect;
	Task();
	~Task();

	// удаление элемента
	void Remove(int numb);
	
	// добавление элемента
	void Add(Type &elem);

	//размер вектора
	int size();

	// проверка на пустоту
	bool Is_empty();

	// линейный поиск
	// bool(*Equal)(Type, Type) - указатель на функцию, которая проверяет равенство искомого эл-та с текущим
	vector<Type> LinearySearch(Type search_elem, bool(*Equal)(Type, Type));
	// бинарный поиск
	// int(*Compare)(Type, Type) - указатель на функцию, которая сравнивает искомый эл-т с текущим
	// bool(*Equal)(Type, Type) - указатель на функцию, которая проверяет равенство искомого эл-та с текущим
	vector<Type> BinarySearch(Type find_element, bool(*Compare)(Type, Type), bool(*Equal)(Type, Type));
	vector<Type> Sort(bool(*Compare)(Type, Type));
	// вывод в файл
	// void(*f) (Type) - указатель на функцию, которая записывает одну структуру в файл  
	void OutputFile(vector<Type> items, void(*f)(Type, ofstream&), string newfname);
	// вывод на экран
	void OutputScreen(vector<Type> items, void(*f)(Type), void(*Header)());
	// ввод из файла
	// Type(*f)(ifstream&) - указатель на функцию, которая считывает одну структуру из файла 
	void ReadFromFile(Type(*f)(ifstream&), string newfname);
	// ввод с экрана
	//Type(*f)() - указатель на функцию, которая вводит одну структуру с консоли
	void ReadFromScreen(Type(*f)());
	vector<int> SumSalary(int type);
	void OutputScreenSalary(vector<int> items);
};


