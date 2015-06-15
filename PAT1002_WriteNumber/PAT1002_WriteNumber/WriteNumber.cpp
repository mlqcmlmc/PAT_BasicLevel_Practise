#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	string strin;
	string pinyin[10] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" };
	vector<string> strout;
	int sum=0;
	cin >> strin;
	if (!strin.empty())
	{
		auto strsize = strin.size();
		for (unsigned int i = 0; i < strsize; i++)
		{
			sum += strin[i] - '0';
		}
		while (sum >0)
		{
			strout.push_back(pinyin[sum % 10]);
			sum = sum / 10;

		}
		for (auto j = strout.size() - 1; j > 0; j--)
		{
			cout << strout[j] <<" ";
		}
		cout << strout[0] << endl;
	}

	return 0;
}