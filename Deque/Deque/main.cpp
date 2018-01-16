/*5. Реализовать шаблон класса дек (Deque<X>), хранящий элементы произвольного типа.
Класс должен в обязательном порядке содержать методы:
Вычисление длины дека;
Добавление нового элемента в конец;
Добавление нового элемента в начало;
Удаление элемента с начала;
Удаление элемента с конца;
Получение элемента с начала;
Получение элемента с конца;
Печать.
b) Реализация дека с помощью списка.*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include "Deque.cpp"


using namespace std;

struct MyStruct {//произвольная структура
	char char1;
	char char2;
};

template <typename T>
void Program(Deque<T> A)//меню
{
	int k;
	do {
		cout << "--Menu:\n"
			<< "1.Get size\n"
			<< "2.Add tail\n"
			<< "3.Add head\n"
			<< "4.Delete head\n"
			<< "5.Delete tail\n"
			<< "6.Get head\n"
			<< "7.Get tail\n"
			<< "8.Print\n"
			<< "0.Exit\n"
			<< "Your choise: ";
		cin >> k;
		switch (k)
		{
		case 1: {
			cout << "Size" << endl;
			cout << A.GetSize() << "\n";
		} break;
		case 2: {
			T n;//ввод значения
			cout << "Input new elem: " << endl;
			cin >> n;
			A.AddTail(n);
		} break;
		case 3: {
			T n;//ввод значения
			cout << "Input new elem: " << endl;
			cin >> n;
			A.AddHead(n);
		} break;
		case 4: A.DelHead(); break;
		case 5: A.DelTail(); break;
		case 6: {
			try {
				cout << A.GetHead() << endl;
			}
			catch (...) {
				cout << "Deque is empty" << endl;
			}
			} break;
		case 7: {
			try {
				cout << A.GetTail() << endl;
			}
			catch (...) {
				cout << "Deque is empty" << endl;
			}
			} break;
		case 8: A.Print(); break;
		case 0: cout << "Now exit"; break;
		default:	cout << "error inputing,try again" << endl;
		}
	} while (k != 0);
}

ostream& operator<<(ostream& os, const  MyStruct& a)//вывод для струтктуры
{
	os << a.char1 << " " << a.char2 << endl;
	return os;
}

istream& operator>>(istream& is, MyStruct& a)//ввод для структуры
{
	cout << "Input char1:" << endl;
	is >> a.char1;
	cout << "Input char2:" << endl;
	is >> a.char2;
	return is;
}

int main() {
	Deque <MyStruct> C;
	Deque <int> A;
	Deque <string> B;
	int k;
	cout << "Select data type: 1 - int, 2 - string, 3 - MyStruct"<<endl;
	cin >> k;
	switch (k)
	{
	case 1: Program(A);break;
	case 2: Program(B);break;
	case 3: Program(C);break;
	}
}
