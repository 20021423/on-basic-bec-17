#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct ATM
{
	string ID;
	string pass;
	string PIN;
	double Money = 0;
};
struct TienATM
{
	int n10k = 0;
	int n20k = 0;
	int n50k = 0;
	int n100k = 0;
	int n200k = 0;
	int n500k = 0;
};

void DocTien(ATM& x)
{
	ifstream filein;
	filein.open(x.ID + ".txt");
	if (filein.fail()) {
		return;
	}
	filein >> x.Money;
	filein.close();
}

bool RutTien(ATM& x, TienATM &n)
{
	int tien;
	cout << "Nhap so tien muon rut: ";
	cin >> tien;
	DocTien(x);
	if (tien > x.Money) return false;
	while (tien > 0)
	{

	}

}

int main()
{
    int a[6]={500000,200000,100000,50000,20000,10000};
    int sotorutdc=0;
    int n;
    cout<<"Nhap so tien muon rut: ";
    cin>>n;
    for(int i=0;i<6;i++)
    {
        sotorutdc += n/a[i];
        n = n%a[i];
    }
    if(n!=0) cout<<"Khong rut dc";
    else cout<<"rut dc"<<endl<<sotorutdc;
    return 0;
}
