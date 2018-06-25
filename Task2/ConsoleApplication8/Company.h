/* 6 ���������� � ���������� ������������ ������� � ������: ��������� �����, ����� ������, �������,
�����, ���� ���������� �� ������, ������� ��������, ���������� �����, ���������� ������������ ���� � ������,
���������� ������� ���� � �����, ���������, ��������. ����� �� ������ ������, �������, ���� ����������� � ������.*/
#pragma once
#include <stdio.h>
#include <sstream>
#include <math.h>
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

class Worker {
public:
	// ��������� �����
	int pers_number;
	// ����� ������
	int depart_number;
	// �������
	string surname;
	// �����
	int salary;
	// ���� �����������
	MyDate date;
	// ������� ��������
	int percent;
	// ���������� �����
	int tax;
	// ���������� ������������ ����
	int days_worked;
	// ���������� ���� � ������
	int days_month;
	// ���������
	int accured;
	// ��������
	int withheld;


	// ����������� �� ���������
	Worker();


	// ��������� ��������� "��������"
	Worker ChangeWorker(Worker &result);

	// ������������� �������� ��������� ��� ��������� "��������"
	Worker& operator = (Worker c);
};



