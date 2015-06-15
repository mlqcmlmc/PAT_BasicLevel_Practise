#include<iostream>
#include<map>
#include<string>
using namespace std;
int main()
{
	int lacksum = 0;
	string str1, str2;
	cin >> str1 >> str2;
	map<char, int> strmap1, strmap2;
	for (int i = 0; i < str1.size(); i++)
	{
		strmap1[str1[i]]++;
	}
	for (int i = 0; i < str2.size(); i++)
	{
		strmap2[str2[i]]++;
	}
	auto it = strmap2.begin();
	while (it != strmap2.end())
	{
		if (it->second>strmap1[it->first])
		{
			lacksum += it->second - strmap1[it->first];
		}
		++it;
	}
	if (lacksum == 0)
	{
		cout << "Yes" << ' ' << str1.size() - str2.size() << endl;
	}
	else
	{
		cout << "No" << ' ' << lacksum << endl;
	}
	return 0;
}