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

#include "Decimal.cpp"

using namespace std;

int main()
{
	TDecimal a, b;
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