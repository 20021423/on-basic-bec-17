// https://paste.ubuntu.com/p/zm8c7QqXDj/?fbclid=IwAR21pexDZDM-FzHLwmWQ4gRVpMsYZFwcSCoFzHFt87BXxAtRkrjIOjAu3YQ
// Bài 10. Cho mảng 1 chiều các số nguyên. Viết chương trình đảo ngược mảng. VD:  1 5 6 2  => 2 6 5 1
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
void DaoNguocMang(int a[], int n, int b[])
{
	int k = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		b[k++] = a[i];
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
	int a[100],b[100];
	NhapMang(a, n);
	cout << "Mang truoc khi dao nguoc la: ";
	XuatMang(a, n);
	DaoNguocMang(a, n, b);
	cout << "\nMang sau khi dao nguoc la: ";
	XuatMang(b, n);
	return 0;
}