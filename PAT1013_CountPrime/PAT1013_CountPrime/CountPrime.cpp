#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool isPrime(int num)
{
	bool mark=1;
	for (int i=2; i <= sqrt(num); i++)
	{
		if (!(num%i))
		{
			mark = 0;
			return mark;
		}
	}
	return mark;
}
int main()
{
	vector<int> primeAll;
	int M, N,count=0,i=2;
	cin >> M >> N;
	while (primeAll.size()<=10000)
	{
		if (isPrime(i))
		{
			primeAll.push_back(i);
		}
		i++;
	}
	for (int i = M; i < N; i++)
	{
		cout<<primeAll[i - 1];
		count++;
		if (count % 10 == 0)
			cout << endl;
		else
			cout << ' ';
	}
	cout << primeAll[N-1]<<endl;
	return 0;
}