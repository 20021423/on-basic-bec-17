#include<iostream>
#include<cmath>


using namespace std;
int giaithua(int n)
{   int tich = 1;
    for (int i = 1; i <=n; i++)
    {
        tich = tich* i;
    }
    return tich;
}

int main(){
    int n, k, C;
     int x ;

    do
    {
        cin >> n >> k;
        if(n <= 0 || k <= 0 )
        {
            cout <<"Nhap lai gia tri n va k";
            cin >> n >> k;
        }
    }while(n <= 0 || k <= 0 );
    if (k == 1)
    {
        C = n;
      int x = C % (int ((pow(10, 9))+7));
    }
    else if(k == 2)
    {
        C = ((n - 1) * (n - 2)) / 2;
      int x = (C % (int ((pow(10, 9))+7)));

    }
    else (k >= 3)
    {
        C = ((giaithua(n))/(giaithua(k) * giaithua(n-k))) - pow((n-k), 2);
        int x = (C % (int ((pow(10, 9))+7)));

    }
    cout <<" Ket qua cua bai toan la:"<<x;
    return 0;
}
