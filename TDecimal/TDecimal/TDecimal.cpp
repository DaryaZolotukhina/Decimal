/*5. ������� ����� Decimal ��� ������ � ������������ ������ ����������� �������,
��������� ��� ������������� ����� ������ �� 100 ��������� ���� unsigned char, ������
�� ������� �������� ���������� ������.������� ����� ����� ������� ������
(������� � � ������� �������� �������).�������� ������ ������� �������� ���
�������� ������������ �������������.����������� �������������� �������� ��������
� ���������, � ����� ���������.*/

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
	unsigned char val[SIZE] = {0};
	unsigned size;

public:
	TDecimal(unsigned value=0) : size(0)//����������� ��� ���� unsigned
	{
		*this = value;
	}
	
	TDecimal(const string& value) : size(0)//����������� ��� ���� string
	{
		*this = value;
	}

	TDecimal& operator = (unsigned value)//�������� ������������ ��� ���� unsigned
	{
		size = 0;

		do
		{
			val[size++] = value % 10;//���������� ������� ����� � ������� ������ 
			value /= 10;//�������� ������� �����
		} while (value);
		return *this;
	}

	TDecimal& operator = (const string& value)//�������� ������������ ��� ���� string
	{
		size = value.size();
		for (unsigned i = 0; i < size; ++i)
		{
			val[i] = value[size - i - 1] - 48;//���������� �������� �������, ������� ������� � �����
		}

		return *this;
	}

	TDecimal operator + (const TDecimal& dec)//�������� �������� 
	{
		TDecimal a, b;
		a = *this;
		b = dec;

		if (b.size>a.size)//���� b ������� a
			a.size = b.size;//����� ������� ���������� ����� ����� b
		
		int c = 0;
		for (int i = 0;i < a.size;++i)
			c = c + a.val[i] + b.val[i],//��������� ��������� ������� �����
			a.val[i] = c % 10,//��������� ������ ��� �����
			c = c / 10;//�������� ������ ��� ��������, ���� �� ����

		if (c>0) {//���� � ����� �������� ����� ��� ��������
			a.val[a.size] = c;//���������� � ����� ������
			a.size++;//����������� ������ ����������
			
		}
		return a;
	}


	TDecimal operator - (const TDecimal& dec)//�������� ���������
	{
		TDecimal a;
		int c = 0;
		try
		{
			if (Compare(dec) == -1)//���� ������ ����� ������ �������
			{
				throw 0;
			}

			a = *this;
			for (int i = 0;i < a.size;++i)
			{
				c = c + a.val[i] - dec.val[i] + 10;//������� �������� ����� �������� ��������� �����, ������� 10
				a.val[i] = c % 10;//��������� ������ ��� �����
				if (c <= 9)//���� ������ 10 �� �������� ������� ��� ���� ����������
					c = -1;//�������� ������� �� �������� �������
				else c = 0;//���� ���, �� ��� ��������� ��� ���������
			}

			if (a.size > 1)
				while ((a.val[a.size - 1] == 0) && (a.size > 0))//������� ���������� ���� �� ����������
					--a.size;

			return a;
		}
		catch(int r)
		{
			cout << "Error! Invalid values!" << endl;
			return r;
		}
	}

	int TDecimal::Compare (const TDecimal& dec)//�������� ��������� ���� �����
	{
		int i;

		if (size > dec.size)//���� ����� �������, �� ������
			return 1;
		
		else if (size < dec.size)//���� ����� ������, �� ������
			return -1;
		
		else//���� ����� ����� ���������
		{
			i = dec.size-1;
			while ((val[i]==dec.val[i]) && (i>=0))//��������� i, ���� �� �������� ������ ������������ ������ ���
												  //�� ������ �� ����� �����(�������� �� �������� �������)
			{
				--i;
			}
			 if (i == -1)//���� �� ������ ��� �������, �� ����� �����
				return 0;
			else if (val[i] > dec.val[i])//���� ������ ������������� ��� ������ ������, �� ����� ������
				return 1;
			else if (val[i] < dec.val[i])//���� ������ ������������� ��� ������ ������, �� ����� ������
				return -1;
		}
	}

	friend ostream& operator << (ostream& os, const TDecimal& digit)//�������� ������
	{
		for (int i = digit.size - 1; i >=0; --i)//����� � �������� �������
		{
			os << (unsigned)digit.val[i];
		}
		return os;
	}

	void TDecimal::Read()//������ � ����������
	{	
		cin >> x;
		TDecimal m(x);
		cout << endl;
		*this = m;
	}

	void TDecimal::Display(TDecimal& dec)//����� �� �����
	{
		cout << "a: " << *this << ", b: " << (dec) << endl;
	}

	string TDecimal::toString(TDecimal& dec)//�������������� � ������
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
			case 1:	
			{
				cout << "A: ";
				a.Read();
				cout << "B: ";
				b.Read();
				break;
			}
			case 2:		a.Display(b);	break;
			case 3:		cout << a.toString(b) << endl;	break;
			case 4:		cout << "Summ: " << (a + b) << endl; break;
			case 5:		cout << "Difference: " << (a - b) << endl; break;
			case 6:		
			{
				char* n;
				if (a.Compare(b) == 1)
					n = ">";
				else if (a.Compare(b) == 0)
					n = "=";
				else n = "<";
				cout << a << n << b << endl; 
				break;
			}
			case 0: cout << "Now exit"; break;
			default:	cout << "error inputing,try again" << endl;
			}
		} while (k != 0);
		return 0;
	}

