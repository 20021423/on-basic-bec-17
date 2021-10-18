// on-basic-bec-17.cpp : This file contains the 'main' function. Program execution begins and ends there.
// đề bài https://paste.ubuntu.com/p/d7HK5dXNGF/?fbclid=IwAR13IKHn9mwNf1DevAIFejRZzgjhiE0lutejcrJBSIm-fEkcqidqvzW0Jqk 

// Viết chương trình xuất ra các phần tử là số nguyên tố trong mảng
#include <iostream>
using namespace std;
bool KiemTraSoNguyenTo(int n);
void NhapMang(int a[], int n);

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
void NhapMang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap phan tu a[" << i << "]=";
        cin >> a[i];
    }
}
int main()
{
    int n;
    cout << "Nhap so phan tu cua mang: ";
    cin >> n;
    int a[100];
    cout << "Nhap cac phan tu cua mang: ";
    NhapMang(a, n);
    cout << "Cac so nguyen to co trong mang la: " << endl;
    for (int i = 0; i < n; i++)
    {
        if (KiemTraSoNguyenTo(a[i]) == true)
        {
            cout << a[i] << " ";
        }
    }
    return 0;
}

