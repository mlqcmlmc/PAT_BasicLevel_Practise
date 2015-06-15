#include <iostream>
using namespace std;
int main()
{
	int N;
	long long int A, B, C;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A >> B >> C;
		if (A + B>C)
		{
			cout << "Case #" << i + 1 << ": true"<<endl;
		}
		else
		{
			cout << "Case #" << i + 1 << ": false" << endl;
		}
	}
	return 0;
}