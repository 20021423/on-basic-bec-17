
//https://paste.ubuntu.com/p/64SSFyt5cd/?fbclid=IwAR1XJwYgARHS98NfA3oxzF3YWxj7PFHLDboyBCfYVPfD6Cai5fHDJqBBAko
// 2. Viết chương trình dùng con trỏ quản lí mảng n phần tử.Xuất các phần tử là số nguyên tố
#include <iostream>
using namespace std;
void Bai2(int* p, int n);
void NhapMang(int* p, int n);
bool SoNguyenTo(int n);

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
bool SoNguyenTo(int n)
{
    if (n < 2) return false;
    for (int i = 2; i <= n/2; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
void Bai2(int* p, int n)
{
   
    for (int i = 1; i < n; i++)
    {
        if (SoNguyenTo(*(p + i)))
        {
            cout << *(p + i) << " ";
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
    Bai2(p, n);
    return 0;
}
