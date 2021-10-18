//99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999923
//Bài 2. Nhập vào 1 chuỗi từ bàn phím.Viết hàm chuẩn hóa chuỗi vừa nhập theo yêu cầu sau :
//+Không tồn tại kí tự khoảng trắng ở đầu chuỗi
//+ Không tồn tại kí tự khoảng trắng ở cuối chuỗi
//+ Mỗi từ chỉ cách nhau 1 kí tự khoảng trắng
//+ Viết hoa kí tự đầu của mỗi từ
//Ví dụ :
//s = "   Ki       thuat lap         trinh     "
//== = > sau khi chuẩn hóa : s = "Ki Thuat Lap Trinh"
#include <iostream>
#include <string.h>
#define MAX 100
using namespace std;

void XoaKiTuSpace(char c[], int& n)
{
    int i = 0;
    while (i < n)
    {
        if (c[i] == ' ' && c[i + 1] == ' ')
        {
            for (int j = i; j < n; j++)
            {
                c[j] = c[j + 1];
            }
            n--;
            i--;
        }
        i++;
    }
    if (c[0] == ' ' && c[1] != '\0')
    {
        for (int j = 0; j < n; j++)
        {
            c[j] = c[j + 1];
        }
        n--;
    }
    if (c[n - 1] == ' ')
    {
        c[n - 1] = '\0';
    }
}

void ChuanHoaXau(char c[], int& n)
{
    XoaKiTuSpace(c, n);
    if (c[0] >= 'a' && c[0] <= 'z')
    {
        c[0] -= 32;
    }
    for (int i = 1; i < n; i++)
    {
        if (c[i] == ' ')
        {
            if (c[i + 1] >= 'a' && c[i + 1] <= 'z')
            {
                c[i + 1] -= 32;
            }
            i++;
        }
        else if (c[i] != ' ')
        {
            if (c[i] >= 'A' && c[i] <= 'Z')
            {
                c[i] += 32;
            }
        }
    }
}

int main()
{
    char c[MAX] = "";
    gets_s(c);
    int n = strlen(c);
    ChuanHoaXau(c, n);
    cout << c << endl;

    return 0;
}
