// https://paste.ubuntu.com/p/zm8c7QqXDj/?fbclid=IwAR21pexDZDM-FzHLwmWQ4gRVpMsYZFwcSCoFzHFt87BXxAtRkrjIOjAu3YQ
// Viết chương trình gộp mảng a vào cuối mảng b
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
void GopMang(int a[], int b[], int na, int& nb)
{
	int n = na + nb;
	int j = nb;
	for (int i = 0; i < na; i++)
	{
		b[j] = a[i];
		j++;
	}
	nb = n;
}

int main()
{
	int na, nb;
	do
	{
		cout << "Nhap so phan tu mang a: ";
		cin >> na;
	} while (na <= 0);
	do
	{
		cout << "Nhap so phan tu mang b: ";
		cin >> nb;
	} while (nb <= 0);
	int a[100], b[100];
	NhapMang(a, na);
	NhapMang(b, nb);
	GopMang(a, b, na, nb);
	XuatMang(b, nb);

	return 0;
}
