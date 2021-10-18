#include <iostream>
#include <vector>
using namespace std;
void nhap(vector<int>& a);
void xuat(vector<int> a);
void HamErase(vector<int>& a);
void main()
{
	vector<int> a;//khai báo 1 biến a kdl vector (hỗ trợ mảng) - lưu trữ các pt là số nguyên
	a.resize(7);//tương đương realloc()
	//---------------
	nhap(a);
	xuat(a);
	int b[] = { 10,11,12,13,14,15 };
	a.insert(a.begin() + 2, b+2,b+5);
	xuat(a);
	system("pause");
}
void nhap(vector<int>& a)
{
	cout << "\t\t-------- nhap --------" << endl;
	for (int i = 0; i < a.size(); i++)
	{
		cin >> a[i];

	}
}
void xuat(vector<int> a)
{
	cout << "\t\t-------- xuat --------" << endl;
	for (int i = 0; i < a.size(); i++)
	{
		cout << a.at(i) << endl;
	}
}
void HamErase(vector<int>&a)
{
	a.erase(a.begin() + 2, a.begin() + 5); // xóa phần tử a[2] đến a[5-1];
	a.erase(a.begin() + 3); // xóa phần tử vị trí 3
}
void HamInsert(vector <int>& a)
{
	a.insert(a.begin() + 2, 5); // chen gia tri 5 vao a[2]
	a.insert(a.begin() + 2, 3, 4); // chen 3 lan gia tri 4 vao a[2]
	a.insert(a.begin() + 1, a.begin() + 2, a.begin() + 3);
}