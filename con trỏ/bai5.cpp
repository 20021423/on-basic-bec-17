// 5. Viết chương trình dùng con trỏ quản lí mảng. Sắp xếp các phần tử trong mảng tăng dần.
#include <iostream>
using namespace std;
void Bai5(int* p, int n);
void NhapMang(int* p, int n);
void XuatMang(int* p, int n);
void Swap(int* a, int* b);

void Swap(int* a, int* b)
{
    int c = *a;
    *a = *b;
    *b = c;
}
void NhapMang(int* p, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap [" << i << "]=";
        cin >> *(p + i);
    }
}
void XuatMang(int* p, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << *(p + i) << " ";
    }
}

void Bai5(int* p, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (*(p + i) > *(p + j))
            {
                Swap(p + i, p + j);
            }
        }
    }
}
int main()
{
    int n;
    do
    {
        cout << "Nhap so luong phan tu mang: ";
        cin >> n;
    } while (n <= 0);
    int* p = new int[n];
    NhapMang(p, n);
    Bai5(p, n);
    XuatMang(p, n);
    return 0;
}
