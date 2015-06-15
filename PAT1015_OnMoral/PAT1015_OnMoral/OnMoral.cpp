#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h> 
using namespace std;
//#define NumMax 100000
struct student{
	int stuId;
	int moralGrade;
	int caiGrade;
	int sumGrade;
};
bool comparision(const student &a, const student &b)
{

	if (a.sumGrade == b.sumGrade)
	{
		if (a.moralGrade == b.moralGrade)
		{
			return a.stuId < b.stuId;
		}
		else
		{
			return a.moralGrade > b.moralGrade;
		}
	}
	else
		return a.sumGrade > b.sumGrade;

}
int main()
{
	vector<student> stuHH, stuHL,stuLMoreL,stuLL;
	student stuOne;
	int N, L, H;
	scanf("%d%d%d", &N, &L, &H);
	//cin >> N >> L >> H;
	//stuHH.reserve(NumMax);
	//stuHL.reserve(NumMax);
	//stuLMoreL.reserve(NumMax);
	//stuLL.reserve(NumMax);
	for (int i = 0; i < N; i++)
	{
		scanf("%d%d%d", &stuOne.stuId, &stuOne.moralGrade,&stuOne.caiGrade);
		//cin >> stuOne.stuId >> stuOne.moralGrade >> stuOne.caiGrade;
		stuOne.sumGrade = stuOne.moralGrade + stuOne.caiGrade;
		if ((stuOne.moralGrade >= H)&&(stuOne.caiGrade >= H))
		{
			stuHH.push_back(stuOne);
		}
		else if (stuOne.moralGrade >= H&&stuOne.caiGrade >= L)
		{
			stuHL.push_back(stuOne);
		}
		else if (stuOne.moralGrade >= L&&stuOne.caiGrade >= L&&stuOne.moralGrade >= stuOne.caiGrade)
		{
			stuLMoreL.push_back(stuOne);
		}
		else if (stuOne.moralGrade >= L&&stuOne.caiGrade >= L)
		{
			stuLL.push_back(stuOne);
		}
	}
	int M = stuHH.size() + stuHL.size() + stuLMoreL.size() + stuLL.size();
	cout << M << endl; 
	sort(stuHH.begin(), stuHH.end(), comparision);
	sort(stuHL.begin(), stuHL.end(), comparision);
	sort(stuLMoreL.begin(), stuLMoreL.end(), comparision);
	sort(stuLL.begin(), stuLL.end(), comparision);
	for (int i = 0; i < stuHH.size(); i++)
	{
		printf("%d %d %d\n", stuHH[i].stuId ,stuHH[i].moralGrade, stuHH[i].caiGrade);
		//cout << stuHH[i].stuId << ' ' << stuHH[i].moralGrade << ' ' << stuHH[i].caiGrade  << endl;
	}
	for (int i = 0; i < stuHL.size(); i++)
	{
		printf("%d %d %d\n", stuHL[i].stuId, stuHL[i].moralGrade, stuHL[i].caiGrade);
		//cout << stuHL[i].stuId << ' ' << stuHL[i].moralGrade << ' ' << stuHL[i].caiGrade << endl;
	}
	for (int i = 0; i < stuLMoreL.size(); i++)
	{
		printf("%d %d %d\n", stuLMoreL[i].stuId, stuLMoreL[i].moralGrade, stuLMoreL[i].caiGrade);
		//cout << stuLMoreL[i].stuId << ' ' << stuLMoreL[i].moralGrade << ' ' << stuLMoreL[i].caiGrade << endl;
	}
	for (int i = 0; i < stuLL.size(); i++)
	{
		printf("%d %d %d\n", stuLL[i].stuId, stuLL[i].moralGrade, stuLL[i].caiGrade);
		//cout << stuLL[i].stuId << ' ' << stuLL[i].moralGrade << ' ' << stuLL[i].caiGrade << endl;
	}
	return 0;
}