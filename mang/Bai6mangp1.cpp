//https://paste.ubuntu.com/p/d7HK5dXNGF/?fbclid=IwAR13IKHn9mwNf1DevAIFejRZzgjhiE0lutejcrJBSIm-fEkcqidqvzW0Jqk
// 6. Vi?t ch??ng trình in ra các s? siêu nguyên t? có trong m?ng.
#include <iostream>
#include <cmath>
using namespace std;


void NhapMang(int a[], int n);
bool CheckSoSieuNguyenTo(int a[], int n);
bool KiemTraSoNguyenTo(int n);

void NhapMang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap phan tu a[" << i << "]=";
        cin >> a[i];
    }
}
bool KiemTraSoNguyenTo(int n)
{
    if (n < 2)
    {
        return false;
    }
    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
int DemSoChuSo(int n)
{
    if (n < 0) n = -n;
    int dem = 0;
    while (n > 0)
    {
        dem++;
        n /= 10;
    }
    return dem;
}
bool CheckSoSieuNguyenTo(int n)
{
    if (KiemTraSoNguyenTo(n)==false)
    {
        return false;
    }
    int dem = DemSoChuSo(n);
    for (int i = 1; i < dem; i++)
    {
        int tmp = pow(10, i); 
        tmp = n / tmp;
        if (KiemTraSoNguyenTo(tmp) == false)
        {
            return false;
        }
    }
    return true;
}



int main()
{
    int n;
    cout << "Nhap so phan tu mang: ";
    cin >> n;
    int a[100];
    NhapMang(a, n);
    for (int i = 0; i < n; i++)
    {
        if (CheckSoSieuNguyenTo(a[i]) == true)
        {
            cout << a[i] << " ";
        }
    }

    return 0;
}