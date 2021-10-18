//4. Cho dãy số nguyên. Viết chương trình kiểm tra mảng có toàn dương hay không?
// https://paste.ubuntu.com/p/d7HK5dXNGF/?fbclid=IwAR13IKHn9mwNf1DevAIFejRZzgjhiE0lutejcrJBSIm-fEkcqidqvzW0Jqk
#include <iostream>
using namespace std;


void NhapMang(int a[], int n);
bool KiemtraHamToanDuong(int a[], int n);


void NhapMang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap phan tu a[" << i << "]=";
        cin >> a[i];
    }
}
bool KiemtraHamToanDuong(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
        {
            cout << "Mang khong toan duong" << endl;
            return false;
        }
    }
    cout << "Mang toan duong";
    return true;
}


int main()
{
    int n;
    cout << "Nhap so phan tu mang: ";
    cin >> n;
    int a[100];
    NhapMang(a, n);
    KiemtraHamToanDuong(a, n);
    return 0;
}