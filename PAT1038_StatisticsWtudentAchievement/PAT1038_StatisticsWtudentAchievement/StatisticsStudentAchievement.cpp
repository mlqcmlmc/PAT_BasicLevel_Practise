#include<iostream>  
#include<cstring>
#include<map>
#include<string>
using namespace std;
int main()
{
	int grade[101];
	memset(grade, 0, sizeof(grade));
	int N;
	while (cin >> N)
	{
		int num;
		for (int i = 0; i<N; i++)
		{
			cin >> num;
			grade[num]++;
		}
		int K;
		cin >> K;
		for (int i = 0; i<K - 1; i++)
		{
			cin >> num;
			cout << grade[num] << ' ';
		}
		cin >> num;
		cout << grade[num] << endl;
	}
	return 0;
}
