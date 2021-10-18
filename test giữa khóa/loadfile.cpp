#include "mylib.h"

void load_ds_mh(danh_sach_mh& ds_mh)
{
	ifstream filein("ds_mh.txt");
	//------ doc file ----
	while (!filein.eof())
	{
		mon a;//lưu tạm dữ liệu load từ file
		getline(filein, a.ma_mh, ',');
		getline(filein, a.ten_mh, ',');
		filein >> a.stclt;
		filein.ignore();//bỏ phẩy
		filein >> a.stcth;
		filein.ignore();// xuống dòng
		//------- thêm ------
		ds_mh.ds[ds_mh.sl++] = a;
	}
	filein.close();
}
void load_ds_lop(danh_sach_lop& ds_lop)
{
	ifstream filein("ds_lop.txt");
	//------ doc file ----
	while (!filein.eof())
	{
		lop a;//lưu tạm dữ liệu load từ file

		getline(filein, a.ma_lop, ',');
		getline(filein, a.ten_lop, ',');
		filein >> a.nien_khoa;
		filein.ignore();// xuống dòng
						//------- thêm ------
		ds_lop.ds[ds_lop.sl++] = a;
	}
	filein.close();
}
void load_ds_sv(danh_sach_lop& ds_lop)
{
	ifstream filein("ds_sv.txt");
	//------ doc file ----
	for (int i = 0; i < ds_lop.sl; i++)
	{
		//tại lớp thứ i sẽ load ds sv vào ??? bao nhiêu sv ???
		int n;
		filein >> n;//n sv
		filein.ignore();//xuống dòng
		for (int j = 1; j <= n; j++)//lặp lại n lần việc load sv
		{
			//---- load 1 sv ----
			sv a;
			getline(filein, a.ma_sv, ',');
			getline(filein, a.ho, ',');
			getline(filein, a.ten, ',');
			getline(filein, a.phai, ',');
			getline(filein, a.sdt);//lẤy đến \n dừng -> bỏ qua \n
			//---- them sv ---
			them_sv(ds_lop.ds[i].ds_sv, a);
		}
	}
	while (!filein.eof())
	{
		lop a;//lưu tạm dữ liệu load từ file
		getline(filein, a.ma_lop, ',');
		getline(filein, a.ten_lop, ',');
		filein >> a.nien_khoa;
		filein.ignore();// xuống dòng
						//------- thêm ------
		ds_lop.ds[ds_lop.sl++] = a;
	}
	filein.close();
}