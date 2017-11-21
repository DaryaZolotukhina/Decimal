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
using namespace std;

struct MyStruct {//произвольная структура
	char char1;
	char char2;
};

template <typename T>
struct deque {//структура дек

	T val;
	deque *next, *prev;

};

template <typename T>
class Deque {

	deque<T> *Head, *Tail;
	int Count;

public:

	Deque();
	~Deque();

	void DelAll();
	void DelHead();
	void DelTail();

	void AddTail();

	void AddHead();

	void Print();
	
	void Deque<T>::GetHead();
	void Deque<T>::GetTail();
	void Deque<T>::GetSize();

	void Deque<T>::Program();
};

template <typename T>
Deque<T>::Deque()
{
	Head = Tail = 0;
	Count = 0;
}


template <typename T>
Deque<T>::~Deque()
{
	DelAll();
}

template <typename T>
void Deque<T>::AddHead()//добавление элемента в начало
{
	deque<T> * temp = new deque<T>;

	temp->prev = 0;

	T n;//ввод значения
	cout << "Input new elem: " << endl;
	cin >> n;

	temp->val = n;//присваиваем новое значение
	temp->next = Head;//следующий элемент становится головой 

	if (Head!=0)//если уже был головной элемент, то его указатель prev должен ссылаться на вновь созданный элемент
		Head->prev = temp;

	if (Tail == 0)//если хвост пустой, то после добавления нового элемента он должен ссылаться на него
		Tail = temp;

	Head = temp;//голове присваиваем новое значение

	Count++;
}

template <typename T>
void Deque<T>::AddTail()//добавление элемента в конец
{
	deque<T> * temp = new deque<T>;

	temp->next = 0;

	T n;//ввод нового значения
	cout << "Input new elem: "<< endl;
	cin >> n;

	temp->val = n;//присваиваем новое значение
	temp->prev = Tail;//предыдущий элемент становится хвостом

	if (Tail != 0)//если уже был элемент в хвосте, то его указатель next должен ссылаться на вновь созданный элемент
		Tail->next = temp;

	if (Head == 0)//если голова пустая, то после добавления нового элемента она должена ссылаться на него
		Head  = temp;

		Tail = temp;//хвосту присваиваем новое значение

	Count++;
}

template <typename T>
void Deque<T>::DelHead()//удаление элемента с начала
{
	deque<T> * Del = Head;//удаляемый элемент - голова
	deque<T> * AfterDel = Del->next;
	Head = AfterDel;//головой становится следующий за удаляемым элемент
	delete Del;//удаляем

	Count--;
}

template <typename T>
void Deque<T>::DelTail()//удаление элемента с конца
{
	int i = 1;
	deque<T> * Del = Head;//удаляемый элемент - голова

	while (i < Count)// Доходим до элемента, который удаляется
	{
		Del = Del->next;
		i++;
	}

	// Доходим до элемента, который предшествует удаляемому
	deque<T> * PrevDel = Del->prev;
	// Доходим до элемента, который следует за удаляемым
	deque<T> * AfterDel = Del->next;

	if (Count != 1)//если в деке больше одного элемента 
		PrevDel->next = AfterDel;

	Tail = PrevDel;

	delete Del;

	Count--;
}

template <typename T>
void Deque<T>::Print()//печать
{
	cout << "Deque:" << endl;
	if (Count != 0)
	{
		deque<T> * temp = Head;
		while (temp != 0)
		{
			cout<<temp->val<<endl;
			temp = temp->next;
		}
	}
}

template <typename T>
void Deque<T>::GetHead()//полученик элемента с начала
{
	cout << Head->val << "\n";
}

template <typename T>
void Deque<T>::GetTail()//получение элемента с конца
{
	cout << Tail->val << "\n";
}

template <typename T>
void Deque<T>::GetSize()//размер
{
	cout << "Size" << endl;
	cout << Count << "\n";
}

template <typename T>
void Deque<T>::DelAll()//удалить все
{
	while (Count != 0)
		DelHead();
}


template <typename T>
void Deque<T>::Program()//меню
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
		case 1: GetSize(); break;
		case 2: AddTail(); break;
		case 3: AddHead(); break;
		case 4: DelHead(); break;
		case 5: DelTail(); break;
		case 6: GetHead(); break;
		case 7: GetTail(); break;
		case 8: Print(); break;
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
	case 1: A.Program();break;
	case 2: B.Program();break;
	case 3: C.Program();break;
	}
}
