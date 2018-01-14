#pragma once
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class TDecimal
{
private:
	string x, y;
public:
	enum { SIZE = 100 };

protected:
	unsigned char val[SIZE] = { 0 };
	unsigned size;

public:
	TDecimal(unsigned value=0);//����������� ��� ���� unsigned

	TDecimal(const string& value);//����������� ��� ���� string

	TDecimal& operator = (unsigned value);//�������� ������������ ��� ���� unsigned

	TDecimal& operator = (const string& value);//�������� ������������ ��� ���� string

	TDecimal operator + (const TDecimal& dec);//�������� �������� 

	TDecimal operator - (const TDecimal& dec);//�������� ���������
	
	friend ostream& operator << (ostream& os, const TDecimal& digit);//�������� ������
	
	int TDecimal::Compare(const TDecimal& dec);//�������� ��������� ���� �����

	void TDecimal::Read();//������ � ����������

	void TDecimal::Display(TDecimal& dec);//����� �� �����

	string TDecimal::toString(TDecimal& dec);//�������������� � ������

};