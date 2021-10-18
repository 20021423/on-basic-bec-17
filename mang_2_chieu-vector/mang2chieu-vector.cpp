// https://paste.ubuntu.com/p/wHsgQJW65s/?fbclid=IwAR0t8rBe4lQ5R8TVVFyOQGq7hV_B2xlBrWnZmS_76zFWCGd5tFqsGItB6IM
// 1. Tính tổng cách phần tử lẻ nằm trên đường chéo chính và đường chéo phụ của mảng 2 chiều a[dong][cot].


#include <iostream>
#define MAX 100
using namespace std;

int Tong(int a[][MAX], int ndong, int ncot);


int Tong(int a[][MAX], int ndong, int ncot)
{
	int sum = 0;
	for (int i = 0; i < ndong; i++)
	{
		sum += a[i][i] + a[i][ndong - i - 1];
	}
	if (ndong % 2 != 0)
	{
		int i = (ndong - 1) / 2;
		sum = sum - a[i][i];
	}
	return sum;
}
void NhapMang(int a[][MAX], int ndong, int ncot)
{
	for (int i = 0; i < ndong; i++)
	{
		for (int j = 0; j < ncot; j++)
		{
			cin >> a[i][j];
		}
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
	NhapMang(a, ndong, ncot);
	cout<<Tong(a, ndong, ncot);
	return 0;
}
