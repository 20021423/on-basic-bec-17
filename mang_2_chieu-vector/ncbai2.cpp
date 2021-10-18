// https://paste.ubuntu.com/p/wHsgQJW65s/?fbclid=IwAR0t8rBe4lQ5R8TVVFyOQGq7hV_B2xlBrWnZmS_76zFWCGd5tFqsGItB6IM
// 
// 1. Viết chương trình C++ để nhập và hiển thị tam giác Pascal. Chắc bạn đã khá quen thuộc với tam giác Pascal rồi, ở đây, hàng đầu tiên và thứ hai được thiết lập là 1. Bắt đầu từ hàng thứ ba trở đi, mỗi phần tử là tổng của phần tử ngay trên nó và phần tử bên trái của phần tử ngay trên đó.
//
//Kích thước pascal: 6
//1
//1  1
//1  2  1
//1  3  3   1
//1  4  6   4   1
//1  5  10  10  5 1


#include <iostream>
#include <iomanip>
#define MAX 200

using namespace std;
int Pascal(int n, int k)
{
	if (k == 0 || k == n) return 1;
	return Pascal(k - 1, n - 1) + Pascal(k, n - 1);
}
void InTamGiacPascal(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << Pascal(j, i) << " ";
		}
		cout << endl;
	}
}

void TamGiacPascal(int a[][MAX], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i][i] = 1;
		a[i][0] = 1;
		for (int j = i + 1; j < n; j++)
		{
			a[i][j] = 0;
		}
		for (int j = i - 1; j > 0; j--)
		{
			a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
		}
	}
}

void XuatMang(int a[][MAX], int ndong, int ncot)
{
	for (int i = 0; i < ndong; i++)
	{
		for (int j = 0; j < ncot; j++)
		{
			if(a[i][j]!=0)
			cout << setw(5) << a[i][j] << " ";
		}
		cout << endl;
	}
}
int main()
{
	//int a[MAX][MAX];
	int n;
	do
	{
		cout << "Nhap tam giac Pasacal he so: ";
		cin >> n;
	} while (n <= 0 || n > MAX);
	/*TamGiacPascal(a, n);*/
	InTamGiacPascal(n);
	//XuatMang(a, n, n);
	return 0;
}
// cach 2: ham de quy
//int Pascal(int n, int k)
//{
//	if (k == 0 || k == n) return 1;
//	return Pascal(k - 1, n - 1) + Pascal(k, n - 1);
//}
//void InTamGiacPascal(int n, int k)
//{
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j <= i; j++)
//		{
//			cout << Pascal(j, i) << " ";
//		}
//		cout << endl;
//	}
//}
