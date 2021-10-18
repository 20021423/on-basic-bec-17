#pragma once
#include <iostream>
#include <string>
#include <fstream>
#define max 100
using namespace std;
//---------------
typedef struct mon
{
	string ma_mh;
	string ten_mh;
	int stclt;
	int stcth;
}mon;

typedef struct danh_sach_mh
{
	mon ds[max];
	int sl = 0;
}danh_sach_mh;
//=============== ds diem tp ================
typedef struct diem_tp
{
	string ma_mh;
	int lan;
	float diem;
}diem_tp;
struct node_diem_tp
{
	diem_tp data;
	node_diem_tp* pnext;
};
typedef struct node_diem_tp node_diem_tp;

typedef struct danh_sach_diem
{
	node_diem_tp* phead = NULL;
	node_diem_tp* ptail = NULL;
}danh_sach_diem;
//=============== ds sv ================
typedef struct sv
{
	string ma_sv;
	string ho;
	string ten;
	string sdt;
	string phai;
	//ds diem
	danh_sach_diem ds_diem;
}sv;
struct node_sv
{
	sv data;
	node_sv* pnext;
};
typedef struct node_sv node_sv;

typedef struct danh_sach_sv
{
	node_sv* phead = NULL;
	node_sv* ptail = NULL;
}danh_sach_sv;
//=============== ds lop ===============
typedef struct lop
{
	string ma_lop;
	string ten_lop;
	int nien_khoa;
	//ds sv
	danh_sach_sv ds_sv;
}lop;

typedef struct danh_sach_lop
{
	lop ds[max];
	int sl = 0;
}danh_sach_lop;

node_sv* khoi_tao_node_sv(sv a);
void them_sv(danh_sach_sv& ds_sv, sv a);
//================= mon hoc =======================
istream& operator >> (istream& is, mon& a);
ostream& operator << (ostream& os, mon a);
void xuat_ds_mh(danh_sach_mh ds_mh);
//================= lop =======================
istream& operator >> (istream& is, lop& a);
ostream& operator << (ostream& os, lop a);
void xuat_ds_lop(danh_sach_lop ds_lop);
//===================SV=====================
int kt_trung_ma_lop(danh_sach_lop ds_lop, string a);
istream& operator >> (istream& is, sv& a);
ostream& operator << (ostream& os, sv a);
void xuat_ds_sv_1_lop(danh_sach_sv ds_sv);
void xuat_ds_sv(danh_sach_lop ds_lop);

void load_ds_mh(danh_sach_mh& ds_mh);
void load_ds_lop(danh_sach_lop& ds_lop);
void load_ds_sv(danh_sach_lop& ds_lop);
void menu();