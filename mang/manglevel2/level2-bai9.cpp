// https://paste.ubuntu.com/p/zm8c7QqXDj/?fbclid=IwAR21pexDZDM-FzHLwmWQ4gRVpMsYZFwcSCoFzHFt87BXxAtRkrjIOjAu3YQ
// Bài 9. Cho mảng 1 chiều các số nguyên. Viết chương trình in ra các phần tử kề nhau mà cả hai đều chẵn.
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
void InChan(int a[], int n)
{
	bool flag = false;
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] % 2 == 0 && a[i + 1] % 2 == 0)
		{
			cout << a[i] << " " << a[i + 1] << endl;
			flag = true;
		}
	}
	if (flag == false) cout << "Khong co 2 phan tu chan lien ke nhau";
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
	InChan(a, n);
	return 0;
}