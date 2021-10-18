#include <iostream>
using namespace std;

void NhapMang(int a[], int n);
void XuatMang(int a[], int n);
int TimSoDao(int n);
bool SoDoiXung(int n);
void XoaPhanTu(int a[], int& n, int pos);

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
int TimSoDao(int n)
{
	int nDao = 0;
	while (n > 0)
	{
		int du = n % 10;
		nDao = nDao * 10 + du;
		n /= 10;
	}
	return nDao;
}
bool SoDoiXung(int n)
{
	if (n == TimSoDao(n)) return true;
	return false;
}
void XoaPhanTu(int a[], int& n, int pos)
{
	for (int i = pos; i < n - 1; i++)
	{
		a[i] = a[i + 1];
	}
	n--;
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
	for (int i = 0; i < n; i++)
	{
		if (SoDoiXung(a[i]))
		{
			XoaPhanTu(a, n, i);
			i--;
		}
	}
	XuatMang(a, n);
	return 0;
}
