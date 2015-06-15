#include <iostream>
#include <algorithm>

using namespace std;
int isPrimeNum(int Num)
{
	for (int i = 2; i <= sqrt(Num); i++)
	{
		if (Num%i == 0)
		{
			return 0;
		}

	}
	return 1;
}
int main()
{
	int N,lastPrime=0,countPrime=0;
	cin >> N;
	while (!isPrimeNum(N))
	{
		N--;
	}
	lastPrime = N;
	for (int i = N-2; i > 2; i--,i--)
	{
		if (isPrimeNum(i))
		{
			if (lastPrime - i == 2)
			{
				countPrime++;
			}
			lastPrime = i;
		}
		
	}
	cout << countPrime << endl;
	return 0;
}