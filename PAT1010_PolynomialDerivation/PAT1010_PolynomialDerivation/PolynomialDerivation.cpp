#include <iostream>
#include<vector>
using namespace std;
struct Number
{
	int coefficient;
	int index;
};
int main()
{
	vector<Number> poly, polyDerivation;
	Number N;
	char c;

	while (cin >> N.coefficient >> N.index)
	{
		poly.push_back(N);
	}
	//for (int i = 0; i < 4;i++)
	//{
	//	cin >> N.coefficient >> N.index;
	//	
	//	poly.push_back(N);
	//}
	for (int i = 0; i < poly.size(); i++)
	{
		if (poly[i].index)
		{
			Number temp;
			temp.coefficient = poly[i].coefficient*poly[i].index;
			temp.index = poly[i].index-1;
			polyDerivation.push_back(temp);
		}

	}
	if (!polyDerivation.size())
	{
		cout << "0 0" << endl;
		return 0;
	}
	for (int i = 0; i < polyDerivation.size()-1; i++)
	{
		cout << polyDerivation[i].coefficient << ' ' << polyDerivation[i].index << ' ';
	}
	cout << polyDerivation[polyDerivation.size() - 1].coefficient << ' ' << polyDerivation[polyDerivation.size() - 1].index << endl;

	return 0;
}


