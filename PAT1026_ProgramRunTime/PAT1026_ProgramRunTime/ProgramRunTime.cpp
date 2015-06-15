#include<iostream>
#include "stdio.h"
using namespace std;
#define CLK_TCK 100.0
int main()
{
	long int startclk, endclk,longTime;
	long double longclk;
	int shi, fen, miao;
	cin >> startclk >> endclk;
	longclk = (endclk - startclk);
	longTime = (long int)(longclk/ CLK_TCK +0.5);
	shi = longTime / 3600;
	fen = (longTime % 3600) / 60;
	miao = (longTime % 3600) % 60;
	printf("%02d:%02d:%02d\n", shi, fen, miao);
	return 0;

}