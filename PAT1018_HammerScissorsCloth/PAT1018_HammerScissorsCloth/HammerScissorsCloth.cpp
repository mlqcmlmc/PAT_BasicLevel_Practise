#include<iostream>
#include<map>
using namespace std;
int whowin(char a, char b)
{
	if (a == b)
	{
		return 0;
	}
	else if ((a == 'C'&&b == 'J') || (a == 'J'&&b == 'B') || (a == 'B'&&b == 'C'))
	{
		return 1;
	}
	else
	{
		return -1;
	}
}
int main()
{
	int N,countAWin=0,countP=0,countBWin=0;
	map<char, int> staANext = { { 'B', 0 }, { 'C', 0 }, { 'J', 0 } }, staBNext = { { 'B', 0 }, { 'C', 0 }, { 'J', 0 } };
	char A, B;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A >> B;
		int temp = whowin(A, B);
		if (temp == 1)
		{
			countAWin++;
			staANext[A]++;
		}
		else if (temp == 0)
		{
			countP++;
		}
		else
		{
			countBWin++;
			staBNext[B]++;
		}

	}
	char nextA='B', nextB='B';
	if ((staANext['B'] < staANext['J']) && (staANext['C'] < staANext['J']))
	{
		nextA = 'J';
	}
	else if ((staANext['B'] < staANext['C']) && (staANext['C'] >= staANext['J']))
	{
		nextA = 'C';
	}

	if ((staBNext['B'] < staBNext['J']) && (staBNext['C'] < staBNext['J']))
	{
		nextB = 'J';
	}
	else if ((staBNext['B'] < staBNext['C']) && (staBNext['C'] >= staBNext['J']))
	{
		nextB = 'C';
	}
	cout << countAWin << ' ' << countP << ' ' << countBWin << endl;
	cout << countBWin << ' ' << countP << ' ' << countAWin << endl;
	cout << nextA << ' ' << nextB << endl;
	return 0;

}