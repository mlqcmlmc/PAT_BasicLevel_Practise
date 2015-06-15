#include <iostream>
#include <string>
#include <vector>
using namespace std;
class student {
public:
	string Name;
	string StuId;
	unsigned int Grade;
};
int main()
{
	unsigned int StuNum,StuGrademin,StuGrademax,minIndex=0,maxIndex=0;
	student StuIn;
	vector<student> Stu;
	cin >> StuNum;
	for (unsigned int i = 0; i < StuNum; i++)
	{
		cin >> StuIn.Name >> StuIn.StuId >> StuIn.Grade;
		Stu.push_back(StuIn);
	}
	StuGrademin = Stu[0].Grade;
	StuGrademax = Stu[0].Grade;
	for (unsigned int i = 1; i < StuNum; i++)
	{
		if (StuGrademin>Stu[i].Grade)
		{
			StuGrademin = Stu[i].Grade;
			minIndex = i;
		}
		if (StuGrademax < Stu[i].Grade)
		{
			StuGrademax = Stu[i].Grade;
			maxIndex = i;
		}
	}
	cout << Stu[maxIndex].Name <<" "<< Stu[maxIndex].StuId << endl;
	cout << Stu[minIndex].Name <<" "<< Stu[minIndex].StuId << endl;
	return 0;

}