/*-----------------------------------------------------------------
//461. Hamming Distance
//Easy
//The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
//
//Given two integers x and y, calculate the Hamming distance.
//
//Note:
//0 �� x, y < 231.
//
//Example:
//
//Input: x = 1, y = 4
//
//Output: 2
//
//Explanation:
//1   (0 0 0 1)
//4   (0 1 0 0)
//	   ��   ��
//
//The above arrows point to positions where the corresponding bits are different.
------------------------------------------------------------------*/

#include <string>

using namespace std;

class Solution {
public:
	int hammingDistance(int x, int y) {

		int n = x ^ y;

		uint32_t mask = 1;

		int result = 0;
		for(int i = 0; i < 32; i++)
		{
			int j = mask & n;
			if(j != 0)
			{
				result++;
			}

			mask = mask << 1;
		}

		return result;
	}
};


//int main()
//{
//	Solution so;
//	int result = so.hammingWeight(43261596);
//	//string result = so.convert("PAYPALISHIRING", 3);
//
//	return 0;
//
//}