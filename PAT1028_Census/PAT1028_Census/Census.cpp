#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct person
{
	string name;
	long int birthday;
};
bool cmp(person person1, person person2)
{
	return person1.birthday <= person2.birthday;
}
int main()
{
	int N,nian,yue,ri;
	string nameone, birthdayone, oldername, youngname;
	person oneperson;
	vector<person> personAll;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> nameone >> birthdayone;
		nian = stoi(birthdayone.substr(0, 4));
		yue = stoi(birthdayone.substr(5, 2));
		ri = stoi(birthdayone.substr(8, 2));
		oneperson.name = nameone;
		oneperson.birthday = nian * 10000 + yue * 100 + ri;
		if (oneperson.birthday <= 20140906)
		{
			if ((oneperson.birthday >= 18140906))
			{
				personAll.push_back(oneperson);
			}
		}
	}
	sort(personAll.begin(), personAll.end(), cmp);
	if (personAll.size()==0)
	{
		cout << personAll.size()<< endl;
	}
	else
	{
		oldername = personAll[0].name;
		youngname = personAll[personAll.size() - 1].name;
		cout << personAll.size() << ' ' << oldername << ' ' << youngname << endl;
	}
	return 0;
}