#include <iostream>
#include <windows.h>
#include <fstream>
#include <math.h>
#include <conio.h>
#include <cstdlib>
using namespace std;
ifstream open("test.txt");
float a, b, c, d, e, f, l, x = 0;

void fun1() {
	open >> a >> b >> c >> d >> e >> f;
	cout << a + d << " " << b + e << " " << c + f << endl;
}
void fun2() {
	cout << "������� �����" << endl;
	cin >> l;
	open >> a >> b >> c >> d >> e >> f;
	cout << l * a << " " << l * b << " " << l * c << endl << l * d << " " << l * e << " " << l * f << endl;
}
void fun3() {
	open >> a >> b >> c >> d >> e >> f;
	cout << a * d + b * e + c * f << endl;
}
void fun4() {
	open >> a >> b >> c >> d >> e >> f;
	cout << b * f - e * c << " " << -( a * f - d * c) << " " << a * e - d * b << " " << endl;
}
void fun5() {
	open >> a >> b >> c >> d >> e >> f;
	cout << sqrt(a * a + b * b + c * c) << endl << sqrt(d * d + e * e + f * f) << endl;
}
void fun6() {
	open >> a >> b >> c >> d >> e >> f;
	if (a == d && b == e && c == f)
		cout << "������� �����" << endl;
	else
		cout << "������� �� �����" << endl;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	while (x == 0)
	{
		cout << "�������� ��������" << endl;
		cout << "1 - �������� ��������" << endl;
		cout << "2 - ��������� �������� �� �����" << endl;
		cout << "3 - ��������� ������������ ��������" << endl;
		cout << "4 - ��������� ������������ ��������" << endl;
		cout << "5 - ���������� ������ ��������" << endl;
		cout << "6 - �������� �������� �� ���������" << endl;
		cout << "7 - ����� �� ���������" << endl;
		int s;
		cin >> s;
		switch (s)
		{
		case 1:
		{
			fun1();
			break;
		}
		case 2:
		{
			fun2();
			break;
		}
		case 3:
		{
			fun3();
			break;
		}
		case 4:
		{
			fun4();
			break;
		}
		case 5:
		{
			fun5();
			break;
		}
		case 6:
		{
			fun6();
			break;
		}
		case 7:
		{
			exit(0);
			break;
		}
		default:
		{
			cout << "������" << endl;
		}
		}
	}
	system("Pause");
}
