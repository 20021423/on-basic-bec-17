// https://paste.ubuntu.com/p/pQgrrtTMJF/

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
void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
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
void SapXepGiamDanAm(int a[], int n)
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
void SapXepGiamDanDuong(int a[], int n, int dem)
{
	for (int i = dem; i < n - 1; i++)
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
void XoaPhanTu(int a[], int& n, int pos)
{
	for (int i = pos; i < n - 1; i++)
	{
		a[i] = a[i + 1];
	}
	n--;
}
void SapXep(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > 0)
			{
				Swap(a[i], a[j]);
			}
		}
	}
}
void TachMang(int a[], int& n, int b[], int& j)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == 0)
		{
			b[j] = a[i];
			XoaPhanTu(a, n, i);
			i--;
			j++;
		}
	}
	SapXep(a, n);
	for (int i = 0; i < n; i++)
	{
		if (a[i] < 0)
		{
			dem++;
		}
	}
	SapXepGiamDanAm(a, dem);
	SapXepGiamDanDuong(a, n, dem);
	for (int i = 0; i < dem; i++)
	{
		ThemPhanTu(b, j, i, a[i]);
	}
	for (int i = dem; i < n; i++)
	{
		ThemPhanTu(b, j, j, a[i]);
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
	cout << "Mang ban dau la:              ";
	XuatMang(a, n);
	cout << endl;
	int j = 0, b[100];
	TachMang(a, n, b, j);
	cout << "Mang sau khi duoc sap xep la: ";
	XuatMang(b, j);

	return 0;
}