// https://paste.ubuntu.com/p/zm8c7QqXDj/?fbclid=IwAR21pexDZDM-FzHLwmWQ4gRVpMsYZFwcSCoFzHFt87BXxAtRkrjIOjAu3YQ
// 1. Viết chương trình gộp mảng a vào đầu mảng b
#include <iostream>
using namespace std;

void NhapMang(int a[], int n);
void XuatMang(int a[], int n);

void NhapMang(int a[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << "Nhap [" << i << "]=";
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
	int c[200];
	int i = 0;
	while (i < na)
	{
		c[i] = a[i];
		i++;
	}
	for (int j = 0; j < nb; j++)
	{
		c[i] = b[j];
		i++;
	}
	nb = i;
	for (int k = 0; k < i; k++)
	{
		b[k] = c[k];
	}
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
