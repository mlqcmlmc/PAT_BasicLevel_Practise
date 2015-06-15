#include<iostream>
#include<string>
using namespace std;
int main()
{
	string shouldstr, realstr,badkey;
	cin >> shouldstr >> realstr;
	for (int i = 0,j=0; i < shouldstr.size(); i++)
	{
		if (shouldstr[i] == realstr[j])
		{
			j++;
		}
		else
		{
			if (shouldstr[i] <= 'z'&&shouldstr[i] >= 'a')
			{
				shouldstr[i] = shouldstr[i] - 'a' + 'A';
			}
			if (badkey.find(shouldstr[i]) == string::npos)
			{
				badkey.push_back(shouldstr[i]);
			}
		}
	}
	cout << badkey << endl;
	return 0;

}