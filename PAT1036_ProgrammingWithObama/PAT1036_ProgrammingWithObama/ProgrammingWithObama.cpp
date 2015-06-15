#include<iostream>
#include<string>
using namespace std;
int main()
{
	int N;
	char C;
	cin >> N >> C;
	string row(N, C), emptystr(N - 2, ' '), line;
	line.push_back(C);
	line = line + emptystr;
	line.push_back(C);
	cout << row << endl;
	for (int i = 0; i < int(N/2.0+0.5) - 2; i++)
	{
		cout << line << endl;
	}
	cout << row << endl;
	return 0;
}