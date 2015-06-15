#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int main()
{
	long int N, Nodot,grade,maxgrade=0,maxNodot=0;
	map<long int, long int> gradesum;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> Nodot >> grade;
		gradesum[Nodot] += grade;
	}
	
	for (auto it = gradesum.begin(); it != gradesum.end(); it++)
	{
		if (it->second>maxgrade)
		{
			maxgrade = it->second;
			maxNodot = it->first;
		}
	}

	cout << maxNodot << ' ' << maxgrade << endl;
	return 0;

}