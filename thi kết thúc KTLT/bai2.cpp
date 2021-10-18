//2. Cho mảng 1 chiều các số nguyên.Hãy tìm giá trị trong mảng các số nguyên xa giá trị x nhất(x nhập từ bàn phím)
//VD: 24 45 23 13 43 - 12
//x = 15
//==> giá trị trong mảng xa x nhất là : 45
#include <iostream>
#define MAX 100
#include <cmath>
#include <vector>
using namespace std;

void NhapMang(int a[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << "Nhap a[" << i << "]=";
		cin >> a[i];
	}
}
void XoaTrung(int b[], int n)
{
	bool k[MAX];
	for (int i = 0; i < n; i++)
	{
		k[i] = true;
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (b[j] == b[i])
			{
				k[j] = false;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (k[i] == true)
		{
			cout << b[i] << " ";
		}
	}
}
void bai2(int a[], int n, int x)
{
	int max = abs(a[0] - x);
	for (int i = 0; i < n; i++)
	{
		if (abs(a[i] - x) > max)
		{
			max = abs(a[i] - x);
		}
	}
	int b[MAX];
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (abs(a[i] - x) == max)
		{
			b[j++] = a[i];
		}
	}
	cout << "Tap hop nhung so cach x xa nhat la: ";
	XoaTrung(b, j);
}
int main()
{
	int a[MAX];
	int n;
	do
	{
		cout << "Nhap so phan tu mang: ";
		cin >> n;
	} while (n > MAX || n <= 0);
	NhapMang(a, n);
	cout << "nhap gia tri can so sanh: ";
	int x;
	cin >> x;
	bai2(a, n, x);
	return 0;
}