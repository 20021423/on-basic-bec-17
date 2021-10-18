
//https://paste.ubuntu.com/p/64SSFyt5cd/?fbclid=IwAR1XJwYgARHS98NfA3oxzF3YWxj7PFHLDboyBCfYVPfD6Cai5fHDJqBBAko
// 1. Viết chương trình dùng con trỏ quản lí mảng n phần tử. Xuất phần tử lớn nhất và nhỏ nhất trong mảng.
#include <iostream>
using namespace std;
void Bai1(int* p, int n);

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
        cout<< *(p + i)<<" ";
    }
}
void Bai1(int* p, int n)
{
    int max = *p, min = *p;
    for (int i = 1; i < n; i++)
    {
        if (*(p + i) < min)
        {
            min = *(p + i);
        }
        if (*(p + i) > max)
        {
            max = *(p + i);
        }
    }
    cout << "Phan tu lon nhat la: " << max << endl;
    cout << "Phan tu nho nhat la: " << min << endl;
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
    Bai1(p, n);
    return 0;
}
