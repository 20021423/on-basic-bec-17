// https://paste.ubuntu.com/p/zm8c7QqXDj/?fbclid=IwAR21pexDZDM-FzHLwmWQ4gRVpMsYZFwcSCoFzHFt87BXxAtRkrjIOjAu3YQ
// 4. Cho 1 mảng các số nguyên a. Viết chương trình tách các số âm ra mảng b và xóa khỏi a
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
void XoaPhanTu(int a[], int& n, int pos)
{
	for (int i = pos; i < n - 1; i++)
	{
		a[i] = a[i + 1];
	}
	n--;
}
void TachMang(int a[], int &n, int b[], int &j)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] < 0)
		{
			b[j] = a[i];
			XoaPhanTu(a, n, i);
			i--;
			j++;
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
	int a[100], b[100];
	NhapMang(a, n);
	int j = 0;
	TachMang(a, n, b, j);
	XuatMang(a, n);
	cout << endl;
	XuatMang(b, j);
	return 0;
}