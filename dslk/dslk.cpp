// bai 2 + bai 3

#include <iostream>
using namespace std;
//---------- dslk ----
typedef struct node
{
	//data
	int data;
	//pointer
	node* pnext;
}node;

typedef struct dslk
{
	node* phead = NULL;
	node* ptail = NULL;
}dslk;
//=============
void them_cuoi(dslk& ds, int x);
node* khoi_tao_node(int x);//copy
void xuat(dslk ds);//copy
void them_dau(dslk& ds, int x);
void xoa_dau(dslk& ds);
void xoa_cuoi(dslk& ds);
void them_sau_vt(dslk& ds, int vt, int x);//build
void xoa_sau_vt(dslk& ds, int vt);//build
void them_truoc_vt(dslk& ds, int vt, int x);
void xoa_truoc_vt(dslk& ds, int vt);
void xoa_tai_vt(dslk& ds, int vt);
void main()
{
	dslk ds;


	//-----menu --- copy
	bool kt = true;
	while (kt == true)
	{
		system("cls");
		cout << "1. Nhap pt vao dslk" << endl;
		cout << "2. Xuat dslk" << endl;
		cout << "3. Them dau" << endl;
		cout << "4. Xoa dau" << endl;
		cout << "5. Xoa cuoi" << endl;
		cout << "6. Them sau vt" << endl;
		cout << "7. Xoa sau vt" << endl;
		cout << "8. Them truoc vt" << endl;
		cout << "9. Xoa truoc vt" << endl;
		cout << "10. Xoa tai vt" << endl;
		cout << "0. Thoat" << endl;
		int lc; cout << "Nhap lc: "; cin >> lc;
		switch (lc)
		{
		case 1:
		{
			int sl; cout << "Nhap sl pt can them: "; cin >> sl;
			for (int i = 1; i <= sl; i++)
			{
				int x; cout << "Nhap PT " << i << ": "; cin >> x;
				them_cuoi(ds, x);
			}
			break;
		}
		case 2:
		{
			xuat(ds);
			system("pause");
			break;
		}
		case 3:
		{
			int x; cout << "Nhap x: "; cin >> x;
			them_dau(ds, x);
			break;
		}
		case 4:
		{
			xoa_dau(ds);
			break;
		}
		case 5:
		{
			xoa_cuoi(ds);
			break;
		}
		case 6:
		{
			int vt, x;
			cout << "Nhap vt can them: "; cin >> vt;
			cout << "Nhap x: "; cin >> x;
			//---------
			them_sau_vt(ds, vt, x);
			break;
		}
		case 7:
		{
			int vt;
			cout << "Nhap vt can xoa: "; cin >> vt;
			//-----
			xoa_sau_vt(ds, vt);
			break;
		}
		case 8:
		{
			int vt;
			cout << "Nhap vt can: "; cin>> vt;
			int x;
			cout << "\nNhap x: "; cin >> x;
			them_truoc_vt(ds, vt, x);
			system("pause");
			break;
		}
		case 9:
		{
			int vt;
			cout << "Nhap vt can xoa: "; cin >> vt;
			xoa_truoc_vt(ds, vt);
			system("pause");
			break;
		}
		case 10:
		{
			int vt;
			cout << "Nhap vt can xoa: "; cin >> vt;
			xoa_tai_vt(ds, vt);
			system("pause");
			break;
		}
		case 0:
		{
			kt = false;
		}
		}
	}
	system("pause");
}
node* khoi_tao_node(int x)
{
	node* p = new node;//tao khuon
	p->data = x;
	p->pnext = NULL;
	return p;
}
void them_cuoi(dslk& ds, int x)
{
	//B1: Chuyen data -> Node
	node* p = khoi_tao_node(x);
	//B2: Them
	if (ds.phead == NULL)//DSlk rong
	{
		ds.phead = ds.ptail = p;
	}
	else if (ds.phead != NULL)//DSlk co n pt
	{
		ds.ptail->pnext = p;//liên kết pt cuối với p
		ds.ptail = p;//cập nhật ptail
	}
}
void xuat(dslk ds)
{
	int i = 0;
	cout << "\t\t===== DSLK =======" << endl;
	for (node* k = ds.phead; k != NULL; k = k->pnext)
	{
		cout << "PT thu " << i++ << ": " << k->data << endl;
	}
}
void them_dau(dslk& ds, int x)
{
	//B1: chuyen data -> node
	node* p = khoi_tao_node(x);
	//B2: Them
	if (ds.phead == NULL)//Rong
	{
		ds.phead = ds.ptail = p;
	}
	else//co n pt
	{
		p->pnext = ds.phead;//liên kết vs ds
		ds.phead = p;//cập nhật phead
	}
}
void xoa_dau(dslk& ds)
{
	if (ds.phead == ds.ptail && ds.phead != NULL)//1 pt
	{
		delete ds.phead;
		ds.phead = ds.ptail = NULL;//ds rỗng
	}
	else if (ds.phead != ds.ptail)//n pt
	{
		node* tam = ds.phead;//giữ node đầu cần xóa
		ds.phead = ds.phead->pnext;//cập nhật phead ở vt pt thứ 2
		delete[] tam;//thu hồi - xóa
	}
}
void xoa_cuoi(dslk& ds)
{
	if (ds.phead == ds.ptail && ds.phead != NULL)//1 pt
	{
		delete[] ds.phead;
		ds.phead = ds.ptail = NULL;
	}
	else if (ds.phead != ds.ptail)//n pt
	{
		//B1: Tim k - ap cuoi
		for (node* k = ds.phead; k != NULL; k = k->pnext)
		{
			if (k->pnext == ds.ptail)//tim duoc roi
			{
				//---B2: Xoa ptail ------
				delete ds.ptail;
				//---:B3: Cập nhật pnext của k - vì k là pt cuối
				k->pnext = NULL;//k mới là pt cuối

				//---B4: Cap nhat lai pt cuoi(ptail) ----
				ds.ptail = k;
			}
		}

	}
}
void them_sau_vt(dslk& ds, int vt, int x)
{
	if (ds.phead == NULL) return;
	node* p = ds.phead;
	while (p)
	{
		if (p->data == vt)
		{
			if (p->pnext == NULL)
			{
				them_cuoi(ds, x);
				return;
			}
			node* moi = khoi_tao_node(x);
			moi->pnext = p->pnext;
			p->pnext = moi;
			p = p->pnext;
		}
		p = p->pnext;
	}
}
void xoa_sau_vt(dslk& ds, int vt)
{
	if (ds.phead == nullptr || ds.phead->pnext == nullptr) return;
	node* p = ds.phead;
	while (p)
	{
		if (p->data == vt)
		{
			if (p->pnext == ds.ptail)
			{
				xoa_cuoi(ds);
				return;
			}
			else if (p == ds.ptail)
			{
				return;
			}
			else
			{
				node* temp = p->pnext;
				p->pnext = temp->pnext;
				delete temp;
			}
			if (p->pnext->data != vt)
			{
				p = p->pnext;
			}
		}
		else
			p = p->pnext;
	}
}
void them_truoc_vt1(dslk& ds, int vt, int x) // cach 1
{
	if (ds.phead == nullptr) return;
	if (ds.phead->pnext == nullptr && ds.phead->data == vt)
	{
		node* khoitao = khoi_tao_node(x);
		khoitao->pnext = ds.phead;
		ds.phead = khoitao;
		return;
	}
	node* p = ds.phead;
	while (p->pnext)
	{
		if (p == ds.phead && ds.phead->data == vt)
		{
			node* khoitao = khoi_tao_node(x);
			khoitao->pnext = ds.phead;
			ds.phead = khoitao;
		}
		if (p->pnext->data == vt)
		{
			node* khoitao = khoi_tao_node(x);
			khoitao->pnext = p->pnext;
			p->pnext = khoitao;
			p = p->pnext;
		}
		p = p->pnext;
	}
}
void them_truoc_vt2(dslk& ds, int vt, int x) // cach 2: h chay theo k
{

}
void them_truoc_vt(dslk& ds, int vt, int x) // cach 3: copy
{
	if (ds.phead == nullptr) return;
	node* k = ds.phead;
	while (k)
	{
		if (k->data == vt)
		{
			node* p = khoi_tao_node(x);
			int temp = k->data;
			k->data = p->data;
			p->data = temp;
			p->pnext = k->pnext;
			k->pnext = p;
			if (p->pnext == nullptr)
			{
				ds.ptail = p;
			}
			k = k->pnext;
		}
		k = k->pnext;
	}
}
//void xoa_truoc_vt1(dslk& ds, int vt)
//{
//	if (ds.phead == NULL || ds.phead->pnext == NULL ) return;
//	node* k = ds.phead;
//	while (k->pnext->pnext!=nullptr)
//	{
//		if (k->pnext->pnext->data == vt)
//		{
//			node* temp = k->pnext;
//			k->pnext = temp->pnext;
//			delete temp;
//		}
//		else
//			k = k->pnext;
//	}
//	node* p = ds.phead;
//	while (p->pnext->pnext != nullptr)
//	{
//		if (p->pnext->pnext->data == vt)
//		{
//			node* temp = p->pnext;
//			p->pnext = temp->pnext;
//			delete temp;
//		}
//		else
//			p = p->pnext;
//	}
//	if (ds.phead->pnext->data == vt)
//	{
//		// xoa dau
//		xoa_dau(ds);
//	}
//}
//void xoa_truoc_vt2(dslk& ds, int vt) 
//{
//	if (ds.phead == NULL || ds.phead->pnext == NULL) return;
//	node* h = nullptr;
//	node* k = ds.phead;
//	while (k->pnext)
//	{
//		bool kt = false;
//		if (k->pnext->data == vt)
//		{
//			if (k == ds.phead)
//			{
//				xoa_dau(ds);
//				kt = true;
//			}
//			else
//			{
//				h->pnext = k->pnext;
//				delete k;
//				k = h;
//			}
//		}
//		if (kt)
//		{
//			k = ds.phead;
//			h = k;
//		}
//		else
//		{
//			h = k;
//			k = k->pnext;
//		}
//	}
//}
void xoa_truoc_vt2(dslk& ds, int vt) // cach 2: h chay theo k
{
	if (ds.phead == NULL || ds.phead->pnext == NULL) return;
	node* h = nullptr;
	node* k = ds.phead;
	while (k->pnext)
	{
		if (k->pnext->data == vt)
		{
			if (k == ds.phead)
			{
				xoa_dau(ds);
				k = ds.phead;
				h = k;
				continue;
			}
			else
			{
				h->pnext = k->pnext;
				delete k;
				k = h;
			}
		}
		h = k;
		k = k->pnext;
	}
}
void xoa_truoc_vt(dslk& ds, int vt) // cach 3: doi
{
	// b1: doi data tai vt ve truoc no
	// xoa sau vt
	if (ds.phead == NULL || ds.phead->pnext == NULL) return;
	node* k = ds.phead;
	while (k->pnext)
	{
		if (k->pnext->data == vt)
		{
			k->data = vt;
			node* temp = k->pnext;
			k->pnext = temp->pnext;
			delete temp;
			if (k->pnext == nullptr)
			{
				ds.ptail = k;
			}
		}
		else
			k = k->pnext;
	}
}
void xoa_tai_vt1(dslk& ds, int vt) // cach 1: h chay theo k
{
	if (ds.phead == nullptr) return;
	if (ds.phead->data == vt && ds.phead->pnext == NULL)
	{
		ds.phead = nullptr;
		return;
	}
	node* k = ds.phead;
	node* h = NULL;
	while (k)
	{
		if (k->data == vt)
		{
			if (k == ds.phead)
			{
				xoa_dau(ds);
				k = ds.phead;
				h = k;
				continue;
			}
			else
			{
				h->pnext = k->pnext;
				if (k == ds.ptail)
				{
					ds.ptail = h;
				}
				delete k;
				k = h;
			}
		}
		h = k;
		k = k->pnext;
	}
}
void xoa_tai_vt(dslk& ds, int vt) // cach 2: doi
{
	if (ds.phead == nullptr) return;
	if (ds.phead->data == vt && ds.phead->pnext == NULL)
	{
		ds.phead = nullptr;
		return;
	}
	node* k = ds.phead;
	while (k)
	{
		if (k->data == vt)
		{
			if (k == ds.ptail)
			{
				xoa_cuoi(ds);
				return;
			}
			node* temp = k->pnext;
			k->data = temp->data;
			k->pnext = temp->pnext;
			delete temp;
			if (k->pnext == nullptr)
			{
				ds.ptail = k;
			}
		}
		else
			k = k->pnext;
	}
}