#include<iostream>
#include<string>
#include<algorithm>
#include "stdio.h";
using namespace std;
string inttostring(int num)
{
	string value;
	for (int i = 0; i < 4;i++)
	{
		value.push_back(num % 10 + '0');
		num = num / 10;
	}
	reverse(value.begin(), value.end());
	return value;
}
int main()
{
	int N;
	cin >> N;
	if (N == 6174)
	{
		printf("7641 - 1467 = 6174\n");
	}
	else
	{
		string diff = inttostring(N), strSub, strMinu;
		while (diff != "6174"&&diff != "0000")
		{
			sort(diff.begin(), diff.end());
			strSub = diff;
			reverse(diff.begin(), diff.end());
			strMinu = diff;
			diff = inttostring(stoi(strMinu) - stoi(strSub));
			printf("%04d - %04d = %04d\n", stoi(strMinu), stoi(strSub), stoi(strMinu) - stoi(strSub));
		}
	}
	return 0;
}