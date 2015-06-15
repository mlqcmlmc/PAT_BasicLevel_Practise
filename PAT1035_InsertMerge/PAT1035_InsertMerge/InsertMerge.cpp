#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
void merge(vector<int>  &str, int b, int c, int e)
{
	vector<int>  strsortsub=str;
	int i = b, j = c + 1;
	for (int k = b; k <= e; k++)
	{
		if (i > c)
		{
			strsortsub[k] = str[j];
			j++;
		}
		else if (j > e)
		{
			strsortsub[k] = str[i];
			i++;
		}
		else if (str[i] < str[j])
		{
			strsortsub[k] = str[i];
			i++;
		}
		else
		{
			strsortsub[k] = str[j];
			j++;
		}
	}
	for (int k = b; k <= e; k++)
	{
		str[k] = strsortsub[k];
	}
}

void mergesort(vector<int>  tempNum, vector<int>  centerNum, vector<int>  &outstr)
{
	bool mergeFlag = false;
	for (int k = 1; k < tempNum.size() && !mergeFlag; k = k + k)
	{
		if (tempNum==centerNum)
		{
			mergeFlag = 1;
		}
		for (int m = 0; m < tempNum.size() - k; m = m + 2 * k)
		{
			int lo = m, mid = m + k - 1, hi = min(m + k + k - 1, (int)tempNum.size() - 1);
			merge(tempNum, lo, mid, hi);
		}
		if (mergeFlag)
		{
			outstr = tempNum;
		}
	}
}



void insertsort(vector<int> tempNum, vector<int>  centerNum, vector<int>  &outstr)
{
	bool insertFlag = false;
	for (int i = 1; i < tempNum.size(); i++)
	{
		bool isSwap = 0;
		if (tempNum==centerNum)
		{
			insertFlag = 1;
		}
		for (int j = i; j >= 1 && tempNum[j - 1]>tempNum[j]; j--)
		{
			swap(tempNum[j], tempNum[j - 1]);
			isSwap = 1;
		}
		if (isSwap && insertFlag)
		{
			outstr = tempNum;
			break;
		}

	}
}
int main()
{
	int N, temp;
	vector<int> originalNum, centerNum, outstr;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		originalNum.push_back(temp);
	}
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		centerNum.push_back(temp);
	}
	//≤Â»Î≈≈–Ú
	outstr.clear();
	insertsort(originalNum, centerNum, outstr);
	if (outstr.size() != 0)
	{
		cout << "Insertion Sort" << endl;
		cout << outstr[0];
		for (int i = 1; i < outstr.size(); i++)
			cout << ' ' << outstr[i];
		cout << endl;
		return 0;
	}
	//πÈ≤¢≈≈–Ú
	outstr.clear();
	mergesort(originalNum, centerNum, outstr);
	if (outstr.size() != 0)
	{
		cout << "Merge Sort" << endl;
		cout << outstr[0];
		for (int i = 1; i < outstr.size(); i++)
			cout << ' ' << outstr[i];
		cout << endl;
		return 0;
	}
	return 0;

}