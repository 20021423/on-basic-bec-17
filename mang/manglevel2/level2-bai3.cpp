// https://paste.ubuntu.com/p/zm8c7QqXDj/?fbclid=IwAR21pexDZDM-FzHLwmWQ4gRVpMsYZFwcSCoFzHFt87BXxAtRkrjIOjAu3YQ
// 5. (Tư duy + Xử lý) // Bài thi kết thúc học phần: Tin học cơ sở 2(PTIT HCM)
//Cho 1 mảng số nguyên.Sắp xếp các số âm nằm trước giảm dần tiếp đến là số 0 rồi đến các số dương giảm dần
//VD : mảng: 12pt : -4     5      0      6 - 1     0      8      3 - 11    15    2    1
//Kết quả : -1 - 4 - 11     0       0    15     8      6       5      3     2    1
//Gợi ý : Sử dụng mảng phụ
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
void SapXepMang(int a[], int b[], int na, int nb, int c[])
{
	int n = na + nb;
	int i = 0, j = 0, k = 0;
	while (k < n && i < na && j < nb)
	{
		if (a[i] < b[j])
		{
			c[k++] = a[i++];
		}
		else
		{
			c[k++] = b[j++];
		}
	}
	while (i < na)
	{
		c[k++] = a[i++];
	}
	while (j < nb)
	{
		c[k++] = b[j++];
	}
}


int main()
{
	int na;
	do
	{
		cout << "Nhap so phan tu mang a: ";
		cin >> na;
	} while (na <= 0);
	int nb;
	do
	{
		cout << "Nhap so phan tu mang b: ";
		cin >> nb;
	} while (nb <= 0);
	int n = na + nb;
	int a[100], b[100], c[200];
	NhapMang(a, na);
	NhapMang(b, nb);
	SapXepMang(a, b, na, nb, c);
	XuatMang(c, n);
	return 0;
}
