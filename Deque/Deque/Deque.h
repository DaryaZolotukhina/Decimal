#pragma once
using namespace std;

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

	void AddTail(T n);

	void AddHead(T n);

	void Print();

	T Deque<T>::GetHead();
	T Deque<T>::GetTail();
	int Deque<T>::GetSize();
};