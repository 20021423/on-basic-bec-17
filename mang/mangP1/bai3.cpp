// https://paste.ubuntu.com/p/BJPsYNY6CZ/?fbclid=IwAR3Awnj0WeZRfaVceyvLp-h78-owY3Mqtgs7f-fUG7r32e3XVrqOgUHpWas
// Bài 3. Cho mảng 1 chiều các số nguyên. Viết chương trình xóa các phần tử trùng nhau trong mảng, chỉ giữ lại duy nhất một phần tử phân biệt.
#include <iostream>
using namespace std;

void NhapMang(int a[], int n);
void XuatMang(int a[], int n);
void XoaPhanTu(int a[], int& n, int pos);

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
void XoaPhanTuTrungNhau(int a[], int& n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] == a[i])
			{
				XoaPhanTu(a, n, j);
				j--;
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
	XuatMang(a, n);
	cout << endl;
	XoaPhanTuTrungNhau(a, n);
	XuatMang(a, n);
	return 0;
}
