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


//�ⷨ��ͨ����ѧ���ɷ��²��ƵõĹ�ʽ������λ����0��������5�ı�������һ��������صģ������ȳ���5������25֮ǰ����
//25�Ժ�25*4���Եõ������㣬��25����ʵ������5�������������㣬�����6����ô������ֻ��Ҫ�������nΪֹ5���ֵĴ�������
//100: 100/5=20, 20/5=4, 4<5ֹͣ���㡣 20+4=24
//25: 25/5 = 5, 5/5=1, 1<5ֹͣ���㡣 5+1=6
//80: 80/5 = 16, 16/5 =3, 3<5ֹͣ���㡣 16+3=19

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