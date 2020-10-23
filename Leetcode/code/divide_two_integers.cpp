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

		uint32_t x = 1 << 32 - 1;
		int minInt = int(x);

		if(divisor==1) return dividend;
		if(dividend==0) return dividend;
		if(divisor==-1) 
		{
			if(dividend == minInt)dividend++;
			return -dividend;
		}

		if(divisor==minInt){
			if(dividend==minInt) return 1;
			return 0;
		}

		bool isNeedPatch = false;
		if(dividend == minInt) 
		{
			dividend++;
			isNeedPatch = true;
		}


		bool isPositive  = true;
		if((dividend<0&&divisor>0)||(dividend>0&&divisor<0)) isPositive=false;

		int surplus = abs(dividend);
		int newBaseDivisor = abs(divisor);
		int newDivisor = newBaseDivisor;

		int result = 0;

		const int maxDivisor = 1<<30;
		if(newDivisor >= maxDivisor) 
		{
			if(surplus>=maxDivisor) 
			{
				if(surplus>=newDivisor) result = 1;
			}

			if(isPositive)
			{
				return result;
			}
			else
			{
				return -result;
			}
		}

		vector<int> newDivisorStack;

		int idx = 0;
		int subtractionTimes = 1;
		bool isDivisorGrowing = true;
		for(;;)
		{
			if(surplus==0) break;

			if (surplus < newDivisor)
			{
				if(subtractionTimes == 0 || subtractionTimes == 1) break;

				if(isDivisorGrowing == true)  isDivisorGrowing = false;
				subtractionTimes = subtractionTimes >> 1;
				newDivisor = newDivisor >> 1;
				continue;
			}

			surplus = surplus - newDivisor;
			if(isNeedPatch)
			{
				surplus++;
				isNeedPatch = false;
			}

			if (surplus >= 0)
			{
				result += subtractionTimes;
			}
			else
			{
				continue;//按道理到不了这里，在这里加段防御性代码，如果到了，可能有我没想到的地方。
			}

			if(newDivisor < maxDivisor)
			{//左移不会溢出
				if(isDivisorGrowing)
				{
					newDivisor = newDivisor << 1;
					subtractionTimes = subtractionTimes << 1;
				}
				else
				{
					if(newDivisor > newBaseDivisor)
					{
						newDivisor = newDivisor >> 1;
						subtractionTimes = subtractionTimes >> 1;
					}
				}
			}


		}

		if(isPositive)
		{
			return result;
		}
		else
		{
			return -result;
		}

	}
};

//解法：先用dividend减去divisor,然后次数+1， 看看减的结果是否小于divisor,如果小于返回次数，否则divisor自己加自己(用左移操作符实现，快)，形成新的divisor
//再用减后的结果减去新的divisor，就这样divisor成倍增大，直到新结果小于新divisor，然后divisor开始成倍缩小，直到divisor回到原来大小，
//这时新结果肯定小于divisor，就是除完了，我们把divisor积累的倍数加起来，就是最后的商
//效率是O(logn)
//abs在处理INT_MIN时是未定义行为，vs上面是直接返回原来的值，不做处理。

//int main()
//{
//	uint32_t x = 1<<32 -1;
//	int dividend = int(x);
//	//dividend++;
//
//	
//	Solution so;
//	int result = so.divide(1076233784, -1766978113);
//
//	return 0;
//
//}


