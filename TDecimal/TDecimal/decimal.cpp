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
	TDecimal(unsigned value = 0) : size(0)//конструктор для типа unsigned
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

		do
		{
			val[size++] = value % 10;//записываем меньшую цифру в меньший индекс 
			value /= 10;//отсекаем меньшую цифру
		} while (value);
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

		if (b.size>a.size)//если b длиннее a
			a.size = b.size;//длина массива результата равна длине b

		int c = 0;
		for (int i = 0; i < a.size; ++i)
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
		TDecimal a;
		int c = 0;
		try
		{
			if (Compare(dec) == -1)//если первое число меньше второго
			{
				throw 0;
			}

			a = *this;
			for (int i = 0; i < a.size; ++i)
			{
				c = c + a.val[i] - dec.val[i] + 10;//считаем разность между младшими разрядами числа, добавив 10
				a.val[i] = c % 10;//оставляем нужную нам часть
				if (c <= 9)//если занять 10 из старшего разряда нам было необходимо
					c = -1;//отнимаем единицу из старшего разряда
				else c = 0;//если нет, то все оставляем без изменений
			}

			if (a.size > 1)
				while ((a.val[a.size - 1] == 0) && (a.size > 0))//убираем незначащие нули из результата
					--a.size;

			return a;
		}
		catch (int r)
		{
			cout << "Error! Invalid values!" << endl;
			return r;
		}
	}

	int TDecimal::Compare(const TDecimal& dec)//операция сравнения двух чисел
	{
		int i;

		if (size > dec.size)//если число длиннее, то больше
			return 1;

		else if (size < dec.size)//если число короче, то меньше
			return -1;

		else//если длина чисел одинакова
		{
			i = dec.size - 1;
			while ((val[i] == dec.val[i]) && (i >= 0))//уменьшаем i, пока не встретим первый отличающийся разряд или
													  //не дойдем до конца числа(начинаем со старшего разряда)
			{
				--i;
			}
			if (i == -1)//если мы прошли все разряды, то числа равны
				return 0;
			else if (val[i] > dec.val[i])//если первый встретившийся нам разряд больше, то число больше
				return 1;
			else if (val[i] < dec.val[i])//если первый встретившийся нам разряд меньше, то число меньше
				return -1;
		}
	}

	void TDecimal::Read()//чтение с клавиатуры
	{
		cin >> x;
		TDecimal m(x);
		cout << endl;
		*this = m;
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
	friend ostream& operator << (ostream& os, const TDecimal& digit)//оператор вывода
	{
		for (int i = digit.size - 1; i >= 0; --i)//вывод в обратном порядке
		{
			os << (unsigned)digit.val[i];
		}
		return os;
	}
};
