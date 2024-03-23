#include <iostream>
#include <windows.h>
#include <fstream>
#include <math.h>
#include <string>
#include <vector>
#include <sstream>
#include <stdio.h>
using namespace std;
int n, m, c, d, i, j, y = 0,yy = 0, s, k, r, g = 0, a, b, u, det = 0,len,f = 0, t = 0, x,p;
string s2, s3, s4, s1;


int aba()
{
	ifstream open1("Matrix1.txt");
	getline(open1, s1);

	len = s1.length();
	k = s1.find(" ");
	s2 = s1.substr(0, k);
	a = stoi(s2);

	open1.close();

	return a;
}
int abb()
{
	ifstream open1("Matrix1.txt");
	getline(open1, s1);

	k = 0;

	len = s1.length();
	k = s1.find(" ");
	s2 = s1.substr(0, k);

	s3 = s1.substr(k, len - k);
	k = s3.find(" ");
	s4 = s3.substr(t, k - 1);
	b = stoi(s4);
	open1.close();

	return b;
}
int cdc()
{
	ifstream open2("Matrix2.txt");
	getline(open2, s1);

	len = s1.length();
	k = s1.find(" ");
	s2 = s1.substr(0, k);
	c = stoi(s2);

	open2.close();

	return c;
}
int cdd()
{
	ifstream open2("Matrix2.txt");
	getline(open2, s1);

	k = 0;

	len = s1.length();
	k = s1.find(" ");
	s2 = s1.substr(0, k);

	s3 = s1.substr(k, len - k);
	k = s3.find(" ");
	s4 = s3.substr(t, k - 1);
	d = stoi(s4);
	open2.close();

	return d;
}

double matrix1(int i, int j)
{



	ifstream open1("Matrix1.txt");
	string s2, s3, s4, s1;
	getline(open1, s1);

	a = aba();
	b = abb();

	getline(open1, s1);

	double** arr1 = new double* [a];
	for (int i = 0; i < a; i++)
	{
		arr1[i] = new double[b];
	}
	for (int i = 0; i < a; i++)
	{
		len = s1.length();
		for (int j = 0; j < b - 1; j++)
		{
			k = s1.find(" ");
			if (f == 0)
			{
				s2 = s1.substr(0, k);
				f = 1;
				y = stoi(s2);
				arr1[i][j] = y;

			}
			s1 = s1.substr(k + 1, len - k);
			y = stoi(s1);
			arr1[i][j + 1] = y;

		}
		f = 0;
		getline(open1, s1);
	}

	return arr1[i][j];
}
double matrix2(int i, int j)
{



	ifstream open2("Matrix2.txt");
	string s2, s3, s4, s1;
	getline(open2, s1);

	cdc();
	cdd();

	getline(open2, s1);

	double** arr2 = new double* [c];
	for (int i = 0; i < c; i++)
	{
		arr2[i] = new double[d];
	}
	for (int i = 0; i < c; i++)
	{
		len = s1.length();
		for (int j = 0; j < d - 1; j++)
		{
			k = s1.find(" ");
			if (f == 0)
			{
				s2 = s1.substr(0, k);
				f = 1;
				y = stoi(s2);
				arr2[i][j] = y;

			}
			s1 = s1.substr(k + 1, len - k);
			y = stoi(s1);
			arr2[i][j + 1] = y;

		}
		f = 0;
		getline(open2, s1);
	}

	return arr2[i][j];
}

