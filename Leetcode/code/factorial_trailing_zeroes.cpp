//-------------------------------------------------------------------------
//172. Factorial Trailing Zeroes
//Easy
//Given an integer n, return the number of trailing zeroes in n!.
//
//Example 1:
//
//Input: 3
//	Output : 0
//	Explanation : 3!= 6, no trailing zero.
//	Example 2 :
//
//	Input : 5
//	Output : 1
//	Explanation : 5!= 120, one trailing zero.
//	Note : Your solution should be in logarithmic time complexity.
//---------------------------------------------------------------------------


#include <vector>
#include <algorithm> 

using namespace std;

class Solution {
public:
	int trailingZeroes(int n) {

		int left = n;
		int result = 0;
		for(;;)
		{
			if(left<5) break;
			left = left/5;
			result += left;
		}

		return result;
	}
};


//解法，通过数学归纳法猜测推得的公式，首先位数是0的数量和5的倍数出现一定是正相关的，所以先除以5看看，25之前都对
//25以后，25*4可以得到两个零，而25里其实有两个5，所以是两个零，结果是6，那么，我们只需要计算出到n为止5出现的次数就行
//100: 100/5=20, 20/5=4, 4<5停止计算。 20+4=24
//25: 25/5 = 5, 5/5=1, 1<5停止计算。 5+1=6
//80: 80/5 = 16, 16/5 =3, 3<5停止计算。 16+3=19

//int main()
//{
//	Solution so;
//	vector<int> x = {2,3,4,2,4};
//	int result = so.singleNumber(x);
//	//string result = so.convert("PAYPALISHIRING", 3);
//
//	return 0;
//
//}