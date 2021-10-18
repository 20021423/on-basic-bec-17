// https://paste.ubu;
// ntu.com/p/3vR3FkKmKB/?fbclid=IwAR29fzSxkue9ndJI3smL6Hw1mw2K5CPt3triDIZyiCoR9-lzUwXT0XU7mOA
//Quản lý danh sách sinh viên.
//Sinh viên gồm : họ tên, tuổi, phái, điểm trung bình
//
//1. viết hàm nhập danh sách sinh viên
//2. viết hàm xuất danh sách sinh viên
//3. sắp xếp danh sách sinh viên tăng dần theo điểm trung bình
//4. sắp xếp danh sách sinh viên giảm dần theo tên, nếu trùng thì theo họ đệm

#include "struct.h"


string ChuanHoaChuoi(string s) // chuoi khong phan biet in hoa thuong khi so sanh
{
	int n = s.length();
	for (int i = 0; i < n; i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			s[i] -= 32;
		}
	}
	return s;
}
bool HoTenSinhVien(string s) // ham nay de check xem co ki tu khong phai letter 
{

	int n = s.length();
	int i = 0;
	while (i < n)
	{
		if (s[i] < 65 || (s[i] > 90 && s[i] < 97) || s[i] > 122)
		{
			return false;
		}
		i++;
	}
	return true;
}

void NhapSinhVien(sv& a)
{
	cin.ignore();
	do
	{
		cout << "Nhap ho ten: ";
		getline(cin, a.hoten);
	} while (!HoTenSinhVien(a.hoten)); // neu ho ten chua ki tu khong phai letter thi bat nhap lai
	cout << "\nNhap tuoi: ";
	cin >> a.tuoi;
	cin.ignore();
	cout << "\nNhap gioi tinh: ";
	getline(cin, a.sex);
	cout << "\nNhap GPA: ";
	cin >> a.GPA;
	cout << endl;
}
void NhapDanhSachSinhVien(sv ds[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap thong tin sinh vien thu " << i + 1 << endl;
		NhapSinhVien(ds[i]);
	}
}
void XuatSinhVien(sv a)
{
	cout << "ho ten: ";
	cout << a.hoten;
	cout << "\ntuoi: ";
	cout << a.tuoi;
	cout << "\ngioi tinh: ";
	cout << a.sex;
	cout << "\nGPA: ";
	cout << a.GPA;
	cout << endl;
}
void XuatDanhSachSinhVien(sv ds[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Thong tin sinh vien thu " << i + 1 << endl;
		XuatSinhVien(ds[i]);
	}
}
void DoiCho_struct(sv& a, sv& b)
{
	sv temp = a;
	a = b;
	b = temp;
}
void SapXepTheo_GPA(sv ds[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (ds[i].GPA > ds[j].GPA)
			{
				DoiCho_struct(ds[i], ds[j]);
			}
		}
	}
}
string CatTenChuoi(const string& s)
{
	// substr(a,b) cat chuoi tu vi tri a va co do dai b
	// substr(a) cat tu vi tri a den het chuoi goc
	// substr() cat chuoi tu vi tri 0 hen het
	int n = s.length();
	int i = n - 1;
	while (i > 0)
	{
		i--;
		if (s[i] == ' ')
		{
			i++;
			break;
		}
	}
	return s.substr(i);
}
string CatTenDem(const string& s)
{
	int n = s.length();
	int i = n - 1;
	int dem = 0;
	while (i > 0)
	{
		i--;
		if (s[i] == ' ')
		{
			dem++;
			if (dem == 2)
			{
				i++;
				break;
			}
		}
	}
	return s.substr(i);
}
void SapXepTheo_Ten_TenDem(sv ds[], int n)
{
	for (int i = 0; i < n; i++)
	{
		string s1 = CatTenChuoi(ds[i].hoten);
		s1 = ChuanHoaChuoi(s1);
		for (int j = i + 1; j < n; j++)
		{
			string s2 = CatTenChuoi(ds[j].hoten);
			s2 = ChuanHoaChuoi(s2);
			if (s1 < s2)
			{
				DoiCho_struct(ds[i], ds[j]);
			}
			else if (s1 == s2)
			{
				s1 = CatTenDem(ds[i].hoten);
				s2 = CatTenDem(ds[j].hoten);
				s1 = ChuanHoaChuoi(s1);
				s2 = ChuanHoaChuoi(s2);
				if (s1 < s2)
					DoiCho_struct(ds[i], ds[j]);
			}
		}
	}
}
int main()
{
	sv ds[MAX];
	bool kt = true;
	int n = 0;
	do
	{
		system("cls");
		cout << "              ---------MENU-----------              \n";
		cout << "\n1. Nhap danh sach sinh vien";
		cout << "\n2. Xuat danh sach sinh vien";
		cout << "\n3. Sap xep tang dan theo GPA";
		cout << "\n4. Sap xep giam dan theo ten";
		cout << "\n0. Thoat chuong trinh\n";
		cout << "\nNhap lua chon: ";
		int choice;
		cin >> choice;
		cin.ignore();
		switch (choice)
		{
		case 1:
			{
				cout << "Nhap so luong sinh vien: ";
				cin >> n;
				NhapDanhSachSinhVien(ds, n);
				break;
			}
		case 2:
			{
			if (n == 0) break;
			cout << "\nDanh sach sinh vien: \n";
			XuatDanhSachSinhVien(ds, n);
			system("pause");
			break;
			}
		case 3:
		{
			if (n == 0) break;
			cout << "\nDanh sach sap xep tang dan theo GPA la: \n";
			SapXepTheo_GPA(ds, n);
			XuatDanhSachSinhVien(ds, n);
			system("pause");
			break;
		}
		case 4:
		{
			if (n == 0) break;
			cout << "\nDanh sach sap xep giam dan theo ten la: \n";
			SapXepTheo_Ten_TenDem(ds, n);
			XuatDanhSachSinhVien(ds, n);
			system("pause");
			break;
		}
		case 0:
		{
			cout << "\ndo you really want to exit ?\n";
			cout << "Please enter your lastest choice \n1.Yes 2.No\n";
			cin >> choice;
			if (choice == 1)
			{
				kt = false;
			}
		}
		}
	} while (kt);
	
	return 0;
}