double determinant(double** x, int m)
{
	if (m == 1)
	{
		return x[0][0];
	}
	if (m == 2)
	{
		return (x[0][0] * x[1][1] - x[0][1] * x[1][0]);
	}
	if (m >= 3)
	{
		double** t = new double* [m - 1];
		for (int i = 0; i < m - 1; i++)
		{
			t[i] = new double[m - 1];
		}
		double det = 0;
		int	r, u;
		for (int j = 0; j < m; j++)
		{
			r = 0;
			for (int k = 1; k < m; k++)
			{
				u = 0;
				for (int s = 0; s < m; s++)
				{
					if (s != j)
					{
						t[r][u] = x[k][s];
						u++;
					}
				}
				r++;
			}
			det += pow(-1, (double)j + 2) * x[0][j] * determinant(t, m - 1);
		}
		return det;
	}
	return 0;
}
int SLAU(double** matrica_a, int n, double* massiv_b, double* x)
{
	int i, j, k, r;
	double c, M, max, s, ** a, * b;
	a = new double* [n];
	for (i = 0; i < n; i++)
	{
		a[i] = new double[n];
	}
	b = new double[n];
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			a[i][j] = matrica_a[i][j];
		}
	}
	for (i = 0; i < n; i++)
	{
		b[i] = massiv_b[i];
	}
	for (k = 0; k < n; k++)
	{
		max = fabs(a[k][k]);
		r = k;
		for (i = k + 1; i < n; i++)
		{
			if (fabs(a[i][k]) > max)
			{
				max = fabs(a[i][k]);
				r = i;
			}
		}
		for (j = 0; j < n; j++)
		{
			c = a[k][j];
			a[k][j] = a[r][j];
			a[r][j] = c;
		}
		c = b[k];
		b[k] = b[r];
		b[r] = c;
		for (i = k + 1; i < n; i++)
		{
			for (M = a[i][k] / a[k][k], j = k; j < n; j++)
			{
				a[i][j] -= M * a[k][j];
			}
			b[i] -= M * b[k];
		}
	}
	if (a[n - 1][n - 1] == 0)
	{
		if (b[n - 1] == 0)
		{
			return -1;
		}
		else
		{
			return -2;
		}
	}
	else
	{
		for (i = n - 1; i >= 0; i--)
		{
			for (s = 0, j = i + 1; j < n; j++)
			{
				s += a[i][j] * x[j];
			}
			x[i] = (b[i] - s) / a[i][i];
		}
		return 0;
	}
}
int INVERSE(double** a, int n, double** y)
{
	int i, j, res;
	double* b, * x;
	b = new double[n];
	x = new double[n];
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			if (j == i)
				b[j] = 1; else
				b[j] = 0;
		res = SLAU(a, n, b, x);
		if (res != 0) break;
		else for (j = 0; j < n; j++)
			y[j][i] = x[j];
	}
	if (res != 0)
		return -1;
	else
		return 0;
}

