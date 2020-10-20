//--------------------------------------------------------------------
//29. Divide Two Integers
//Medium
//Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.
//
//Return the quotient after dividing dividend by divisor.
//
//The integer division should truncate toward zero, which means losing its fractional part.For example, truncate(8.345) = 8 and truncate(-2.7335) = -2.
//
//Note:
//
//Assume we are dealing with an environment that could only store integers within the 32 - bit signed integer range : [−231, 231 − 1].For this problem, assume that your function returns 231 − 1 when the division result overflows.
//
//
//Example 1 :
//
//	Input : dividend = 10, divisor = 3
//	Output : 3
//	Explanation : 10 / 3 = truncate(3.33333..) = 3.
//	Example 2 :
//
//	Input : dividend = 7, divisor = -3
//	Output : -2
//	Explanation : 7 / -3 = truncate(-2.33333..) = -2.
//	Example 3 :
//
//	Input : dividend = 0, divisor = 1
//	Output : 0
//	Example 4 :
//
//	Input : dividend = 1, divisor = 1
//	Output : 1
//
//
//Constraints :
//
//	-231 <= dividend, divisor <= 231 - 1
//	divisor != 0
//--------------------------------------------------------------------

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int divide(int dividend, int divisor) {
		if(divisor==1) return dividend;
		if(dividend==0) return dividend;

		bool isPositive  = true;
		if((dividend<0&&divisor>0)||(dividend>0&&divisor<0)) isPositive=false;

		int surplus = abs(dividend);
		int newDivisor = abs(divisor);

		vector<int> newDivisorStack;

		int result = 0;
		int idx = 0;
		int subtractionTimes = 0;
		for(;;)
		{
			if (surplus < newDivisor)
			{
				if(subtractionTimes==0 || subtractionTimes==1) return result;

				subtractionTimes = subtractionTimes >> 1;
			}

			surplus = surplus - newDivisor;
			if (subtractionTimes == 0)
				subtractionTimes++;
			else
				subtractionTimes = subtractionTimes << 1;

			if (surplus > 0)
			{
				result += subtractionTimes;
			}
		}


	}
};

//解法：先用dividend减去divisor,然后次数+1， 看看减的结果是否小于divisor,如果小于返回次数，否则divisor自己加自己，形成新的divisor
//再用减后的结果减去新的divisor，

//int main()
//{
//	vector<int> candidates = { 2,3,6,7,10 };
//
//	Solution so;
//	vector<vector<int>> result = so.combinationSum(candidates, 10);
//
//	return 0;
//
//}


