/*5. Создать класс Decimal для работы с беззнаковыми целыми десятичными числами,
используя для представления числа массив из 100 элементов типа unsigned char, каждый
из которых является десятичной цифрой.Младшая цифра имеет меньший индекс
(единицы – в нулевом элементе массива).Реальный размер массива задается как
аргумент конструктора инициализации.Реализовать арифметические операции сложения
и вычитания, а также сравнения.*/

#include "stdafx.h"
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
	unsigned char val[SIZE];
	unsigned size;

public:
	TDecimal(unsigned value=0) : size(0)//конструктор для типа unsigned
	{
		*this = value;
	}
	
	TDecimal(const string& value) : size(0)//конструктор для типа string
	{
		*this = value;
	}

	TDecimal& operator = (unsigned value)//оператор присваивания для типа unsigned
	{
		size = 0;

		while (value)
		{
			val[size++] = value % 10;//записываем меньшую цифру в меньший индекс 
			value /= 10;//отсекаем меньшую цифру
		}

		return *this;
	}

	TDecimal& operator = (const string& value)//оператор присваивания для типа string
	{
		size = value.size();
		for (unsigned i = 0; i < size; ++i)
		{
			val[i] = value[size - i - 1] - 48;//заполнение элемента массива, перевод символа в число
		}

		return *this;
	}

	TDecimal operator + (const TDecimal& dec)//оператор сложения 
	{
		TDecimal a, b;
		a = *this;
		b = dec;

		if ((Compare(0) == "=") && (Compare(dec) == "="))//если оба числа равны 0, то результат 0
			return "0";
		
		else if (a.size > b.size)//если a длиннее b 
			for (int i = b.size;i < a.size;i++)//заполняем пустые ячейки b нулями
				b.val[i] = 0;
		
		else//если b длиннее a
		{
			for (int i = a.size ;i < b.size;i++)//заполняем пустые ячейки a нулями
				a.val[i] = 0;
			a.size = b.size;//длина массива результата равна длине b
		}
		
		int c = 0;
		for (int i = 0;i < a.size;++i)
			c = c + a.val[i] + b.val[i],//суммируем последние разряды чисел
			a.val[i] = c % 10,//оставляем нужную нам часть
			c = c / 10;//отсекаем разряд для переноса, если он есть

		if (c>0) {//если в конце осталось число для переноса
			a.val[a.size] = c;//записываем в новый разряд
			a.size++;//увеличиваем размер результата
			
		}
		return a;
	}


	TDecimal operator - (const TDecimal& dec)//оператор вычитания
	{
		TDecimal a, b;
		int c = 0;

		if (Compare(dec) == "=")//если два числа равны, то выводим 0
			return "0";
		
		else if (Compare(dec) == "<")//если первое число меньше второго
		{
			a = dec;
			for (int i = size;i < a.size;i++)//заполняем пустые ячейки меньшего нулями
			val[i] = 0;
			for (int i = 0;i < a.size;++i)
			{
				c = c + a.val[i] - val[i] + 10;//считаем разность между младшими разрядами числа, добавив 10 
				a.val[i] = c % 10;//оставляем нужную нам часть
				if (c <= 9)//если занять 10 из старшего разряда нам было необходимо
					c = -1;//отнимаем единицу из старшего разряда
				else c = 0;//если нет, то все оставляем без изменений
			}
			while ((a.val[a.size-1] == 0) && (a.size>0))//убираем незначащие нули из результата
				--a.size;
			return a;
		}

		else//если второе число меньше первого
		{
			a = *this;
			b = dec;
			for (int i = b.size;i < a.size;i++)//заполняем пустые ячейки меньшего нулями
				b.val[i] = 0;
			for (int i = 0;i < a.size;++i)
			{
				c = c + a.val[i] - b.val[i] + 10;//считаем разность между младшими разрядами числа, добавив 10
				a.val[i] = c % 10;//оставляем нужную нам часть
				if (c <= 9)//если занять 10 из старшего разряда нам было необходимо
					c = -1;//отнимаем единицу из старшего разряда
				else c = 0;//если нет, то все оставляем без изменений
			}
			while ((a.val[a.size - 1] == 0) && (a.size>0))//убираем незначащие нули из результата
				--a.size;
			return a;
		}
	}

	char* TDecimal::Compare (const TDecimal& dec)//операция сравнения двух чисел
	{
		int i;

		if (size > dec.size)//если число длиннее, то больше
			return ">";
		
		else if (size < dec.size)//если число короче, то меньше
			return "<";
		
		else//если длина чисел одинакова
		{
			i = dec.size-1;
			while ((val[i]==dec.val[i]) && (i>=0))//уменьшаем i, пока не встретим первый отличающийся разряд или
												  //не дойдем до конца числа(начинаем со старшего разряда)
			{
				--i;
			}
			 if (i == -1)//если мы прошли все разряды, то числа равны
				return "=";
			else if (val[i] > dec.val[i])//если первый встретившийся нам разряд больше, то число больше
				return ">";
			else if (val[i] < dec.val[i])//если первый встретившийся нам разряд меньше, то число меньше
				return "<";
		}
	}

	friend ostream& operator << (ostream& os, const TDecimal& digit)//оператор вывода
	{
		for (unsigned i = digit.size - 1; i < digit.size; --i)//вывод в обратном порядке
		{
			os << (unsigned)digit.val[i];
		}
		return os;
	}

	void TDecimal::Read(TDecimal& dec)//чтение с клавиатуры
	{
		cout << "A: ";
		cin >> x;
		TDecimal m(x);
		cout << endl;
		cout << "B: ";
		cin >> y;
		TDecimal n(y);
		cout << endl;
		*this = m;
		dec = n;
	}

	void TDecimal::Display(TDecimal& dec)//вывод на экран
	{
		cout << "a: " << *this << ", b: " << (dec) << endl;
	}

	string TDecimal::toString(TDecimal& dec)//преобразование в строку
	{
		stringstream s;
		string str;
		s << "a=" << *this << ";b=" << (dec) << endl;
		s >> str;
		return str;
	}

};

int main()
{
	TDecimal a,b;
	int k;
	do {
		cout << "--Menu:\n"
			<< "1.Read\n"
			<< "2.Display\n"
			<< "3.toString\n"
			<< "4.Summ\n"
			<< "5.Difference\n"
			<< "6.Compare\n"
			<< "0.Exit\n"
			<< "Your choise: ";
		cin >> k;
		switch (k)
		{
			case 1:		a.Read(b);		break;
			case 2:		a.Display(b);	break;
			case 3:		cout << a.toString(b) << endl;	break;
			case 4:		cout << "Summ: " << (a + b) << endl; break;
			case 5:		cout << "Difference: " << (a - b) << endl; break;
			case 6: 
			{
				if ((a.Compare(0) == "=") && (b.Compare(0) == "="))
				cout << "0=0" << endl;
			else cout << a << a.Compare(b) << b << endl; break;
			}
			case 0: cout << "Now exit"; break;
			default:	cout << "error inputing,try again" << endl;
			}
		} while (k != 0);
		return 0;
	}

