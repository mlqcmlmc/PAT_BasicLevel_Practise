#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	int num;
	string strMinNum;
	for (int i = 0; i < 10; i++)
	{
		cin >> num;
		for (int j = 0; j < num; j++)
		{
			strMinNum.push_back(i + '0');
		}
	}
	//sort(strMinNum.begin(), strMinNum.end());
	if (strMinNum.empty())
	{
		strMinNum.push_back('0');
	}
	else if (strMinNum[0] == '0')
	{
		auto pos=strMinNum.find_first_not_of('0');
		char c = strMinNum[pos];
		strMinNum.erase(pos, 1);
		strMinNum.insert(strMinNum.begin(), c);
	}
	cout << strMinNum << endl;
	return 0;
}