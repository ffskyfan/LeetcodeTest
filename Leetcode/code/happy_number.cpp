/*-----------------------------------------------------------------
202. Happy Number
Easy
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example:

Input: 19
Output: true
Explanation:
1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 02 = 1
------------------------------------------------------------------*/

#include <set>

using namespace std;

class Solution {

	bool isHappy(int n, std::set<int>& oldNums) 
	{
		int number = 0;
		for(;;)
		{
			int x = n % 10;
			number += x * x;

			n = n / 10;
			if(n == 0) break;
		}
		
		if(number == 1) return true;

		if(oldNums.find(number) != oldNums.end()) return false;
		oldNums.insert(number);

		return isHappy(number, oldNums);

	}

public:
	bool isHappy(int n) {
		std::set<int> oldNums;

		return isHappy(n, oldNums);
	}
};


//int main()
//{
//	Solution so;
//	bool result = so.isHappy(19);
//	return 0;
//
//}