#include<iostream>
#include<string>
using namespace std;
int main()
{
	string badkey, shouldout, realout = "";
	int flag = 0;
	getline(cin, badkey);
	getline(cin, shouldout);
	auto badkayposplus = badkey.find('+');
	if (badkayposplus != string::npos)
	{
		badkey.erase(badkayposplus, 1);
		flag = 1;
	}

	for (int i = 0; i < shouldout.size(); i++)
	{
		char ch = shouldout[i];
		if (ch >= 'A'&&ch <= 'Z')
		{
			if (!flag)
			{
				auto posL = badkey.find(ch);
				if (posL == string::npos)
				{
					realout.push_back(ch);
				}
			}
		}
		else if (ch >= 'a'&&ch <= 'z')
		{
			auto posL = badkey.find(ch - 'a' + 'A');
			if (posL == string::npos)
			{
				realout.push_back(ch);
			}
		}
		else if (ch == ' ')
		{
			auto posL = badkey.find('+');
			if (posL == string::npos)
			{
				realout.push_back(ch);
			}
		}
		else
		{
			auto posL = badkey.find(ch);
			if (posL == string::npos)
			{
				realout.push_back(ch);
			}
		}
	}


	cout << realout << endl;
	return 0;
}