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
	unsigned char val[SIZE];
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

		while (value)
		{
			val[size++] = value % 10;//���������� ������� ����� � ������� ������ 
			value /= 10;//�������� ������� �����
		}

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

		if ((Compare(0) == "=") && (Compare(dec) == "="))//���� ��� ����� ����� 0, �� ��������� 0
			return "0";
		
		else if (a.size > b.size)//���� a ������� b 
			for (int i = b.size;i < a.size;i++)//��������� ������ ������ b ������
				b.val[i] = 0;
		
		else//���� b ������� a
		{
			for (int i = a.size ;i < b.size;i++)//��������� ������ ������ a ������
				a.val[i] = 0;
			a.size = b.size;//����� ������� ���������� ����� ����� b
		}
		
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
		TDecimal a, b;
		int c = 0;

		if (Compare(dec) == "=")//���� ��� ����� �����, �� ������� 0
			return "0";
		
		else if (Compare(dec) == "<")//���� ������ ����� ������ �������
		{
			a = dec;
			for (int i = size;i < a.size;i++)//��������� ������ ������ �������� ������
			val[i] = 0;
			for (int i = 0;i < a.size;++i)
			{
				c = c + a.val[i] - val[i] + 10;//������� �������� ����� �������� ��������� �����, ������� 10 
				a.val[i] = c % 10;//��������� ������ ��� �����
				if (c <= 9)//���� ������ 10 �� �������� ������� ��� ���� ����������
					c = -1;//�������� ������� �� �������� �������
				else c = 0;//���� ���, �� ��� ��������� ��� ���������
			}
			while ((a.val[a.size-1] == 0) && (a.size>0))//������� ���������� ���� �� ����������
				--a.size;
			return a;
		}

		else//���� ������ ����� ������ �������
		{
			a = *this;
			b = dec;
			for (int i = b.size;i < a.size;i++)//��������� ������ ������ �������� ������
				b.val[i] = 0;
			for (int i = 0;i < a.size;++i)
			{
				c = c + a.val[i] - b.val[i] + 10;//������� �������� ����� �������� ��������� �����, ������� 10
				a.val[i] = c % 10;//��������� ������ ��� �����
				if (c <= 9)//���� ������ 10 �� �������� ������� ��� ���� ����������
					c = -1;//�������� ������� �� �������� �������
				else c = 0;//���� ���, �� ��� ��������� ��� ���������
			}
			while ((a.val[a.size - 1] == 0) && (a.size>0))//������� ���������� ���� �� ����������
				--a.size;
			return a;
		}
	}

	char* TDecimal::Compare (const TDecimal& dec)//�������� ��������� ���� �����
	{
		int i;

		if (size > dec.size)//���� ����� �������, �� ������
			return ">";
		
		else if (size < dec.size)//���� ����� ������, �� ������
			return "<";
		
		else//���� ����� ����� ���������
		{
			i = dec.size-1;
			while ((val[i]==dec.val[i]) && (i>=0))//��������� i, ���� �� �������� ������ ������������ ������ ���
												  //�� ������ �� ����� �����(�������� �� �������� �������)
			{
				--i;
			}
			 if (i == -1)//���� �� ������ ��� �������, �� ����� �����
				return "=";
			else if (val[i] > dec.val[i])//���� ������ ������������� ��� ������ ������, �� ����� ������
				return ">";
			else if (val[i] < dec.val[i])//���� ������ ������������� ��� ������ ������, �� ����� ������
				return "<";
		}
	}

	friend ostream& operator << (ostream& os, const TDecimal& digit)//�������� ������
	{
		for (unsigned i = digit.size - 1; i < digit.size; --i)//����� � �������� �������
		{
			os << (unsigned)digit.val[i];
		}
		return os;
	}

	void TDecimal::Read(TDecimal& dec)//������ � ����������
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

