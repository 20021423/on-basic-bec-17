// https://paste.ubuntu.com/p/zm8c7QqXDj/?fbclid=IwAR21pexDZDM-FzHLwmWQ4gRVpMsYZFwcSCoFzHFt87BXxAtRkrjIOjAu3YQ
// 7. Viết chương trình tìm UCLN của tất cả các phần tử trong mảng 1 chiều các số nguyên.
#include <iostream>
using namespace std;

void NhapMang(int a[], int n);
void XuatMang(int a[], int n);
int UCLN(int a, int b);

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
int UCLN(int a, int b)
{
	if (a == 0 && b == 0) return 0;
	while (b != 0)
	{
		int c = a;
		a = b;
		b = c % a;
	}
	return a;
}
int UCLNMang(int a[], int n)
{
	int k = UCLN(a[0], a[1]);
	for (int i = 2; i < n; i++)
	{
		if (a[i] % k != 0)
		{
			return 1;
		}
	}
	return k;
}
int main()
{
	int n;
	do
	{
		cout << "nhap so phan tu mang: ";
		cin >> n;
	} while (n <= 0);
	int a[100];
	NhapMang(a, n);
	cout << "UCLN cua mang la: ";
	cout<<UCLNMang(a, n);
	return 0;
}