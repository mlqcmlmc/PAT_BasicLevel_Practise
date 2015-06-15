#include<iostream>
#include<string>
#include <algorithm>
//#include "stdlib.h"
using namespace std;
int main()
{
	int A, B, D,sum=0;
	string sumDstr;
	cin >> A >> B >> D;
	sum = A + B;
	if (!sum)
	{
		sumDstr.push_back('0');
	}
	while (sum)
	{
		sumDstr.push_back(sum % D+'0');
		sum = sum / D;
	}
	reverse(sumDstr.begin(), sumDstr.end());
	cout << sumDstr << endl;
	return 0;
}