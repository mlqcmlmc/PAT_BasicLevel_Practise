#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n,ge,shi,bai;
	cin >> n;
	ge = n % 10;
	shi = (n % 100)/10;
	bai = n / 100;
	for (int i = 0; i < bai; i++)
	{
		cout << 'B';
	}
	for (int i = 0; i < shi; i++)
	{
		cout << 'S';
	}
	for (int i = 0; i < ge; i++)
	{
		cout << i + 1;
	}
	cout << endl;
	return 0;

}