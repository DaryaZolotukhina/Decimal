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

	// �������� ��������
	void Remove(int numb);
	
	// ���������� ��������
	void Add(Type &elem);

	//������ �������
	int size();

	// �������� �� �������
	bool Is_empty();

	// �������� �����
	// bool(*Equal)(Type, Type) - ��������� �� �������, ������� ��������� ��������� �������� ��-�� � �������
	vector<Type> LinearySearch(Type search_elem, bool(*Equal)(Type, Type));
	// �������� �����
	// int(*Compare)(Type, Type) - ��������� �� �������, ������� ���������� ������� ��-� � �������
	// bool(*Equal)(Type, Type) - ��������� �� �������, ������� ��������� ��������� �������� ��-�� � �������
	vector<Type> BinarySearch(Type find_element, bool(*Compare)(Type, Type), bool(*Equal)(Type, Type));
	vector<Type> Sort(bool(*Compare)(Type, Type));
	// ����� � ����
	// void(*f) (Type) - ��������� �� �������, ������� ���������� ���� ��������� � ����  
	void OutputFile(vector<Type> items, void(*f)(Type, ofstream&), string newfname);
	// ����� �� �����
	void OutputScreen(vector<Type> items, void(*f)(Type), void(*Header)());
	// ���� �� �����
	// Type(*f)(ifstream&) - ��������� �� �������, ������� ��������� ���� ��������� �� ����� 
	void ReadFromFile(Type(*f)(ifstream&), string newfname);
	// ���� � ������
	//Type(*f)() - ��������� �� �������, ������� ������ ���� ��������� � �������
	void ReadFromScreen(Type(*f)());
	vector<int> SumSalary(int type);
	void OutputScreenSalary(vector<int> items);
};


