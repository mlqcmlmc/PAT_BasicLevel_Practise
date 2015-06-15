#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int N=0, inOneNum=0, sum0 = 0, sum1 = 0, count0 = 0, count1 = 0, count2 = 0, count3 = 0, count4 = 0, num4max = 0, temp=0;
	double sum3 = 0.0, count33 = 0.0;
	cin >> N;
	for (int i = 0; i < N;i++)
	{
		cin >> inOneNum;
		if (inOneNum % 10==0)
		{
			count0++;
			sum0 += inOneNum;
		}
		else if (inOneNum % 5 == 1)
		{
			count1++;
			temp = ((count1 % 2) ? inOneNum : (-inOneNum));
			sum1 += temp;
		}
		else if (inOneNum % 5 == 2)
		{
			count2++;
		}
		else if (inOneNum % 5 ==3)
		{
			count3++;
			sum3 = sum3 + inOneNum;
			count33 = count33 + 1.0;
		}
		else if (inOneNum % 5 == 4)
		{
			if (num4max < inOneNum)
			{
				count4++;
				num4max = inOneNum;
			}
		}
	}

	if (count0)
		cout << sum0 << ' ';
	else
		cout << 'N' << ' ';

	if (count1)
		cout << sum1 << ' ';
	else
		cout << 'N' << ' ';

	if (count2)
		cout << count2 << ' ';
	else
		cout << 'N' << ' ';
	if (count3)
	{
		cout << fixed << setprecision(1) << sum3 / count33 << ' ';
	}
	else
		cout << 'N' << ' ';
	if (count4)
		cout << num4max << endl;
	else
		cout << 'N' << endl;
	return 0;

}
