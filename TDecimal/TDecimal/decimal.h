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
	TDecimal(unsigned value=0);//конструктор для типа unsigned

	TDecimal(const string& value);//конструктор для типа string

	TDecimal& operator = (unsigned value);//оператор присваивания для типа unsigned

	TDecimal& operator = (const string& value);//оператор присваивания для типа string

	TDecimal operator + (const TDecimal& dec);//оператор сложения 

	TDecimal operator - (const TDecimal& dec);//оператор вычитания
	
	friend ostream& operator << (ostream& os, const TDecimal& digit);//оператор вывода
	
	int TDecimal::Compare(const TDecimal& dec);//операция сравнения двух чисел

	void TDecimal::Read();//чтение с клавиатуры

	void TDecimal::Display(TDecimal& dec);//вывод на экран

	string TDecimal::toString(TDecimal& dec);//преобразование в строку

};