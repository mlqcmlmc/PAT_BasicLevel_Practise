//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int main()
//{
//	unsigned long int N;
//	unsigned long long int P, temp,max=0;
//	unsigned long long int multiply;
//	vector<unsigned long long int> numAll;
//	cin >> N >> P;
//	for (unsigned long int i = 0; i < N; i++)
//	{
//		cin >> temp;
//		//scanf("%lld", &temp);
//		numAll.push_back(temp);
//	}
//	sort(numAll.begin(), numAll.end());
//	for (unsigned long int i = 0; i < numAll.size() - max; i++)
//	{
//		multiply = numAll[i] * P;
//		while (i + max < N&&multiply >= numAll[i + max])
//		{
//			max++;
//		}
//	}
//
//	cout << max << endl;
//	return 0;
//
//}



#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <cctype>
#include <map>
#include <string>
#include <cstring>
#include <stack>
#include <set>
using namespace std;

vector<long long> vec;

int main() {
	int n;
	long long p, e;
	scanf("%d%lld", &n, &p);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &e);
		vec.push_back(e);
	}
	sort(vec.begin(), vec.end());
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int pos = upper_bound(vec.begin(), vec.end(), vec[i] * p) - vec.begin();
		if (pos - 1 >= 0) pos -= 1;
		// cout << vec[i]*p << " " << pos << endl;
		ans = max(ans, pos - i + 1);
	}
	printf("%d\n", ans);
	return 0;
}