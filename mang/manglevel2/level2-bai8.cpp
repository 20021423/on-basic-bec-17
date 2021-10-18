// https://paste.ubuntu.com/p/zm8c7QqXDj/?fbclid=IwAR21pexDZDM-FzHLwmWQ4gRVpMsYZFwcSCoFzHFt87BXxAtRkrjIOjAu3YQ
// 8. Cho mảng 1 chiều các số nguyên. Hãy tìm giá trị trong mảng các số nguyên xa giá trị x nhất(x nhập từ bàn phím)
//VD: 24 45 23 13 43 - 12
//x = 15
//==> giá trị trong mảng xa x nhất là : 45
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
int Abs(int n)
{
	n = (n > 0) ? n : -n;
	return n;
}
void TimSoXaNhat(int a[], int n, int x, int b[])
{
	int max = Abs(a[0] - x);
	int index = 0;
	for (int i = 1; i < n; i++)
	{
		if (Abs(a[i] - x) > max)
		{
			max = Abs(a[i] - x);
		}
	}
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		if (Abs(a[i] - x) == max)
		{
			b[k++] = a[i];
		}
	}
	cout << "So xa " << x << " nhat la: ";
	for (int i = 0; i < k; i++)
	{
		cout << b[i] << " ";
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
	int a[100], b[100];
	NhapMang(a, n);
	int x;
	cout << "Nhap x: ";
	cin >> x;
	TimSoXaNhat(a, n, x, b);
	return 0;
}