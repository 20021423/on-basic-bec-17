// Nhapxuatfile.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 
//1. đọc các số nguyên từ file input.txt biết
//+ dòng đầu tiên là 1 số nguyên biểu diễn số lượng các số nguyên cần đọc
//+ dòng thứ 2 là 1 dãy các số nguyên cần đọc
//VD : intput.txt
//5
//1 4 7 8 9
//(các bạn tự tạo)
//== = yêu cầu == =
//Tìm phần tử lớn nhất trong mảng số nguyên đó và ghi vào file input.txt

#include "Header.h"


void bai1()
{
	vector<int> a;
	fstream file;
	file.open("input.txt", ios::in);
	int n;
	file >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		file >> x;
		a.push_back(x);
	}
	int max = a[0];
	for (int i = 1; i < n; ++i)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
	}
	cout << max;
	ofstream k("input.txt");
	k << max;
	k.close();
}


//-----------------------BAI2------------------

//2. đọc các số nguyên từ file input.txt
//biết : chỉ có 1 dòng duy nhất chứa các số nguyên
//VD : input.txt
//12 345 1 7 12 1
//==== yêu cầu ==
//tìm các phần tử là số amstrong trong mảng số nguyên đó và ghi vào file ouput.txt

bool Amstrong(const int& n)
{
	if (n < 10) return true;
	int ntam = n;
	int nsize = 0;
	while (ntam > 0)
	{
		ntam /= 10;
		nsize++;
	}
	ntam = n;
	int sum = 0;
	while (ntam > 0)
	{
		sum += pow(ntam % 10, nsize);
		ntam /= 10;
	}
	return (n == sum);
}

void bai2()
{
	ofstream k;
	k.open("input.txt");
	k << "12 345 1 7 12 1";
	k.close();
	ifstream p;
	p.open("input.txt");
	vector<int>a;
	while (!p.eof())
	{
		int n;
		p >> n;
		a.push_back(n);
	}
	for (int i = 0; i < a.size(); i++)
	{
		if(Amstrong(a[i]))
		cout << a[i] << " ";
	}
	ofstream knew("output.txt");
	for (int i = 0; i < a.size(); i++)
	{
		if (Amstrong(a[i]))
			knew << a[i] << " ";
	}
}



// ====================BAI3===============================

//Đọc các số nguyên từ file INPUT.TXT biết
//+ Chỉ có 1 dòng duy nhất chứa các số nguyên và mỗi số nguyên cách nhau bởi 1 dấu phẩy
//VD : INPUT.TXT
//1, 3, 6, 9
//
//== = Yêu cầu == =
//-File UCLN.TXT lưu 1 số nguyên là ước số chung lớn nhất của tất cả các phần tử của mảng
//- File BCNN.TXT lưu 1 số nguyên là bội chung nhỏ nhất của tất cả các phần tử của mảng

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
int BCNN(int a, int b)
{
	int ucln = UCLN(a, b);
	return a*b/ucln;
}

void bai3()
{
	ifstream filein("input.txt");
	vector<int>a;
	int n;
	filein >> n;
	a.push_back(n);
	while (!filein.eof())
	{
		if (filein)
		{
			char x;
			filein >> x;
			int m;
			filein >> m;
			a.push_back(m);
		}
	}
	int asize = a.size();
	filein.close();
	ofstream out("UCLN.txt");
	int ucln = UCLN(a[0], a[1]);
	int bcnn = BCNN(a[0], a[1]);
	for (int i = 2; i < asize; ++i)
	{
		ucln = UCLN(ucln, a[i]);
		bcnn = BCNN(bcnn, a[i]);
	}
	out << ucln << " ";
	out.close();
	out.open("BCNN.txt", ios_base::out);
	out << bcnn << " ";
	out.close();
	
}


int main()
{
	ifstream thu;
	thu.open("hello.txt", ios::in);
	string h;
	thu >> h;
	cout << h;
	return 0;
}
