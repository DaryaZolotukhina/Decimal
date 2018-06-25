#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
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

	// ���� �� �����
	// Type(*f)(ifstream&) - ��������� �� �������, ������� ��������� ���� ��������� �� ����� 
	bool ReadFromFile(Type(*f)(ifstream&));

	// ���� � ������
	//Type(*f)() - ��������� �� �������, ������� ������ ���� ��������� � �������
	void ReadFromScreen(Type(*f)());

	// �������� �����
	// bool(*Equal)(Type, Type) - ��������� �� �������, ������� ��������� ��������� �������� ��-�� � �������
	vector<Type> LinearySearch(Type search_elem, bool(*Equal)(Type, Type));

	// �������� �����
	// int(*Compare)(Type, Type) - ��������� �� �������, ������� ���������� ������� ��-� � �������
	// bool(*Equal)(Type, Type) - ��������� �� �������, ������� ��������� ��������� �������� ��-�� � �������
	vector<Type> BinarySearch(Type find_element, bool(*Compare)(Type, Type), bool(*Equal)(Type, Type));
};


