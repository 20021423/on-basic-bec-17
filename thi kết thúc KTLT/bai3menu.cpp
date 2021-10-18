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
		if (s[i] == ' ') i++;
		if (s[i] < 65 || (s[i] > 90 && s[i] < 97) || s[i] > 122 )
		{
			return false;
		}
		i++;
	}
	return true;
}
void NhapSinhVien(sv& x)
{
	do {
		cout << "Nhap ho ten:";
		getline(cin, x.HoTen);
	} while (!HoTenSinhVien(x.HoTen));
	cout << "Gioi tinh: ";
	getline(cin, x.sex);
	cout << "MSSV: ";
	getline(cin, x.MSSV);
	cout << "Ngay thang nam sinh: ";
	getline(cin, x.birthday);
}
void NhapDanhSachSinhVien(sv ds[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap thong tin sinh vien thu " << i + 1 << endl;
		NhapSinhVien(ds[i]);
	}
}
void NhapDiemChoSinhVien(sv& x)
{
	cout << "\nDiem Mac: ";
	cin >> x.diem.Mac;
	cout << "\Diem dai so: ";
	cin >> x.diem.DaiSo;
	cout << "\nDiem c++ ";
	cin >> x.diem.Cpp;
	cin.ignore();
}
void XuatSinhVien(sv x)
{
	cout << "Ho ten: ";
	cout << x.HoTen << endl;
	cout << "Gioi tinh: ";
	cout << x.sex << endl;
	cout << "MSSV: ";
	cout << x.MSSV << endl;
	cout << "Ngay thang nam sinh: ";
	cout << x.birthday << endl;
	cout << "Diem Mac,Dai so, C++ " << x.diem.Mac << " " << x.diem.DaiSo << " " << x.diem.Cpp << endl;
}
void XuatDanhSachSinhVien(sv ds[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Thong tin sinh vien thu " << i + 1 << endl;
		XuatSinhVien(ds[i]);
	}
}
void Xoa(sv ds[], int& n, int vt)
{
	for (int i = vt; i < n; i++)
	{
		ds[i] = ds[i + 1];
	}
	n--;
}
string CatTen(const string& s)
{
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
string CatHo(const string& s)
{
	int i = 0;
	int n = s.length();
	while (i < n)
	{
		i++;
		if (s[i] == ' ')
		{
			break;
		}
	}
	return s.substr(0, i);
}
void DoiCho_struct(sv& a, sv& b)
{
	sv temp = a;
	a = b;
	b = temp;
}
void SapXepTheo_Ten_Ho(sv ds[], int n)
{
	for (int i = 0; i < n; i++)
	{
		string s1 = CatTen(ds[i].HoTen);
		s1 = ChuanHoaChuoi(s1);
		for (int j = i + 1; j < n; j++)
		{
			string s2 = CatTen(ds[j].HoTen);
			s2 = ChuanHoaChuoi(s2);
			if (s1 > s2)
			{
				DoiCho_struct(ds[i], ds[j]);
			}
			else if (s1 == s2)
			{
				s1 = CatHo(ds[i].HoTen);
				s2 = CatHo(ds[j].HoTen);
				s1 = ChuanHoaChuoi(s1);
				s2 = ChuanHoaChuoi(s2);
				if (s1 > s2)
					DoiCho_struct(ds[i], ds[j]);
			}
		}
	}
}
string CatNgay(const string& s)
{
	int n = s.length();
	int i = 0;
	while (s[i]!='/')
	{
		i++;
	}
	return s.substr(0, i);
}
string CatThang(const string& s)
{
	int n = s.length();
	int i = 0;
	int dem = 0;
	int index = 0;
	while (i < n)
	{
		if (s[i] == '/')
		{
			dem++;
			if (dem == 1)
			{
				index = i + 1;
			}
			if (dem == 2)
			{
				break;
			}
		}
		i++;
	}
	return s.substr(index, i-index);
}
string CatNam(const string& s)
{
	int n = s.length();
	int i = n-1;
	while (s[i] != '/')
	{
		i--;
	}
	return s.substr(i+1);
}
void SapXepTheoNgayThangNam(sv ds[], int n)
{
	for (int i = 0; i < n; i++)
	{
		string s1 = CatNam(ds[i].birthday);
		for (int j = i + 1; j < n; j++)
		{
			string s2 = CatNam(ds[j].birthday);
			if (s1 > s2)
			{
				DoiCho_struct(ds[i], ds[j]);
			}
			else if (s1 == s2)
			{
				s1 = CatThang(ds[i].birthday);
				s2 = CatThang(ds[j].birthday);
				if (s1 > s2)
				{
					DoiCho_struct(ds[i], ds[j]);
				}
				else if (s1 == s2)
				{
					s1 = CatNgay(ds[i].birthday);
					s2 = CatNgay(ds[j].birthday);
					if (s1 > s2)
					{
						DoiCho_struct(ds[i], ds[j]);
					}
				}
			}
		}
	}
}

void menu(sv ds[], int& n)
{
	DocFile(ds, n);
	bool kt = true;
	do
	{
		system("cls");
		cout << "--------------MENU---------------" << endl;
		cout << "\n1.Nhap danh sach sinh vien: ";
		cout << "\n2.Xuat danh sach sinh vien: ";
		cout << "\n3.Xoa sinh vien co MSSV nhap tu ban phim";
		cout << "\n4.Sap xep sinh vien tang dan theo ten, ho";
		cout << "\n5.Nhap diem cho sinh vien co MSSV nhap tu ban phim";
		cout << "\n6.Sap xep danh sach sinh vien tang dan theo ngay thang nam";
		cout << "\n0.Thoat chuong trinh:";
		cout << "\nNhap lua chon: ";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cout << "\nNhap so luong sinh vien: \n";
			cin >> n;
			cin.ignore();
			NhapDanhSachSinhVien(ds, n);
			break;
		}
		case 2:
		{
			if (n == 0) break;
			cout << "\nDanh sach sinh vien\n";
			XuatDanhSachSinhVien(ds, n);
			system("pause");
			break;
		}
		case 3:
		{
			if (n == 0) break;
			cout << "\nNhap MSSV sinh vien muon xoa: \n";
			cin.ignore();
			string s;
			getline(cin, s);
			for (int i = 0; i < n; i++)
			{
				if (ds[i].MSSV == s)
				{
					Xoa(ds, n, i);
				}
			}
			break;
		}
		case 4:
		{
			SapXepTheo_Ten_Ho(ds, n);
			break;
		}
		case 5:
		{
			cout << "Nhap MSSV can nhap diem: ";
			cin.ignore();
			string s;
			getline(cin, s);
			for (int i = 0; i < n; i++)
			{
				if (ds[i].MSSV == s)
				{
					NhapDiemChoSinhVien(ds[i]);
					break;
				}
			}
			break;
		}
		case 6:
		{
			SapXepTheoNgayThangNam(ds, n);
			cout << "\nDanh sach sap xep sinh vien theo sinh nhat la: \n";
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
}
void DocFile(sv ds[], int &n)
{
	ifstream filein;
	filein.open("input.txt", ios_base::in);
	int sl;
	filein >> sl;
	filein.ignore();
	for (int i = 1; i <= sl; i++)
	{
		sv x;
		getline(filein, x.HoTen, ',');
		getline(filein, x.sex, ',');
		getline(filein, x.birthday, ',');
		getline(filein, x.MSSV,'\n');
		ds[n++] = x;
	}
	filein.close();
}
int main()
{
	sv ds[MAX];
	int n = 0;
	menu(ds, n);
	return 0;
}