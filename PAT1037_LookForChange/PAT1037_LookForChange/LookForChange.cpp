#include<iostream>
#include<string>
using namespace std;
struct money
{
	long int Galleon;
	int Sickle;
	int Knut;
};
int main()
{
	money P, A, changes;
	string strP, strA;
	cin >> strP >> strA;
	auto posPdotfirst = strP.find_first_of('.');
	auto posPdotlast = strP.find_last_of('.');
	if (posPdotfirst != string::npos && posPdotlast != string::npos)
	{
		P.Galleon = stol(strP.substr(0, posPdotfirst));
		P.Sickle = stoi(strP.substr(posPdotfirst + 1, posPdotlast));
		P.Knut = stoi(strP.substr(posPdotlast + 1));
	}
	auto strAdotfirst = strA.find_first_of('.');
	auto strAdotlast = strA.find_last_of('.');
	if (strAdotfirst != string::npos && strAdotlast != string::npos)
	{
		A.Galleon = stol(strA.substr(0, strAdotfirst));
		A.Sickle = stoi(strA.substr(strAdotfirst + 1, strAdotlast));
		A.Knut = stoi(strA.substr(strAdotlast + 1));
	}
	if (strA.size()>strP.size() || strA.compare(strP) >= 0)
	{
		if (A.Knut >= P.Knut)
		{
			changes.Knut = A.Knut - P.Knut;
		}
		else
		{
			A.Knut = A.Knut + 29;
			A.Sickle = A.Sickle - 1;
			changes.Knut = A.Knut - P.Knut;
		}
		if (A.Sickle >= P.Sickle)
		{
			changes.Sickle = A.Sickle - P.Sickle;
		}
		else
		{
			A.Sickle = A.Sickle + 17;
			A.Galleon = A.Galleon - 1;
			changes.Sickle = A.Sickle - P.Sickle;
		}
		changes.Galleon = A.Galleon - P.Galleon;

	}
	else
	{
		if (A.Knut <= P.Knut)
		{
			changes.Knut = P.Knut - A.Knut;
		}
		else
		{
			P.Knut = P.Knut + 29;
			P.Sickle = P.Sickle - 1;
			changes.Knut = P.Knut - A.Knut;
		}
		if (A.Sickle <= P.Sickle)
		{
			changes.Sickle = P.Sickle - A.Sickle;
		}
		else
		{
			P.Sickle = P.Sickle + 17;
			P.Galleon = P.Galleon - 1;
			changes.Sickle = P.Sickle - A.Sickle;
		}
		changes.Galleon = -(P.Galleon - A.Galleon);
	}
	cout << changes.Galleon << '.' << changes.Sickle << '.' << changes.Knut << endl;
	return 0;
}