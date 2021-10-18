#include "mylib.h"

void menu()
{
	//--- setting ----
	danh_sach_mh ds_mh;
	danh_sach_lop ds_lop;
	//---- loadfile ---
	load_ds_mh(ds_mh);
	load_ds_lop(ds_lop);
	load_ds_sv(ds_lop);
	//---- play ----
	bool kt_menu = true;
	while (kt_menu == true)
	{
		system("cls");
		cout << "1. Nhap mon hoc" << endl;
		cout << "2. Xuat danh sach mon hoc" << endl;
		cout << "3. Nhap lop" << endl;
		cout << "4. Xuat danh sach lop" << endl;
		cout << "5. Them sinh vien" << endl;
		cout << "6. Xuat danh sach sinh vien" << endl;
		cout << "0. Thoat" << endl;
		int lc;
		cout << "Nhap lc: "; cin >> lc;
		switch (lc)
		{
		case 1:
		{
			int sl = 0;
			cout << "Nhap sl mon can nhap: "; cin >> sl;

			for (int i = 1; i <= sl; i++)
			{
				cin.ignore();//xóa cho mỗi thằng
				cout << "\t\t-------- Nhap mon " << i << " --------" << endl;
				//------------- Nhap 1 mon ------------
				mon a;//lưu tạm dữ liệu người dùng nhập vào
				cin >> a;
				//---- thêm cuối -----
				ds_mh.ds[ds_mh.sl++] = a;
			}

			break;
		}
		case 2:
		{
			xuat_ds_mh(ds_mh);
			system("pause");
			break;
		}
		case 3:
		{
			int sl = 0;
			cout << "Nhap sl mon can nhap: "; cin >> sl;

			for (int i = 1; i <= sl; i++)
			{
				cin.ignore();//xóa cho mỗi thằng
				cout << "\t\t-------- Nhap lop " << i << " --------" << endl;
				//------------- Nhap 1 mon ------------
				lop a;//lưu tạm dữ liệu người dùng nhập vào
				cin >> a;
				//---- thêm cuối -----
				ds_lop.ds[ds_lop.sl++] = a;
			}

			break;
		}
		case 4:
		{
			xuat_ds_lop(ds_lop);
			system("pause");
			break;
		}
		case 5:
		{
			string s;//lưu mã lớp cần nhập ds sinh viên
			cin.ignore();
			cout << "Nhap ma lop can them sinh vien: "; getline(cin, s);
			int i = kt_trung_ma_lop(ds_lop, s);
			if (i == -1)
			{
				cout << "Ma lop khong ton tai!" << endl;
				system("pause");
			}
			else//trùng
			{
				//thêm sinh viên cho lớp thứ i	:	ds_lop.ds[i]

				int sl;
				cout << "Nhap sl sv can them: "; cin >> sl;
				cin.ignore();//chỉ xóa cho sv đầu tiên
				for (int j = 1; j <= sl; j++)
				{
					cout << "\t\t------ Nhap sv " << j << " -----------" << endl;
					//---- nhap 1 sv ---
					sv a;//lưu tạm dữ liệu người dùng nhập vào
					cin >> a;
					//---- thêm ----
					them_sv(ds_lop.ds[i].ds_sv, a);
				}
			}
			break;
		}
		case 6:
		{
			xuat_ds_sv(ds_lop);
			system("pause");
			break;
		}
		case 0:
		{
			kt_menu = false;
			break;
		}
		}
	}
}
istream& operator >>(istream& is, mon& a)
{
	cout << "Nhap ma mon hoc: "; getline(is, a.ma_mh);
	cout << "Nhap ten mon hoc: "; getline(is, a.ten_mh);
	cout << "Nhap so tin chi ly thuyet: "; is >> a.stclt;
	cout << "Nhap so tin chi thuc hanh: "; is >> a.stcth;
	return is;
}
ostream& operator << (ostream& os, mon a)
{
	cout << "Ma mon: " << a.ma_mh << endl;
	cout << "Ten mon: " << a.ten_mh << endl;
	cout << "So tin chi ly thuyet: " << a.stclt << endl;
	cout << "So tin chi thuc hanh: " << a.stcth << endl;
	return os;
}
void xuat_ds_mh(danh_sach_mh ds_mh)
{
	cout << "\t\t========= Xuat Danh Sach mon hoc =========" << endl;
	for (int i = 0; i < ds_mh.sl; i++)
	{
		cout << "\t\t----- Mon: " << i << " ---------" << endl;
		cout << ds_mh.ds[i];
	}

	/*for each (mon i in ds_mh.ds)
	{
		cout << "\t\t----- Mon: " << i << " ---------" << endl;
		cout << i;
	}*/
}
//============== lop ===============
istream& operator >> (istream& is, lop& a)
{
	cout << "Nhap ma lop: "; getline(is, a.ma_lop);
	cout << "Nhap ten lop: "; getline(is, a.ten_lop);
	cout << "Nhap nien khoa: "; is >> a.nien_khoa;
	return is;
}
ostream& operator << (ostream& os, lop a)
{
	cout << "Ma lop: " << a.ma_lop << endl;
	cout << "Ten lop: " << a.ten_lop << endl;
	cout << "Nien khoa: " << a.nien_khoa << endl;
	return os;
}
void xuat_ds_lop(danh_sach_lop ds_lop)
{
	cout << "\t\t========= Xuat Danh Sach lop =========" << endl;
	for (int i = 0; i < ds_lop.sl; i++)
	{
		cout << "\t\t----- Lop: " << ds_lop.ds[i].ten_lop << " ---------" << endl;
		cout << ds_lop.ds[i];
	}

}
//============= Nhap sv ===============
int kt_trung_ma_lop(danh_sach_lop ds_lop, string a)
{
	for (int i = 0; i < ds_lop.sl; i++)
	{
		if (_stricmp(ds_lop.ds[i].ma_lop.c_str(), a.c_str()) == 0)
		{
			return i;
		}
	}
	return -1;//không tồn tại
}
//---- nhap 1 sv -------
istream& operator >> (istream& is, sv& a)
{
	cout << "Nhap ma sv: "; getline(is, a.ma_sv);
	cout << "Nhap ho: "; getline(is, a.ho);
	cout << "Nhap ten: "; getline(is, a.ten);
	cout << "Nhap phai: "; getline(is, a.phai);
	cout << "Nhap sdt: "; getline(is, a.sdt);
	return is;
}
node_sv* khoi_tao_node_sv(sv a)
{
	node_sv* p = new node_sv;
	p->data = a;
	p->pnext = NULL;
	return p;
}
void them_sv(danh_sach_sv& ds_sv, sv a)
{
	node_sv* p = khoi_tao_node_sv(a);
	if (ds_sv.phead == NULL)
	{
		ds_sv.phead = ds_sv.ptail = p;
	}
	else
	{
		ds_sv.ptail->pnext = p;//liên kết
		ds_sv.ptail = p;//cập nhật ptail
	}
}
//========================= xuat ds sv============
ostream& operator << (ostream& os, sv a)
{
	cout << "Ma sv: " << a.ma_sv << endl;
	cout << "Ho ten: " << a.ho << " " << a.ten << endl;
	cout << "Phai: " << a.phai << endl;
	cout << "SDT: " << a.sdt << endl;
	return os;
}
void xuat_ds_sv_1_lop(danh_sach_sv ds_sv)
{
	cout << "\t\t============= Xuat danh sach sinh vien ======" << endl;
	for (node_sv* k = ds_sv.phead; k != NULL; k = k->pnext)
	{
		cout << "\t\t--------- SV: " << k->data.ma_sv << " ---------" << endl;
		cout << k->data;
	}
}
void xuat_ds_sv(danh_sach_lop ds_lop)
{
	for (int i = 0; i < ds_lop.sl; i++)
	{
		cout << "\t\t======= Danh sach sinh vien lop: " << ds_lop.ds[i].ten_lop << " ========" << endl;
		for (node_sv* k = ds_lop.ds[i].ds_sv.phead; k != NULL; k = k->pnext)
		{
			cout << "\t\t--------- SV: " << k->data.ma_sv << " ---------" << endl;
			cout << k->data;
		}
	}
}