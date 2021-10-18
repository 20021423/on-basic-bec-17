// struct.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://paste.ubuntu.com/p/7BbyNS8d7G/?fbclid=IwAR3NoeATqll5VFwM4t3wem8veT45bi05pmpQk1-cGXx7pkfNJqbJqB3qcX4
//
//BT 1. khai báo cấu trúc 1 phân số, biết phân số luôn luôn có tử số và mẩu số
//_ nhập danh sách phân số
//_ xuất danh sách phân số
//_ rút gọn các phân số
//_ tìm phân số lớn nhất
//_ tính tổng các phân số
//_ thêm phân số x vào vị trí vt nhập từ bàn phím
//_ xóa phân số tại vị trí vt nhập từ bàn phím


#include "struct.h"

void NhapPhanSo(ps& x)
{
	cin >> x.TuSo;
	cin>> x.MauSo;
}
void NhapDayPhanSo(ps ds[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap phan so thu " << i + 1 << endl;
		NhapPhanSo(ds[i]);
	}
}
void XuatPhanSo(ps x)
{
	cout << x.TuSo << "/" << x.MauSo;
}
void XuatDayPhanSo(ps ds[], int n)
{
	for (int i = 0; i < n; i++)
	{
	//	cout << "phan so thu " << i + 1 << endl;
		XuatPhanSo(ds[i]);
		cout << " ";
	}
}
int UCLN(int a, int b)
{
	while (b != 0)
	{
		int c = a;
		a = b;
		b = c % a;
	}
	return a;
}
void RutGonPhanSo(ps& x)
{
	int UC = UCLN(x.TuSo, x.MauSo);
	x.TuSo /= UC;
	x.MauSo /= UC;
}
ps SoSanh2PhanSo(ps a, ps b)
{
	int k = a.TuSo * b.MauSo - b.TuSo * a.MauSo;
	k = k / (a.MauSo * b.MauSo);
	if (k >= 0)
	{
		return a;
	}
	else
		return b;
}
ps TimPhanSoLonNhat(ps ds[], int n)
{
	ps max = ds[0];
	for (int i = 1; i < n; i++)
	{
		max = SoSanh2PhanSo(max, ds[i]);
	}
	return max;
}
ps TongHaiPhanSo(ps a, ps b)
{
	ps sum;
	sum.TuSo = a.TuSo * b.MauSo + b.TuSo * a.MauSo;
	sum.MauSo = a.MauSo * b.MauSo;
//	RutGonPhanSo(sum);
	return sum;
}
ps TongDayPhanSo(ps ds[], int n)
{
	ps sum = TongHaiPhanSo(ds[0], ds[1]);
	for (int i = 2; i < n; i++)
	{
		sum = TongHaiPhanSo(sum, ds[i]);
	}
	RutGonPhanSo(sum);
	return sum;
}
void ThemPhanTu(ps ds[], int& n, int vt, ps val)
{
	for (int i = n; i > vt; i--)
	{
		ds[i] = ds[i-1];
	}
	ds[vt] = val;
	n++;
}
void XoaPhanTu(ps ds[], int& n, int vt)
{
	for (int i = vt; i < n; i++)
	{
		ds[i] = ds[i + 1];
	}
	n--;
}
int main()
{
	int n;
	do
	{
		cout << "Nhap so phan so: ";
		cin >> n;
	} while (n > MAX);
	ps ds[MAX];
	NhapDayPhanSo(ds, n);
	XuatDayPhanSo(ds, n);
	cout << "\nDay so da duoc rut gon la: ";
	for (int i = 0; i < n; i++)
	{
		RutGonPhanSo(ds[i]);
		XuatPhanSo(ds[i]);
		cout << " ";
	}
	cout << "\nPhan so lon nhat la: ";
	ps max = TimPhanSoLonNhat(ds, n);
	XuatPhanSo(max);
	cout << "\nTong day phan so la: ";
	ps sum = TongDayPhanSo(ds, n);
	XuatPhanSo(sum);
	cout << "\nNhap phan so can them: ";
	ps newps;
	NhapPhanSo(newps);
	int vt;
	do
	{
		cout << "\nthem vao vi tri: ";
		cin >> vt;
	} while (vt > n);
	ThemPhanTu(ds, n, vt, newps);
	cout << "\nDay so moi la: ";
	XuatDayPhanSo(ds, n);
	int pos;
	do
	{
		cout << "\nNhap vi tri can xoa: ";
		cin >> pos;
	} while (pos >= n);
	XoaPhanTu(ds, n, pos);
	cout << "\nDay sau khi xoa la: ";
	XuatDayPhanSo(ds, n);
	
	return 0;
}