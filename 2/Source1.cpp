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
	cout << "Введите число" << endl;
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
		cout << "Вектора равны" << endl;
	else
		cout << "Вектора не равны" << endl;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	while (x == 0)
	{
		cout << "Выбирите действие" << endl;
		cout << "1 - Сложение векторов" << endl;
		cout << "2 - Умножение векторов на число" << endl;
		cout << "3 - Скалярное произведение векторов" << endl;
		cout << "4 - Векторное произведение векторов" << endl;
		cout << "5 - Вычисление модуля векторов" << endl;
		cout << "6 - Проверка векторов на равенство" << endl;
		cout << "7 - Выход из программы" << endl;
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
			cout << "Ошибка" << endl;
		}
		}
	}
	system("Pause");
}
