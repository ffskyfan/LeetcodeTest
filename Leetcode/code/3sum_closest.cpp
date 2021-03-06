/*-----------------------------------------------------------------
//16. 3Sum Closest
//Medium
//Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
//
//Example:
//
//Given array nums = [-1, 2, 1, -4], and target = 1.
//
//The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
------------------------------------------------------------------*/

#include <vector>
#include <set>
#include <algorithm>

class Solution {


public:
	int threeSumClosest(std::vector<int>& nums, int target) {
		int count = static_cast<int>(nums.size());
		if(count <= 3)
		{
			int result = 0;
			for(int a : nums)
			{
				result += a;
			}
			return result;
		}

		std::sort(nums.begin(), nums.end());

		return 0;



	}
};

//int main()
//{
//	Solution so;
//	std::vector<int> numbers = {-1,0,1,2,-1,-4};
//	int result = so.threeSumClosest(numbers, 3);
//
//	return 0;
//
//}