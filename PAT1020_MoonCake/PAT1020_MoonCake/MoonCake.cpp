#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct goods
{
	double stock;
	double priceAll;
	double priceOne;
};
bool compareGoods(goods A, goods B)
{
	return A.priceOne >= B.priceOne;
}
int main()
{
	int kind, demand;
	goods goodsOne;
	vector<goods> goodsAll;
	cin >> kind >> demand;
	goodsAll.resize(kind);
	for (int i = 0; i < kind; i++)
	{
		cin >> goodsAll[i].stock;
	}
	for (int i = 0; i < kind; i++)
	{
		cin >> goodsAll[i].priceAll;
	}
	for (int i = 0; i < kind; i++)
	{
		goodsAll[i].priceOne = goodsAll[i].priceAll / goodsAll[i].stock;
	}
	sort(goodsAll.begin(), goodsAll.end(), compareGoods);
	int count = 0;
	double profit = 0.0;
	while ((demand - goodsAll[count].stock)>0)
	{
		profit += goodsAll[count].priceAll;
		demand = demand - goodsAll[count].stock;
		count++;
		if (count >= kind)
			break;
	}
	if (count < kind)
	{
		profit = profit + demand*goodsAll[count].priceOne;
	}
	printf("%.2lf", profit);
	return 0;
}