#include<iostream>
#include<string>
#include<iomanip>
#include<algorithm>
using namespace std;
int main()
{
	string A;
	cin >> A;
	auto posE = A.find('E');
	string strNum=A.substr(0 , posE);
	//auto Num = stod(strNum);
	string strindex = A.substr(posE+1);;
	auto index = stoi(strindex);
	int indexbk = abs(index);
	if (index > 0)
	{
		auto posdot = strNum.find('.');
		if (posdot == string::npos)
		{
			strNum.insert(strNum.size(), indexbk, '0');
		}
		else if (strNum.size()>posdot + indexbk + 1)
		{
			strNum.insert(posdot + indexbk + 1, 1, '.');
			strNum.erase(posdot, 1);

		}
		else if (strNum.size() == posdot + indexbk + 1)
		{
			strNum.erase(posdot, 1);
		}
		else if (strNum.size() < posdot + indexbk + 1)
		{
			strNum.insert(strNum.size(), posdot + indexbk + 1 - strNum.size(), '0');
			strNum.erase(posdot, 1);
		}
		if (strNum[0] == '+')//去掉正数前面的+
		{
			strNum.erase(0, 1);
		}	
		cout << strNum << endl;
	}
	else
	{
		auto posdot = strNum.find('.');
		if (posdot != string::npos)
		{
			strNum.erase(posdot, 1);
		}
		strNum.insert(1, indexbk , '0');
		strNum.insert(2, 1 , '.');
		if (strNum[0] == '+')//去掉正数前面的+
		{
			strNum.erase(0, 1);
		}
		cout << strNum << endl;
	}

	return 0;
}



