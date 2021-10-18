// https://paste.ubuntu.com/p/wHsgQJW65s/?fbclid=IwAR0t8rBe4lQ5R8TVVFyOQGq7hV_B2xlBrWnZmS_76zFWCGd5tFqsGItB6IM
// 
//1. Nhập và hiển thị một ma trận có kích thước là 5x5, trong đó : các phần tử trên đường chéo được điền giá trị 0, các phần tử của tam giác dưới đường chéo được điền các giá trị - 1, và ở tam giác trên là được điền với các giá trị 1.
//0  1  1  1  1
//- 1  0  1  1  1
//- 1 - 1  0  1  1
//- 1 - 1 - 1  0  1
//- 1 - 1 - 1 - 1  0
//---------------------- -

#include <iostream>
#include<iomanip>
#define MAX 100
using namespace std;
void NhapMang(int a[][MAX], int ndong, int ncot);
void XuatMang(int a[][MAX], int ndong, int ncot);
void ChuanHoaMaTran(int a[][MAX], int n);

void ChuanHoaMaTran(int a[][MAX], int n)
{
	int i=0;
	while (i < n)
	{
		for (int j = i + 1; j < n; j++)
		{
			a[i][j] = 1;
		}
		for (int j = i - 1; j >= 0; j--)
		{
			a[i][j] = -1;
		}
		a[i][i] = 0;
		i++;
	}
}
 /*void NhapMang(int a[][MAX], int ndong, int ncot)
{
	for (int i = 0; i < ndong; i++)
	{
		for (int j = 0; j < ncot; j++)
		{
			cin >> a[i][j];
		}
	}
}*/
void XuatMang(int a[][MAX], int ndong, int ncot)
{
	for (int i = 0; i < ndong; i++)
	{
		for (int j = 0; j < ncot; j++)
		{
			cout <<setw(3)<< a[i][j] << " ";
		}
		cout << endl;
	}
}
int main()
{
	int a[MAX][MAX];
	int ndong, ncot;
	do
	{
		cout << "Nhap ndong: ";
		cin >> ndong;
		cout << "Nhap ncot: ";
		cin >> ncot;
	} while ((ndong && ncot) <= 0 || (ndong && ncot) > MAX);
	if (ndong != ncot)
	{
		cout << "Khong ton tai duong cheo chinh phu";
		return -1;
	}
//	NhapMang(a, ndong, ncot);
	ChuanHoaMaTran(a, ndong);
	XuatMang(a, ndong, ncot);
	return 0;
}
