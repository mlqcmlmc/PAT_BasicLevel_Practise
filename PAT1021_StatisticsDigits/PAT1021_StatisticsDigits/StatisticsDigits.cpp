#include <iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
	map<char, int> countAllNum = { { '0', 0 }, { '1', 0 }, { '2', 0 }, { '3', 0 }, { '4', 0 }, { '5', 0 }, { '6', 0 }, { '7', 0 }, { '8', 0 }, { '9', 0 } };
	string strAll;
	cin >> strAll;
	for (auto &strone : strAll)
	{
		countAllNum[strone]++;
	}
	auto mapit = countAllNum.begin();
	while (mapit!=countAllNum.end())
	{
		if (mapit->second!=0)
		{
			cout << mapit->first << ':' << mapit->second << endl;
		}
		++mapit;
	}
	return 0;
}