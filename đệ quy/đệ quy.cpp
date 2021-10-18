#include <iostream>
#include <vector>
#include <string>
using namespace std;
void Reverse(string sentence) {
	vector<string> k;
	string str = "";
	for (int i = 0; i < sentence.size(); i++)
		if (sentence[i] == ' ') {
			k.push_back(str);
			str = "";
		}
		else {
			str += sentence[i];
		}
	k.push_back(str);
	for (int i = k.size() - 1; i > 0; i--)
		cout << k[i] << " ";
	cout << k[0] << endl;
}
int main()
{
	string sentence;
	getline(cin, sentence);
	Reverse(sentence);
	return 0;
}
