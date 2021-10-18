//3. Cho dãy số nguyên.Viết chương trình tìm đoạn[a, b] sao cho đoạn này chứa mọi giá trị trong mảng.
#include <iostream>
using namespace std;

int MaxMang(int a[], int n);
void NhapMang(int a[], int n);
int MinMang(int a[], int n);

void NhapMang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap phan tu a[" << i << "]=";
        cin >> a[i];
    }
}
int MaxMang(int a[],int n)
{
    int max = a[0];
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    return max;
}

int MinMang(int a[], int n)
{
    int min = a[0];
    for (int i = 0; i < n; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
        }
    }
    return min;
}
int main()
{
    int n;
    cout << "Nhap so phan tu mang: ";
    cin >> n;
    int a[100];
    NhapMang(a, n);
    cout << "Doan [a;b] chua moi gia tri cua mang la: " << "[" << MinMang(a, n) << ";" << MaxMang(a, n) << "]";
    return 0;
}