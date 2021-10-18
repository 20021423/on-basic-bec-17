#pragma once
//https://paste.ubuntu.com/p/8Wvy8tRJKQ/
/*1. Không nhìn lý thuyết, tự phân tích các trường hợp khi xử lý xóa sau vt.
TH1: rỗng return luôn
TH2 : có 1 phần tử : cập nhật phead = ptail = null, rồi giải phóng
TH3 : có nhiều phần tử
	+) vt ở đầu + vt ở giữa: 
	{
		node *temp = p->next; // luu lai bien tam
		p->next = temp->next; // xoa
		delete temp;
	}
	+) vt o cuoi  return luon
	+) vt o vi tri ap cuoi (xoa cuoi)
	{
		C1: co the dung luon ham xoa cuoi
		C2:
		node *temp = p->next; // luu lai bien tam
		p->next = temp->next; // xoa
		if(p->next==null)
		{
			p = ptail;
		}
		delete temp;
	} 


*/

// https://paste.ubuntu.com/p/WFskVhjx2F/
/*
	1. Không nhìn lý thuyết, tự phân tích các trường hợp khi xử lý thêm trước vt.
	th1: 0 phần tử => return luôn
	th2: 1 phần mà có giá trị là vt => đưa về bài toán thêm đầu
	th3: có 2 phần tử trở lên 
		- nếu phần tử đầu tiên có giá trị vt thì đưa về bài toán thêm đầu
		- xử lý các phần tử từ thứ 2 về cuối danh sách

*/