
//https://paste.ubuntu.com/p/64SSFyt5cd/?fbclid=IwAR1XJwYgARHS98NfA3oxzF3YWxj7PFHLDboyBCfYVPfD6Cai5fHDJqBBAko
// 3. Viết chương trình dùng con trỏ quản lí mảng. Xóa phần tử tại vị trí vt nhập từ bàn phím
#include <iostream>
using namespace std;
void Bai3(int* p, int& n, int vt);
void NhapMang(int* p, int n);
void XuatMang(int* p, int n);

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

void Bai3(int* p, int& n, int vt)
{
    for (int i = vt; i < n; i++)
    {
        *(p + i) = *(p + i + 1);
    }
    n--;
}
int main()
{
    int n;
    do
    {
        cout << "Nhap so luong phan tu mang: ";
        cin >> n;
    } while (n <= 0);
    int vt;
    int* p = new int[n];
    NhapMang(p, n);
    do
    {
        cout << "Nhap vi tri can xoa: ";
        cin >> vt;
    } while (vt <= 0 || vt > n);
    Bai3(p, n, vt);
    XuatMang(p, n);
    return 0;
}
