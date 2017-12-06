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
struct List {//структура дек

	T val;
	List *next, *prev;

};

template <typename T>
class Deque {

	List<T> *Head, *Tail;
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
};

template <typename T>
Deque<T>::Deque()
{
	Head = Tail = nullptr;
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
	List<T> * temp = new List<T>;

	temp->prev = nullptr;

	T n;//ввод значения
	cout << "Input new elem: " << endl;
	cin >> n;

	temp->val = n;//присваиваем новое значение
	temp->next = Head;//следующий элемент становится головой 

	if (Head!= nullptr)//если уже был головной элемент, то его указатель prev должен ссылаться на вновь созданный элемент
		Head->prev = temp;

	if (Tail == nullptr)//если хвост пустой, то после добавления нового элемента он должен ссылаться на него
		Tail = temp;

	Head = temp;//голове присваиваем новое значение

	Count++;
}

template <typename T>
void Deque<T>::AddTail()//добавление элемента в конец
{
	List<T> * temp = new List<T>;

	temp->next = nullptr;

	T n;//ввод нового значения
	cout << "Input new elem: "<< endl;
	cin >> n;

	temp->val = n;//присваиваем новое значение
	temp->prev = Tail;//предыдущий элемент становится хвостом

	if (Tail != nullptr)//если уже был элемент в хвосте, то его указатель next должен ссылаться на вновь созданный элемент
		Tail->next = temp;

	if (Head == nullptr)//если голова пустая, то после добавления нового элемента она должена ссылаться на него
		Head  = temp;

		Tail = temp;//хвосту присваиваем новое значение

	Count++;
}

template <typename T>
void Deque<T>::DelHead()//удаление элемента с начала
{
	List<T> * Del = Head;//удаляемый элемент - голова
	List<T> * AfterDel = Del->next;
	Head = AfterDel;//головой становится следующий за удаляемым элемент
	delete Del;//удаляем
	if (Count == 1)
		Tail = nullptr;

	Count--;
}

template <typename T>
void Deque<T>::DelTail()//удаление элемента с конца
{
	int i = 1;
	List<T> * Del = Head;//удаляемый элемент - голова

	while (i < Count)// Доходим до элемента, который удаляется
	{
		Del = Del->next;
		i++;
	}

	// Доходим до элемента, который предшествует удаляемому
	List<T> * PrevDel = Del->prev;
	// Доходим до элемента, который следует за удаляемым
	List<T> * AfterDel = Del->next;

	if (Count != 1)//если в деке больше одного элемента 
		PrevDel->next = AfterDel;

	Tail = PrevDel;

	delete Del;

	if (Count == 1)
		Head = nullptr;

	Count--;
}

template <typename T>
void Deque<T>::Print()//печать
{
	cout << "Deque:" << endl;
	if (Count != 0)
	{
		List<T> * temp = Head;
		while (temp != nullptr)
		{
			cout<<temp->val<<endl;
			temp = temp->next;
		}
	}
	else cout << "Deque is empty" << "\n";
}

template <typename T>
void Deque<T>::GetHead()//полученик элемента с начала
{
	if (Count==0)
		cout<<"Deque is empty"<< "\n";
	else cout << Head->val << "\n";
}

template <typename T>
void Deque<T>::GetTail()//получение элемента с конца
{
	if (Count == 0)
		cout << "Deque is empty" << "\n";
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
void Program(T A)//меню
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
		case 1: A.GetSize(); break;
		case 2: A.AddTail(); break;
		case 3: A.AddHead(); break;
		case 4: A.DelHead(); break;
		case 5: A.DelTail(); break;
		case 6: A.GetHead(); break;
		case 7: A.GetTail(); break;
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
