#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

string getInputFileName(int);
string getOutputFileName(int);
void Nhap(int[][100], int&, int&, string);
void Xuat(int[][100], int, int, string);
void Xuat(int[][100], int, int);
void ThemDong(int[][100], int&, int, int);



int main()
{
	int b[100][100];
	int k;
	int l;
	int c;
	cout << "\nNhap chi so dong can them: "; cin >> c;

	for (int i = 1; i <= 13; i++)
	{
		string FileName = getInputFileName(i);
		Nhap(b, k, l, FileName);

		cout << "\n" << FileName << endl;
		Xuat(b, k, l);
		cout << '\n' << '\n';
		ThemDong(b, k, l, c);
		cout << "\nMang sau khi them dong toan 1 vao sau dong c la: ";
		Xuat(b, k, l);

		FileName = getOutputFileName(i);
		Xuat(b, k, l, FileName);
	}
	return 1;
}

void Xuat(int a[][100], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(8);
			cout << setprecision(3);
			cout << a[i][j];
		}
		cout << "\n";
	}
}

string getInputFileName(int n)
{
	string fileName = string("intmatrandata");
	if (n < 10)
		fileName += "0" + to_string(n) + ".inp";
	else
		fileName += to_string(n) + ".inp";
	return fileName;
}

string getOutputFileName(int n)
{
	string fileName = string("intmatrandata");
	if (n < 10)
		fileName += "0" + to_string(n) + ".out";
	else
		fileName += to_string(n) + ".out";
	return fileName;
}


void Nhap(int a[][100], int& m, int& n, string filename)
{
	ifstream fi(filename);
	fi >> m;
	fi >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			fi >> a[i][j];
}

void Xuat(int a[][100], int m, int n, string filename)
{
	ofstream fo(filename);
	fo << setw(8) << n;
	fo << setw(8) << m;
	fo << "\n";
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			fo << setw(8) << a[i][j];
		fo << "\n";
	}
}


void ThemDong(float a[][100], int& m, int n,int d)
{
	for (int j = 0; j < n; j++)
	{
		for (int i = m; i >= d + 1; i--)
			a[i][j] = a[i - 1][j];
		a[d][j] = +1;
	}
	m++;
}


