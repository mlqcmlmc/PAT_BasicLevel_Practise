#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<unsigned int>> saveProcess;
unsigned int find(unsigned int num)
{
	unsigned int Mark = 0;
	for (unsigned int i = 0; i < saveProcess.size(); i++)
	{
		auto it = saveProcess[i].begin();
		while (it != saveProcess[i].end())
		{
			if ((*it) == num)
			{
				Mark = 1;
				return Mark;
			}
			++it;
		}
	}
	return Mark;
}
int findFirst(unsigned int num)
{
	int Mark = -1;
	for (unsigned int i = 0; i < saveProcess.size(); i++)
	{
		if (num == saveProcess[i][0])
		{
			Mark = i;
			return Mark;
		}
	}
	return Mark;
}
int main()
{
	unsigned int len,number;
	vector<unsigned int> oneProcess,rankKey;
	cin >> len;
	for (unsigned int i = 0; i < len; i++)
	{
		cin >> number;
		oneProcess.clear();
		int findMark=find(number);
		if (findMark == 0)
		{
			while (number != 1)
			{
				int findFirstMark = findFirst(number);
				if (findFirstMark == -1)
				{
					oneProcess.push_back(number);
					if (number % 2 == 0)
					{
						number = number / 2;
					}
					else
					{
						number = (3 * number + 1) / 2;
					}
				}
				else
				{
					oneProcess.insert(oneProcess.end(), saveProcess[findFirstMark].begin(), saveProcess[findFirstMark].end());
					auto ittemp = saveProcess.begin() + findFirstMark;
					saveProcess.erase(ittemp);
					//saveProcess.push_back(oneProcess);
					break;

				}

			}
			saveProcess.push_back(oneProcess);
		}
	}

	for (unsigned int i = 0; i < saveProcess.size(); i++)
	{
		rankKey.push_back(saveProcess[i][0]);
	}
	sort(rankKey.begin(), rankKey.end());
	for (unsigned int i = (rankKey.size()-1); i >0; i--)
	{
		cout << rankKey[i] << ' ';
	}
	cout << rankKey[0] << endl;
	return 0;

}