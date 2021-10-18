// Test nhỏ.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "mylib.h"


int LoadFile(int* p, int& n)
{
    ifstream filein;
    filein.open("input.txt", ios_base::in);
    if (filein.fail()) return 0;
    filein >> p[n];
    while (!filein.eof())
    {
        char x;
        filein >> x;
        filein >> p[n];
        n++;
    }
    return n;
}
void CapPhatLai(int* p, int ncu, int nmoi)
{
    int* temp = new int[ncu];
    for (int i = 0; i < ncu; i++)
    {
        temp[i] = p[i];
    }
    //delete[] p;
    p = new int[nmoi];
    for (int i = 0; i < ncu; i++)
    {
        p[i] = temp[i];
    }
    if (temp == NULL) return;
    delete[]temp;
}
void NhapMang(int* p, int& n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
}
void XuatMang(int* p, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << p[i] << " ";
    }
    cout << endl;
}
void ThemPhanTu(int* p, int& n, int vt, int val)
{
    CapPhatLai(p, n, n + 1);
    for (int i = n; i > vt; i--)
    {
        p[i] = p[i - 1];
    }
    p[vt] = val;
    n++;
}
void XoaPhanTu(int* p, int& n, int vt)
{
    for (int i = vt; i < n; i++)
    {
        p[i] = p[i + 1];
    }
    CapPhatLai(p, n, n - 1);
    n--;
}
bool CheckSoHoanThien(int n)
{
    int ntam = 0;
    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
        {
            ntam += i;
        }
    }
    if (ntam == n) return true;
    return false;
}
void Them0(int* p, int& n)
{
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (CheckSoHoanThien(p[i]))
        {
            ThemPhanTu(p, n, i, 0);
            i++;
        }
    }
}
bool CheckSoDoiXung(int n)
{
    int nDao = 0;
    int ntam = n;
    while (ntam > 0)
    {
        int du = ntam % 10;
        nDao = nDao * 10 + du;
        ntam /= 10;
    }
    return (n == nDao);
}
void XoaPhanTuDoiXung(int* p, int& n)
{
    for (int i = 0; i < n; i++)
    {
        if (CheckSoDoiXung(p[i]))
        {
            XoaPhanTu(p, n, i);
            i--;
        }
    }
}
void LietKeMangCon(int* p, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            for (int k = i; k < j; k++)
            {
                cout << p[k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}
bool CheckMangGonSong(int* p, int n)
{
    for (int i = 1; i < n-1; i++)
    {
        if (!(p[i]<p[i + 1] && p[i]<p[i - 1] || p[i] >p[i + 1] && p[i]>p[i - 1]))
        {
            return false;
        }
    }
    return true;
}
void menu(int* p, int& n)
{
    bool kt = true;
    do
    {
        system("cls");
        cout << "0. Load file danh sach so nguyen" << endl;
        cout << "1. Nhap danh sach so nguyen" << endl;
        cout << "2. Xuat danh sach so nguyen" << endl;
        cout << "3. Them phan tu vao vi tri" << endl;
        cout << "4. Xoa phan tu tai vi tri" << endl;
        cout << "5. Them so 0 vao so hoan thien" << endl;
        cout << "6. Xoa phan tu la so doi xung" << endl;
        cout << "7. Liet ke mang con ban dau" << endl;
        cout << "8. Kiem tra mang gon song" << endl;
        cout << "9. Thoa chuong trinh" << endl;
        int choice;
        cout << "Nhap lua chon: ";
        cin >> choice;
        switch (choice)
        {
        case 0:
        {
            LoadFile(p, n);
            break;
        }
        case 1:
        {
            cout << "\nNhap so luong phan tu can them: ";
            int nso;
            cin >> nso;
            CapPhatLai(p, n, n + nso);
            for (int i = 0; i < nso; i++)
            {
                int x;
                cin >> x;
                p[n++] = x;
            }
            break;
        }
        case 2:
        {
            XuatMang(p, n);
            system("pause");
            break;
        }
        case 3:
        {
            cout << "Them vao vi tri: "; int vt;
            cin >> vt;
            cout << " gia tri: "; int val;
            cin >> val;
            ThemPhanTu(p, n, vt, val);
            break;
        }
        case 4:
        {
            cout << "Xoa phan tu tai vi tri: "; int vt;
            cin >> vt;
            XoaPhanTu(p, n, vt);
            break;
        }
        case 5:
        {
            Them0(p, n);
            break;
        }
        case 6:
        {
            XoaPhanTuDoiXung(p, n);
            break;
        }
        case 7:
        {
            LietKeMangCon(p, n);
            system("pause");
            break;
        }
        case 8:
        {
            if (CheckMangGonSong(p, n))
            {
                cout << "Day la mang gon song!";
                system("pause");
                break;
            }
            else
            {
                cout << "Day khong phai la mang gon song!";
                system("pause");
                break;
            }
        }
        case 9:
        {
            cout << "You really want to exit this program?";
            cout << "\n1.YES 2.NO\n";
            int lc;
            cin >> lc;
            if (lc == 1)
            {
                kt = false;
                break;
            }
        }
        }
    } while (kt);
}
void bai1()
{
    int* p = new int[10];
    int n = 0;
    menu(p, n);
}
int main()
{
    //bai1();
    bai2();
    return 0;
}
void DocFile(Account ds[], int &n)
{
    ifstream filein;
    filein.open("structinput.txt", ios_base::in);
    while (!filein.eof())
    {
        Account x;
        getline(filein, x.id, ',');
        getline (filein, x.pass, '\n');
        ds[n++] = x;
    }
}
void XuatAcount(Account ds[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << ds[i].id << " " << ds[i].pass << endl;
    }
}
void bai2()
{
    Account ds[100];
    int n = 0;
    DocFile(ds, n);
    XuatAcount(ds, n);
}
