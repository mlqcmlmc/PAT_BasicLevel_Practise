#include <iostream>
#include <string>
#include<algorithm>
using namespace std;
int compareBigInt(string str1, string str2)
{
	if (str1.size() > str2.size())
	{
		return 1;
	}
	else if (str1.size() < str2.size())
	{
		return -1;
	}
	else
	{
		return str1.compare(str2);
	}
}
string Subtraction(string str1, string str2)
{
	string value,temp;
	//确保大数减小数
	if (compareBigInt(str1,str2) < 0)
	{
		temp = str1;
		str1 = str2;
		str2 = temp;
	}

	//翻转字符串，使高位在后面
	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());
	int i;
	//逐位相减
	for (i = 0; i < str2.size(); i++)
	{
		value.push_back(str1[i] - str2[i] + '0');
	}
	if (i<str1.size())
	{
		for (; i < str1.size(); i++)
		{
			value.push_back(str1[i]);
		}
	}
	//处理借位
	for (int j = 0; j < value.size() - 1; j++)
	{
		if (value[j]<'0')
		{
			value[j] = value[j] + 10;
			value[j + 1] = value[j + 1] - 1;
		}
	}
	//翻转字符串，使高位在前面
	reverse(value.begin(), value.end());
	int pos = value.find_first_not_of('0');
	if (pos == string::npos)//空的，说明结果是0  
	{
		value.clear();
		value.push_back('0');
		return value;
	}
	value = string(value.begin() + pos, value.end()); //去掉前面的0  
	if (value.empty())
	{
		value.push_back('0');
	}
	return value;
}
//返回商，使用引用返回余数，strA最后的结果为余数
string DivideBigInt(string &strA, string strB)
{
	string value;
	if (compareBigInt(strA, strB) < 0)
	{
		return "0";
	}
	else if (compareBigInt(strA, strB) == 0)
	{
		strA = Subtraction(strA, strB);
		return "1";
	}
	else 
	{
		int count = strA.size() - strB.size();
		while (count>=0)
		{
			string temp(strB);
			for (int i = 0; i < count;i++)
			{
				temp.push_back('0');
			}
			int addNum = 0;
			while (compareBigInt(strA, temp) >= 0)
			{
				strA = Subtraction(strA, temp);
				addNum++;
			}
			value.push_back(addNum + '0');
			count--;
		}
		value = string(value.begin() + value.find_first_not_of('0'), value.end()); //去掉前面的0 
		return value;
	}
}

//string ModuleBigInt(string strA, string strB)
//{
//	while (compareBigInt(strA, strB) >= 0)
//	{
//		strA = Subtraction(strA, strB);
//	}
//	return strA;
//}
int main()
{
	string A, B,Q,R;
	cin >> A >> B;
	Q = DivideBigInt(A, B);
	R = A;
	cout << Q << ' ' << R << endl;
	return 0;
}

