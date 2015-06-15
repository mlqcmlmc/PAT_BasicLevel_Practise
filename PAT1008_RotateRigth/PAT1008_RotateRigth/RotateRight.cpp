#include<iostream>
#include<vector>
using namespace std;
int main()
{
	unsigned int N, M;
	cin >> N >> M;
	vector<unsigned int> Array(N);
	for (unsigned int i = 0; i < N;i++)
	{
		cin >>Array[i];
	}
	unsigned int temp;
	while (M)
	{
		temp = Array[N - 1];
		for (unsigned int j = N - 1; j >0; j--)
		{
			Array[j] = Array[j-1];
		}
		Array[0] = temp;
		M--;
	}
	for (unsigned int i = 0; i < N-1; i++)
	{
		cout<< Array[i]<<' ';
	}
	cout << Array[N-1] << endl;
	return 0;

}