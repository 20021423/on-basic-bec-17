#pragma once

#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int LoadFile(int* p, int& n);
void CapPhatLai(int* p, int ncu, int nmoi);
void NhapMang(int* p, int& n);
void XuatMang(int* p, int n);
void ThemPhanTu(int* p, int& n, int vt, int val);
void XoaPhanTu(int* p, int& n, int vt);
bool CheckSoHoanThien(int n);
void Them0(int* p, int& n);
bool CheckSoDoiXung(int n);
void XoaPhanTuDoiXung(int* p, int& n);
void LietKeMangCon(int* p, int n);
bool CheckMangGonSong(int* p, int n);
void bai1();

struct Account
{
	string id;
	string pass;
};
void bai2();
void XuatAcount(Account ds[], int n);