// https://paste.ubuntu.com/p/BJPsYNY6CZ/?fbclid=IwAR3Awnj0WeZRfaVceyvLp-h78-owY3Mqtgs7f-fUG7r32e3XVrqOgUHpWas
// Bài 4. Cho mảng 1 chiều các số nguyên. Viết chương trình đếm số lần xuất hiện của từng phần tử trong mảng.
#include <iostream>
using namespace std;

void NhapMang(int a[], int n);
void XuatMang(int a[], int n);

void NhapMang(int a[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << "Nhap a[" << i << "]=";
		cin >> a[i];
	}
}
void XuatMang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}
void DemSoLanXuatHien(int a[], int n)
{
	int dem[100];
	bool phantu[100];
	for (int i = 0; i < n; i++)
	{
		dem[i] = 1;
		phantu[i] = true;
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] == a[j])
			{
				phantu[j] = false;
				dem[i]++;
			}
		}
	}
	cout << "Phan tu - Tan suat" << endl;
	for (int i = 0; i < n; i++)
	{
		if (phantu[i] == true)
		{
			cout << a[i] << " " << dem[i] << endl;
		}
	}
}
int main()
{
	int n;
	do
	{
		cout << "Nhap so phan tu mang: ";
		cin >> n;
	} while (n <= 0);
	int a[100];
	NhapMang(a, n);
	DemSoLanXuatHien(a, n);
	return 0;
}
