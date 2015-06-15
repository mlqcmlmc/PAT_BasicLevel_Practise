#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<map>
#include "stdio.h"
using namespace std;
struct listNum
{
	int add;
	int data;
	int nextadd;
};
int main()
{
	int firstAdd;
	int N, K;
	cin >> firstAdd >> N >> K;
	map<int, int> listAddNum, listNextAddNum;
	map<int, int> listNumAdd, listNumNextAdd;
	vector<listNum> saveListAll;
	for (int i = 0; i < N; i++)
	{
		int strAdd, strNextAdd;
		int nowNum;
		cin >> strAdd >> nowNum >> strNextAdd;
		listAddNum.insert({ strAdd, nowNum });
		listNumNextAdd.insert({ nowNum, strNextAdd });
	}
	//被最后一个测试点坑了好久，起始地址不一定是整个链表的第一个，有可能从中间开始，所以在顺序保存saveListAll时，其size不一定是N.
	int curadd = firstAdd;
	listNum temp;
	while (curadd!=-1)
	{
		temp.add = curadd;
		temp.data = listAddNum[temp.add];
		temp.nextadd = listNumNextAdd[temp.data];
		curadd = temp.nextadd;
		saveListAll.push_back(temp);
	}
	/*saveListAll[0].add = firstAdd;
	saveListAll[0].data = listAddNum[saveListAll[0].add];
	saveListAll[0].nextadd = listNumNextAdd[saveListAll[0].data];
	for (int i = 1; i < N; i++)
	{
		saveListAll[i].add = saveListAll[i-1].nextadd;
		saveListAll[i].data = listAddNum[saveListAll[i].add];
		saveListAll[i].nextadd = listNumNextAdd[saveListAll[i].data];
	}*/
	int numRev = saveListAll.size() / K;
	for (int j = 0; j < numRev;j++)
	{
		for (int i = (j + 1)*K - 1; i >= j*K; i--)
		{
			printf("%05d %d ", saveListAll[i].add, saveListAll[i].data);
			if (i == j*K)
			{
				if (j<numRev - 1)
				{
					printf("%05d", saveListAll[(j + 2)*K - 1].add);
				}
				else
				{
					if ((j + 1)*K < saveListAll.size())
					{
						printf("%05d", saveListAll[(j + 1)*K].add);
					}
					else
					{
						printf("-1");
					}
				}
			}
			else
			{
				printf("%05d", saveListAll[i-1].add);

			}
			printf("\n");
		}	
	}
	int remain = saveListAll.size() % K;
	if (remain)
	{
		for (int i = saveListAll.size() - remain; i < saveListAll.size(); i++)
		{
			if (i == saveListAll.size() - 1)
			{
				printf("%05d %d -1\n", saveListAll[i].add, saveListAll[i].data);

			}
			else
				printf("%05d %d %05d\n", saveListAll[i].add, saveListAll[i].data, saveListAll[i+1].add);

		}
	}

	return 0;
}