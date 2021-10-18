#pragma once
#include <iostream>
#include <string>
#include <fstream>
#define MAX 100
using namespace std;

struct Diem {
	double Mac = 0;
	double DaiSo = 0;
	double Cpp = 0;
};

struct SinhVien
{
	string HoTen;
	string sex;
	string birthday;
	string MSSV;
	struct Diem diem;
};
typedef SinhVien sv;

string ChuanHoaChuoi(string s);
bool HoTenSinhVien(string s);
//istream operator >> (istream& in, sv& x);
void NhapDanhSachSinhVien(sv ds[], int n);
void XuatSinhVien(sv a);
void XuatDanhSachSinhVien(sv ds[], int n);
void NhapDiemChoSinhVien(sv& x);
void Xoa(sv ds[], int& n, int vt);
void SapXepTheo_Ten_Ho(sv ds[], int n);
void DoiCho_struct(sv& a, sv& b); 
string CatNgay(const string& s);
string CatThang(const string& s);
string CatNam(const string& s);
void menu(sv ds[], int& n);
void DocFile(sv ds[], int& n);