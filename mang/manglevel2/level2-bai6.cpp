// https://paste.ubuntu.com/p/zm8c7QqXDj/?fbclid=IwAR21pexDZDM-FzHLwmWQ4gRVpMsYZFwcSCoFzHFt87BXxAtRkrjIOjAu3YQ
// 6. Cho mảng 1 chiều các số nguyên. Viết chương trình tìm phần tử lớn thứ k trong mảng
#include <iostream>
using namespace std;

void NhapMang(int a[], int n);
void XuatMang(int a[], int n);
void Swap(int& a, int& b);
void SapXepGiamDan(int a[], int n);

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
void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
void SapXepGiamDan(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] < a[j])
			{
				Swap(a[i], a[j]);
			}
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
	int k;
	do
	{
		cout << "Nhap k: ";
		cin >> k;
	} while (k > n || k <= 0);
	cout << "Phan tu lon thu " << k << " la: " << a[k-1];
	return 0;
}