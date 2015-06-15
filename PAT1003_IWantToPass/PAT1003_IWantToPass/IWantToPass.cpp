#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
	unsigned int StrNum;
	cin >> StrNum;
	for (unsigned int j = 0; j < StrNum; j++)
	{
		unsigned int PFrontNum, BetweenNum, TAfterNum;
		string StrLine;
		int PrintNo = 1, Tpos = -1, Ppos = -1;
		cin >> StrLine;
		for (unsigned int i = 0; i < StrLine.size(); i++)
		{
			if (!(StrLine[i] == 'A' || StrLine[i] == 'P' || StrLine[i] == 'T'))
			{
				PrintNo=0;
				break;
			}
			if (StrLine[i] == 'P')
			{
				Ppos = i;
			}
			if (StrLine[i] == 'T')
			{
				Tpos = i;
			}
		}
		if (PrintNo == 0||Tpos <0 || Ppos <0 || (Tpos <= Ppos + 1) )
		{
			cout << "NO" << endl;
		}
		else
		{
			PFrontNum = Ppos;
			BetweenNum = Tpos - Ppos - 1;
			TAfterNum = StrLine.size() - Tpos - 1;
			if (PFrontNum == 0 && TAfterNum == 0 && BetweenNum >= 1)
			{
				cout << "YES" << endl;
			}
			else if (TAfterNum > 0 && (TAfterNum == PFrontNum*BetweenNum))
			{
				cout << "YES" << endl;
			}
			else
			{
				cout << "NO" << endl;
			}
		}
		
	}

	return 0;
}
