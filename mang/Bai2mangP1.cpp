// đề bài https://paste.ubuntu.com/p/d7HK5dXNGF/?fbclid=IwAR13IKHn9mwNf1DevAIFejRZzgjhiE0lutejcrJBSIm-fEkcqidqvzW0Jqk
// Cho dãy số nguyên. Viết chương trình tìm giá trị lẻ cuối cùng trong mảng.

#include <iostream>
using namespace std;

void NhapMang(int a[], int n);


void NhapMang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap phan tu a[" << i << "]=";
        cin >> a[i];
    }
}
int TimGiaTriLeCuoiCung(int a[], int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] % 2 == 1)
        {
            cout << "Phan tu le cuoi cung la: ";
            return a[i];
        }
    }
    cout << "khong co gia tri le";
    return 0;
}
int main()
{
    int n;
    cout << "Nhap so phan tu mang: ";
    cin >> n;
    int a[100];
    cout << "Nhap mang: ";
    NhapMang(a, n);
    cout<<TimGiaTriLeCuoiCung(a, n);
    return 0;
}
