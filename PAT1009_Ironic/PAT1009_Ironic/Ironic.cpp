#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	string wordLine;
	getline(cin, wordLine);
	auto pos = wordLine.rfind(' ');
	while (pos != string::npos)
	{
		string temp(wordLine, pos + 1);
		cout << temp << ' ';
		wordLine.erase(pos);
		pos = wordLine.rfind(' ');
	}
	cout << wordLine << endl;
	return 0;
}