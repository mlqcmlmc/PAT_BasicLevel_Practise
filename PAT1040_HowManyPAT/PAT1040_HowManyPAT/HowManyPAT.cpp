//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	long int count = 0;
//	string originalstr, tempstrP, tempstrA, tempstrT;
//	cin >> originalstr;
//	tempstrP = originalstr;
//	auto posP = tempstrP.find('P');
//	while (posP != string::npos)
//	{
//		tempstrP = tempstrP.substr(posP+1);
//		tempstrA = tempstrP;
//		auto posA = tempstrA.find('A');
//		while (posA != string::npos)
//		{
//			tempstrA = tempstrA.substr(posA+1);
//			tempstrT = tempstrA;
//			auto posT = tempstrT.find('T');
//			while (posT != string::npos)
//			{
//				tempstrT = tempstrT.substr(posT + 1);
//				count++;
//				posT = tempstrT.find('T');
//			}
//			posA = tempstrA.find('A');
//		}
//		posP = tempstrP.find('P');
//	}
//	cout << count % 1000000007 << endl;
//	return 0;
//}


#include<iostream>
#include<string>
using namespace std;
int main()
{
	long int countT = 0, countAT = 0, countPAT = 0;
	string str;
	cin >> str;
	for (int i = str.size() - 1; i >= 0; i--)
	{
		if (str[i] == 'T')
		{
			countT++;
		}
		else if (str[i] == 'A')
		{
			countAT = (countAT + countT) % 1000000007;
		}
		else if (str[i] == 'P')
		{
			countPAT = (countPAT + countAT) % 1000000007;
		}
	}
	cout << countPAT << endl;
	return 0;
}