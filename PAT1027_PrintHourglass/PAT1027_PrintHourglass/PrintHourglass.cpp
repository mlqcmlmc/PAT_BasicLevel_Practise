#include<iostream>
#include<string>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
	int N,row;
	char printchar;
	string strprint;
	cin >> N >> printchar;
	row = sqrt((N + 1) / 2);
	int blankNum , charNum = 2 * row - 1;
	for (blankNum = 0; blankNum < row; blankNum++, charNum--, charNum--)
	{
		strprint.insert(strprint.end(), blankNum, ' ');
		strprint.insert(strprint.end(), charNum, printchar);
		cout << strprint << endl;
		strprint.clear();
	}
	for (blankNum = row - 2, charNum = 3; blankNum >= 0 ; charNum++, charNum++, blankNum--)
	{
		strprint.insert(strprint.end(), blankNum, ' ');
		strprint.insert(strprint.end(), charNum, printchar);
		cout << strprint << endl;
		strprint.clear();
	}
	int surplus = N - (2 * (row * row )- 1);
	cout << surplus<<endl;
	return 0;
}