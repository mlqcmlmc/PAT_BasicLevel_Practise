#include<iostream>
#include<algorithm>
#include "stdio.h"
#define int64 long long int 
using namespace std;

int64 MaxCommonDiv(int64 a, int64 b)
{
	int64 min, max;
	a = abs(a);
	b = abs(b);
	return b == 0 ? a : MaxCommonDiv(b, a%b);
}
class Fraction
{
public:
	Fraction() = default;//默认构造函数
	Fraction(int64 a, int64 b, int effect=1)//构造函数
	{
		this->effect = effect;
		if (effect)
		{
			if (a%b == 0)
			{
				numerator = a / b;
				denominator = 1;
			}
			else
			{
				int64 maxab = MaxCommonDiv(a, b);
				numerator = a / maxab;
				denominator = b / maxab;
			}
		}

	}
	friend Fraction operator+ (const Fraction &lhs, const Fraction &rhs)
	{
		int64 a = lhs.numerator*rhs.denominator + lhs.denominator*rhs.numerator;
		int64 b = lhs.denominator*rhs.denominator;
		int64 maxab = MaxCommonDiv(a, b);
		return Fraction(a / maxab, b / maxab);
	}
	friend Fraction operator- (const Fraction &lhs, const Fraction &rhs)
	{
		int64 a = lhs.numerator*rhs.denominator - lhs.denominator*rhs.numerator;
		int64 b = lhs.denominator*rhs.denominator;
		int64 maxab = MaxCommonDiv(a, b);
		return Fraction(a / maxab, b / maxab);
	}
	friend Fraction operator* (const Fraction &lhs, const Fraction &rhs)
	{
		int64 a = lhs.numerator*rhs.numerator;
		int64 b = lhs.denominator*rhs.denominator;
		int64 maxab = MaxCommonDiv(a, b);
		return Fraction(a / maxab, b / maxab);
	}
	friend Fraction operator/ (const Fraction &lhs, const Fraction &rhs)
	{
		int64 a = lhs.numerator*rhs.denominator;
		int64 b = lhs.denominator*rhs.numerator;
		if (b < 0)
		{
			a = a*(-1);
			b = b*(-1);
		}
		int64 maxab = MaxCommonDiv(a, b);
		if (b == 0)
		{
			return Fraction(a / maxab, b / maxab, 0);
		}
		else
		{
			return Fraction(a / maxab, b / maxab);
		}
	}
	friend ostream &operator << (ostream &os, const Fraction &item)
	{
		if (item.effect == 0)
		{
			os << "Inf";
		}
		else 
		{
			int brackets = 0;
			if (item.numerator < 0)
			{
				brackets = 1;
			}
			if (item.denominator == 1)
			{
				if (brackets)
				{
					os << '(' << item.numerator << ')';
				}
				else
				{
					os << item.numerator;
				}
			}
			else
			{
				if (brackets)
				{
					os << '(';
				}
				if (item.numerator / item.denominator != 0)
				{
					os << item.numerator / item.denominator << ' ';
					os << abs(item.numerator % item.denominator) << '/' << item.denominator;
				}
				else
				{
					os << item.numerator % item.denominator << '/' << item.denominator;
				}
				if (brackets)
				{
					os << ')';
				}

			}
		}
		return os;
	}


private:
	int64 numerator;
	int64 denominator;
	int effect;

};
int main()
{
	int64 a1, b1, a2, b2;
	scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);
	Fraction num1(a1, b1), num2(a2, b2);
	cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
	cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
	cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
	cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
	return 0;
}