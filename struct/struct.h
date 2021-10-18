#pragma once
#include <iostream>
#include <string>
#define MAX 100
using namespace std;

struct PhanSo
{
	int TuSo;
	int MauSo;
};
typedef struct PhanSo ps;
void NhapPhanSo(ps& x);
void NhapDayPhanSo(ps ds[], int n);
void XuatPhanSo(ps x);
void XuatDayPhanSo(ps ds[], int n);
void RutGonPhanSo(ps& x);
int UCLN(int a, int b);
ps SoSanh2PhanSo(ps a, ps b);
ps TimPhanSoLonNhat(ps ds[], int n);
ps TongHaiPhanSo(ps a, ps b);
ps TongDayPhanSo(ps ds[], int n);
void ThemPhanTu(ps ds[], int& n, int vt, ps val);
void XoaPhanTu(ps ds[], int& n, int vt);

// bai2

struct SINHVIEN
{
	string hoten;
	int tuoi;
	string sex;
	double GPA;
};
typedef SINHVIEN sv;

void XoaKiTu(string s, int vt);

string ChuanHoaChuoi(string s);
bool HoTenSinhVien(string s);
void NhapSinhVien(sv& a);
void NhapDanhSachSinhVien(sv ds[], int n);
void XuatSinhVien(sv a);
void XuatDanhSachSinhVien(sv ds[], int n);
void DoiCho_struct(sv& a, sv& b); 
void SapXepTheo_GPA(sv ds[], int n);
string CatTenChuoi(const string& s);
string CatTenDem(const string& s);