void sum()
{

	aba();
	abb();
	cdc();
	cdd();	

	
	if (c == a && d == b)
	{
		double** arr3 = new double* [a];
		for (int i = 0; i < a; i++)
		{
			arr3[i] = new double[b];
		}

		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < b; j++)
			{
				arr3[i][j] = matrix1(i, j) + matrix2(i, j);
			}

		}
		ofstream fout;
		fout.open("File.txt");
		fout << a;
		fout << " ";
		fout << b << endl;
		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < b; j++)
			{
				fout << arr3[i][j] << "\t";
			}
			fout << endl;
		}
		fout.close();

		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < b; j++)
			{
				cout << arr3[i][j] << "\t";
			}
			cout << endl;
		}
	}
	else
	{
		cout << "Несовместимые матрицы" << endl;
	}

}
void diff()
{
	aba();
	abb();
	cdc();
	cdd();

	if (c == a && d == b)
	{
		double** arr3 = new double* [a];
		for (int i = 0; i < a; i++)
		{
			arr3[i] = new double[b];
		}

		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < b; j++)
			{
				arr3[i][j] = matrix1(i, j) - matrix2(i, j);
			}

		}
		ofstream fout;
		fout.open("File.txt");
		fout << a;
		fout << " ";
		fout << b << endl;
		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < b; j++)
			{
				fout << arr3[i][j] << "\t";
			}
			fout << endl;
		}
		fout.close();

		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < b; j++)
			{
				cout << arr3[i][j] << "\t";
			}
			cout << endl;
		}
	}
	else
	{
		cout << "Несовместимые матрицы" << endl;
	}
}
void multi()
{
	a = aba();
	b = abb();
	c = cdc();
	d = cdd();

	cout << "Ввод числа" << endl;
	cin >> p;

	double** arr3 = new double* [a];
	for (int i = 0; i < a; i++)
	{
		arr3[i] = new double[b];
	}

	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			arr3[i][j] = matrix1(i, j) * p;
		}

	}


	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			cout << arr3[i][j] << "\t";
		}
		cout << endl;
	}

	double** arr4 = new double* [c];
	for (int i = 0; i < c; i++)
	{
		arr4[i] = new double[d];
	}

	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < d; j++)
		{
			arr4[i][j] = matrix2(i, j) * p;
		}

	}
	cout << " " << endl;
	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < d; j++)
		{
			cout << arr4[i][j] << "\t";
		}
		cout << endl;
	}


	//вывод в файл
	ofstream fout;
	fout.open("File.txt");
	fout << a;
	fout << " ";
	fout << b << endl;
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			fout << arr3[i][j] << "\t";
		}
		fout << endl;
	}
	fout << " " << endl;
	fout << c;
	fout << " ";
	fout << d << endl;
	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < d; j++)
		{
			fout << arr4[i][j] << "\t";
		}
		fout << endl;
	}
	fout.close();
}
void multi12()
{
	aba();
	abb();
	cdc();
	cdd();

	if (b == c)
	{
		double** arr3 = new double* [a];
		for (int i = 0; i < a; i++)
		{
			arr3[i] = new double[d];
		}
		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < d; j++)
			{
				arr3[i][j] = 0;
			}

		}


		for (int i = 0; i < a; i++) {
			for (int j = 0; j < d; j++)
			{
				arr3[i][j] = 0;
				for (int k = 0; k < d; k++)
				{
					arr3[i][j] += matrix1(i, k) * matrix2(k, j);
				}
			}
		}

		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < d; j++)
			{
				cout << arr3[i][j] << "\t";
			}
			cout << endl;
		}

		ofstream fout;
		fout.open("File.txt");
		fout << a;
		fout << " ";
		fout << d << endl;
		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < d; j++)
			{
				fout << arr3[i][j] << "\t";
			}
			fout << endl;
		}

	}
	else
	{
		cout << "Матрицы не удовлетворяют условию умножения" << endl;
	}
}
void transp()
{
	aba();
	abb();
	cdc();
	cdd();

	double** arr3 = new double* [b];
	for (int j = 0; j < b; j++)
	{
		arr3[j] = new double[a];
	}

	for (int j = 0; j < b; j++)
	{
		for (int i = 0; i < a; i++)
		{
			arr3[j][i] = matrix1(i, j);
		}

	}

	for (int i = 0; i < b; i++)
	{
		for (int j = 0; j < a; j++)
		{
			cout << arr3[i][j] << "\t";
		}
		cout << endl;
	}


	double** arr4 = new double* [d];
	for (int j = 0; j < d; j++)
	{
		arr4[j] = new double[c];
	}

	for (int j = 0; j < d; j++)
	{
		for (int i = 0; i < c; i++)
		{
			arr4[j][i] = matrix2(i, j);
		}

	}
	cout << " " << endl;
	for (int i = 0; i < d; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << arr4[i][j] << "\t";
		}
		cout << endl;
	}
	//////////////////////////////////////

	ofstream fout;
	fout.open("File.txt");
	fout << b;
	fout << " ";
	fout << a << endl;
	for (int j = 0; j < b; j++)
	{
		for (int i = 0; i < a; i++)
		{
			fout << arr3[j][i] << "\t";
		}
		fout << endl;
	}

	fout << " " << endl;

	fout << d;
	fout << " ";
	fout << c << endl;
	for (int j = 0; j < d; j++)
	{
		for (int i = 0; i < c; i++)
		{
			fout << arr4[j][i] << "\t";
		}
		fout << endl;
	}

}
void opred()
{

	ofstream open("File.txt");
	aba();
	abb();
	cdc();
	cdd();
	if (a == b)
	{
		double** arr = new double* [a];
		for (int i = 0; i < a; i++)
		{
			arr[i] = new double[b];
		}
		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < b; j++)
			{
				arr[i][j] = matrix1(i, j);
			}
		}
		cout << "Определитель матрицы 1 = " << determinant(arr, a) << endl;
		open << "Определитель матрицы 1 = " << determinant(arr, a) << endl;
	}
	else
	{
		cout << "Ошибка, невозможно вычислить определитель матрицы 1" << endl;
		open << "Ошибка, невозможно вычислить определитель матрицы 1" << endl;
	}
	if (c == d)
	{
		double** arr1 = new double* [c];
		for (int i = 0; i < c; i++)
		{
			arr1[i] = new double[d];
		}
		for (int i = 0; i < c; i++)
		{
			for (int j = 0; j < d; j++)
			{
				arr1[i][j] = matrix2(i, j);
			}
		}
		cout << "Определитель матрицы 2 = " << determinant(arr1, c) << endl;
		open << "Определитель матрицы 2 = " << determinant(arr1, c) << endl;
	}
	else
	{
		cout << "Ошибка, невозможно вычислить определитель матрицы 2" << endl;
		open << "Ошибка, невозможно вычислить определитель матрицы 2" << endl;
	}
	open.close();
}
void reverse()
{
	ofstream open("File.txt");
	double h, result;
	aba();
	abb();
	if (a == b)
	{
		double** arr = new double* [a];
		for (int i = 0; i < a; i++)
		{
			arr[i] = new double[a];
		}
		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < a; j++)
			{
				arr[i][j] = matrix1(i,j);
			}
		}
		double** arr2 = new double* [a];
		for (int i = 0; i < a; i++)
		{
			arr2[i] = new double[a];
		}
		result = INVERSE(arr, a, arr2);
		cout << "Прошло" << endl;
		h = determinant(arr, a);
		if (h != 0)
		{
			cout << "Обратная к матрице 1" << endl;
			for (i = 0; i < a; cout << endl, i++)
			{
				for (j = 0; j < a; j++)
				{
					cout << arr2[i][j] << "\t";
				}
			}
			open << "Обратная к матрице 1" << endl;
			for (i = 0; i < a; open << endl, i++)
			{
				for (j = 0; j < a; j++)
				{
					open << arr2[i][j] << "\t";
				}
			}
		}
		else
		{
			cout << "Обратной матрицы к матрице 1 не существует" << endl;
			open << "Обратной матрицы к матрице 1 не существует" << endl;
		}
	}
	else
	{
		cout << "Обратной матрицы к матрице 1 не существует" << endl;
		open << "Обратной матрицы к матрице 1 не существует" << endl;
	}
	
	cdc();
	cdd();

	if (c == d)
	{
		double** arr1 = new double* [c];
		for (int i = 0; i < c; i++)
		{
			arr1[i] = new double[c];
		}
		for (int i = 0; i < c; i++)
		{
			for (int j = 0; j < c; j++)
			{
				arr1[i][j] = matrix2(i,j);
			}
		}
		double** arr3 = new double* [c];
		for (int i = 0; i < c; i++)
		{
			arr3[i] = new double[c];
		}
		result = INVERSE(arr1, c, arr3);
		h = determinant(arr1, c);
		if (h != 0)
		{
			cout << "Обратная к матрице 2" << endl;
			for (i = 0; i < c; cout << endl, i++)
			{
				for (j = 0; j < c; j++)
				{
					cout << arr3[i][j] << "\t";
				}
			}
			open << "Обратная к матрице 2" << endl;
			for (i = 0; i < c; open << endl, i++)
			{
				for (j = 0; j < c; j++)
				{
					open << arr3[i][j] << "\t";
				}
			}
		}
		else
		{
			cout << "Обратной матрицы к матрице 2 не существует" << endl;
			open << "Обратной матрицы к матрице 2 не существует" << endl;
		}
	}
	else
	{
		cout << "Обратной матрицы к матрице 2 не существует" << endl;
		open << "Обратной матрицы к матрице 2 не существует" << endl;
	}
	open.close();
}

int main()
{
	while (yy == 0)
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		cout << "выбор действия" << endl;
		cout << "1 - Сложение матриц" << endl;
		cout << "2 - Вычетание матриц" << endl;
		cout << "3 - Умножение матрицы на число" << endl;
		cout << "4 - Умножение матриц" << endl;
		cout << "5 - Транспонирование" << endl;
		cout << "6 - Определитель" << endl;
		cout << "7 - Обратная матрица" << endl;
		cout << "8 - Выход из программы" << endl;
		cout << " " << endl;
		cin >> s;
		switch (s)
		{
		case 1:
		{
			sum();
			break;
		}
		case 2:
		{
			diff();
			break;
		}
		case 3:
		{
			multi();
			break;
		}
		case 4:
		{
			multi12();
			break;
		}
		case 5:
		{
			transp();
			break;
		}
		case 6:
		{
			opred();
			break;
		}
		case 7:
		{
			reverse();
			break;
		}
		case 8:
		{
			yy = 1;
			break;
		}
		}
	}
}
