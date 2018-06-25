#pragma once
#include <string>
#include <iostream>
#include <string>
#include "HelpUtils.h"
//using namespace std;

//������ ����
class MyDate {

	// �������� �������� �� ��� ����������
	bool IsLeap(int year);

	// �������� ���� �� ������������
	bool CorrectDate(int day, int month, int year, string &message);
public:
	// ����
	int day;
	// �����
	int month;
	// ���
	int year;

	// ����������� �� ���������
	MyDate();

	// ���� ���� � �������
	void InputDate();

	// ������� ���� � ������ (��� ����������� ������ � ����)
	string ToString();

	//���������� ��������� "����" �� ������ 
	// ������:
	// ���� ����� ���
	MyDate FromString(string str);

	// ������������� �������� ���������
	bool operator == (const MyDate &c);

	// ����������� �����������
	MyDate& operator = (MyDate c);

	// ������������� �������� ������
	bool operator > (const MyDate &c);

	// ������������� �������� ������
	bool operator < (const MyDate &c);

};