//https://paste.ubuntu.com/p/d7HK5dXNGF/?fbclid=IwAR13IKHn9mwNf1DevAIFejRZzgjhiE0lutejcrJBSIm-fEkcqidqvzW0Jqk
#include <iostream>
using namespace std;


void NhapMang(int a[], int n);
bool DayTangDan(int a[], int n);

void NhapMang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap phan tu a[" << i << "]=";
        cin >> a[i];
    }
}
bool DayTangDan(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                return false;
            }
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
    if (DayTangDan(a, n) == true)
        cout << "Day la mang tang dan";
    else
        cout << "Day khong phai mang tang dan";
    return 0;
}