#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
	ifstream k;
	string s;
	cin >> s;
	k.open(s, ios_base::in);
	int n;
	k >> n;
	vector<int> a;
	for (int i = 0; i < n; i++)
	{
		int m;
		k >> m;
		a.push_back(m);
	}
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}

