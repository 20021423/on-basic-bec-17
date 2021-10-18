// https://paste.ubuntu.com/p/BJPsYNY6CZ/?fbclid=IwAR3Awnj0WeZRfaVceyvLp-h78-owY3Mqtgs7f-fUG7r32e3XVrqOgUHpWas
// Bài 2: Cho 1 dãy số nguyên. Viết chương trình thêm phần tử 0 vào trước các số hoàn thiện
#include <iostream>
using namespace std;

void NhapMang(int a[], int n);
void XuatMang(int a[], int n);
bool SoHoanThien(int n);
void ThemPhanTu(int a[], int& n, int pos, int value);

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
bool SoHoanThien(int n)
{
	if (n == 0) return false;
	int sum = 0;
	for (int i = 1; i < n; i++)
	{
		if (n % i == 0)
		{
			sum += i;
		}
	}
	if (sum == n) return true;
	return false;
}
void ThemPhanTu(int a[], int& n, int pos, int value)
{
	for (int i = n; i > pos; i--)
	{
		a[i] = a[i - 1];
	}
	a[pos] = value;
	n++;
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
	cout << "Mang ban dau la: ";
	XuatMang(a, n);
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		if (SoHoanThien(a[i]))
		{
			ThemPhanTu(a, n, i, 0);
			i++;
		}
	}
	cout << "Mang sau khi them la: ";
	XuatMang(a, n);
	return 0;
}
