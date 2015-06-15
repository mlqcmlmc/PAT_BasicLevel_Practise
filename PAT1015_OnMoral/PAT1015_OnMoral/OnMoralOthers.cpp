//#define _CRT_SECURE_NO_DEPRECATE
//#define _SECURE_SCL 0
//#pragma comment(linker, "/STACK:66777216")
//#include <algorithm>
//#include <string>
//#include <complex>
//#include <cassert>
//#include <memory>
//#include <set>
//#include <stack>
//#include <map>
//#include <list>
//#include <deque>
//#include <numeric>
//#include <cctype>
//#include <cstddef>
//#include <vector>
//#include <queue>
//#include <iostream>
//#include <iomanip>
//#include <iterator>
//#include <cmath>
//#include <cstdio>
//#include <cstdlib>
//#include <sstream>
//#include <fstream>
//#include <ctime>
//#include <cstring>
//#include <functional>
//#include <bitset>
//using namespace std;
//
////
////static inline bool get(int &v)
////{
////	int s = 1, c;
////	while (!isdigit(c = getchar()) && c != '-')
////	{
////		if (c == EOF) break;
////	}
////	if (c == EOF) return 0;
////	if (c == '-') s = 0, v = 0;
////	else v = c ^ 48;
////	for (; isdigit(c = getchar()); v = (v << 1) + (v << 3) + (c ^ 48))
////		;
////	v = (s ? v : -v);
////	return 1;
////}
////#define out(x) printf("%d")
//
//struct info
//{
//	int ID;
//	int D;
//	int C;
//	int tot;
//}tmp;
//
//vector<info> elem1, elem2, elem3, elem4;
//
//int cmp(const info &a, const info &b)
//{
//	if (a.tot == b.tot)
//	{
//		if (a.D == b.D)	return a.ID < b.ID;
//		else return a.D > b.D;
//	}
//	else return a.tot>b.tot;
//}
//
//
//int main()
//{
//	int n, l, h, num;
//	cin >> n >> l >> h;
//	//get(n), get(l), get(h);
//	num = n;
//	for (int i = 0; i < n;i++)
//	{
//		//get(tmp.ID), get(tmp.D), get(tmp.C);
//		cin >> tmp.ID >> tmp.D >> tmp.C;
//		tmp.tot = tmp.D + tmp.C;
//		if (tmp.C < l || tmp.D < l)
//		{
//			num--;
//			continue;
//		}
//		if (tmp.D >= h && tmp.C >= h)
//		{//1
//			elem1.push_back(tmp);
//		}
//		else if (tmp.D >= h && tmp.C < h)
//		{//2
//			elem2.push_back(tmp);
//		}
//		else if (tmp.D < h && tmp.C < h && tmp.D >= tmp.C)
//		{//3
//			elem3.push_back(tmp);
//		}
//		else
//		{//4
//			elem4.push_back(tmp);
//		}
//	}
//	sort(elem1.begin(), elem1.end(), cmp);
//	sort(elem2.begin(), elem2.end(), cmp);
//	sort(elem3.begin(), elem3.end(), cmp);
//	sort(elem4.begin(), elem4.end(), cmp);
//	printf("%d\n", num);
//	for (int i = 0; i < elem1.size();i++)	printf("%d %d %d\n", elem1[i].ID, elem1[i].D, elem1[i].C);
//		//cout << elem1[i].ID << ' ' << elem1[i].D << ' ' << elem1[i].C << endl;
//	for (int i = 0; i < elem2.size(); i++)	printf("%d %d %d\n", elem2[i].ID, elem2[i].D, elem2[i].C);
//		//cout << elem2[i].ID << ' ' << elem2[i].D << ' ' << elem2[i].C << endl;
//	for (int i = 0; i < elem3.size(); i++)	printf("%d %d %d\n", elem3[i].ID, elem3[i].D, elem3[i].C);
//		//cout << elem3[i].ID << ' ' << elem3[i].D << ' ' << elem3[i].C << endl;
//	for (int i = 0; i < elem4.size(); i++)	printf("%d %d %d\n", elem4[i].ID, elem4[i].D, elem4[i].C);
//		//cout << elem4[i].ID << ' ' << elem4[i].D << ' ' << elem4[i].C << endl;
//	return 0;
//}