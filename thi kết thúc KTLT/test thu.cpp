// https://paste.ubuntu.com/p/pQgrrtTMJF/

#include <iostream>
#include <string>
using namespace std;

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
	return s.substr(index, i);
}
string CatNam(const string& s)
{
	int n = s.length();
	int i = n-1;
	while (s[i] != '/')
	{
		i--;
	}
	return s.substr(i);
}

int main()
{
	string s;
	getline(cin,s);
	cout<<CatNam(s)<<endl<<CatNgay<<endl<<CatThang;
	return 0;
}
