#include <iostream>
#include <string>
using namespace std;
int main()
{
	string A, B;
	char DA, DB;
	int coutA=0, coutB=0,PA=0,PB=0,DAint,DBint;
	cin >> A >> DA >> B >> DB;
	for (auto &a : A)
	{
		if (a == DA)
		{
			coutA++;
		}
	}
	for (auto &b : B)
	{
		if (b == DB)
		{
			coutB++;
		}
	}
	DAint = DA - '0';
	DBint = DB - '0';
	while (coutA--)
	{
		PA = PA * 10 + DAint;
	}
	while (coutB--)
	{
		PB = PB * 10 + DBint;
	}
	cout << PA + PB << endl;
	return 0;
	
}
