#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	int N, sum = 0, weight[17] = { 7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2 };
	char M[11] = { '1', '0', 'X', '9', '8', '7','6', '5', '4', '3', '2' };
	string strId,strnum="1234567890",strId17;
	vector<string> wrongId;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> strId;
		if (strId.size() != 18)
		{
			wrongId.push_back(strId);
			break;
		}
		strId17 = strId.substr(0, 17);
		auto pos = strId17.find_first_not_of(strnum);
		if (pos == string::npos)
		{
			sum = 0;
			for (int j = 0; j < strId17.size(); j++)
			{
				sum = sum + (strId17[j] - '0')*weight[j];
			}
			if (M[sum % 11] != strId[strId.size() - 1])
			{
				wrongId.push_back(strId);
			}
		}
		else
		{
			wrongId.push_back(strId);
		}
	}
	if (wrongId.empty())
	{
		cout << "All passed" << endl;
	}
	else
	{
		for (int i = 0; i < wrongId.size();i++)
		{
			cout << wrongId[i] << endl;
		}
	}
	return 0;

}