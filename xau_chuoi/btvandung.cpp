
////==================== BT VẬN DỤNG =========================
//Xây dựng lại các hàm
//1 / strlen(<chuỗi cần lấy độ dài>) : trả về độ dài của 1 chuỗi
//2 / strcpy(<chuỗi s1>, <chuỗi s2>) : sao chép chuỗi s2 sang cho s1
//3 / strdup(<chuỗi>) : sao chép chuỗi - cấp phát 1 vùng nhớ vừa đủ để chứa cái chuỗi cần sao chép
//4 / strlwr(<chuỗi cần chuyển>) : chuyển chuỗi thành chuỗi in thường
//5 / strupr(<chuỗi cần chuyển>) : chuyển chuỗi thành chuỗi in hoa
//6. strrev(<chuỗi cần đảo ngược>) : đảo ngược 1 chuỗi : abcds->sdcba
//7. strcmp(<chuỗi s1>, <chuỗi s2>) : so sánh có phân biệt hoa thường chuỗi s1 với chuỗi s2
//số, kí tự : > , < == != .    "aB" > "Cd"->ko cho
//8. Thêm kí tự x tại vị trí vt(x, vt nhập từ bàn phím) vào xâu.
//9. Xóa kí tự tại vị trí vt(vt nhập từ bàn phím) trong xâu.

#include <iostream>
using namespace std;
int StringLength(char c[]);
void Strcpy(char a[], char b[]);

int StringLength(char c[])
{
	int l = 0;
	while (c[l] != '\0')
	{
		l++;
	}
	return l;
}
void Strcpy(char a[], char b[])
{
	int n = 0;
	do
	{
		a[n] = b[n];
		n++;
	} while (b[n] != '\0');
	a[n] = '\0';
}
char* Strdup( char b[])
{
	char* s = b;
	return s;
}
void Strlwr(char s[])
{
	int i = 0;
	while (s[i] != '\0')
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			s[i] = s[i] - 32;
		}
	}
}
void Strupr(char s[])
{
	int i = 0;
	while (s[i] != '\0')
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			s[i] = s[i] - 32;
		}
	}
}
void Strrev(char s[])
{
	int n = StringLength(s);
	for (int i = 0; i <= n / 2; i++)
	{
		char c = s[i];
		s[i] = s[n - i - 1];
		s[n - i - 1] = c;
	}
}
int Strcmp(char s1[], char s2[])
{
	int i = 0;
	do
	{
		if (s1[i] > s2[i])
		{
			return 1;
		}
		else if (s1[i] < s2[i])
		{
			return -1;
		}
		i++;
	} while (s1[i] != '\0' || s2[i] != '\0');
	return 0;
}
void ThemKiTu(char s[], int vt, char c)
{
	int n = StringLength(s);
	for (int i = n; i > vt; i--)
	{
		s[i] = s[i - 1];
	}
	s[vt] = c;
	s[n + 1] = '\0';
}
void XoaKiTu(char s[], int vt)
{
	int i;
	for ( i = vt; s[i] != '\0'; i++)
	{
		s[i] = s[i + 1];
	}
}
int main()
{
	char c[] = "HElklo";
	char b[] = "hello";
	XoaKiTu(c, 2);
	cout << c << endl;
	return 0;
}
