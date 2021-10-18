
//https://paste.ubuntu.com/p/64SSFyt5cd/?fbclid=IwAR1XJwYgARHS98NfA3oxzF3YWxj7PFHLDboyBCfYVPfD6Cai5fHDJqBBAko
// 4. Viết chương trình dùng con trỏ quản lí mảng. Thêm phần tử có giá trị x tại vị trí vt nhập từ bàn phím
#include <iostream>
using namespace std;
void Bai4(int* p, int& n, int vt, int val);
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

void Bai4(int* p, int& n, int vt, int val)
{
    for (int i = n; i > vt; i--)
    {
        *(p + i) = *(p + i - 1);
    }
    *(p + vt) = val;
    n++;
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
        cout << "Nhap vi tri can them: ";
        cin >> vt;
    } while (vt <= 0 || vt > n);
    cout << "Nhap gia tri: ";
    int val;
    cin >> val;
    Bai4(p, n, vt-1, val);
    XuatMang(p, n);
    return 0;
}
