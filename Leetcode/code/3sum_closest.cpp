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

	int FindClosestIdx(std::vector<int>& nums, int target)
	{
		int interval = 0;
		int begin = 0;
		int end = static_cast<int>(nums.size()-1);
		int mid = 0;
		for(; begin <= end;)
		{
			mid = begin + ((end - begin) / 2);
			interval = target - nums[mid];

			if(target > nums[mid])
			{
				begin = mid + 1;
			}
			else if(target < nums[mid])
			{
				end = mid - 1;
			}
			else
			{
				break;
			}
		}

		if(nums[mid] == target) return mid;

		if(mid - 1 >= 0 && ((abs(target - nums[mid - 1]) < abs(target - nums[mid]))
		{
				return mid - 1;
		}
		else if(mid + 1 <= static_cast<int>(nums.size() - 1) && ((abs(target - nums[mid + 1]) < abs(target - nums[mid]))
		{
			return mid + 1;
		}

		return mid;
	}


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

		int targetClosestIdx = FindClosestIdx(nums, target);
		int zeroClosestIdx = FindClosestIdx(nums, 0);
		if(zeroClosestIdx == targetClosestIdx)

		int zeroClosestBeforIdx = zeroClosestIdx - 1;
		int zeroClosestAfterIdx = zeroClosestIdx + 1;
		if(zeroClosestBeforIdx < 0)
		{
			return nums[targetClosestIdx]

		}
		else if(zeroClosestAfterIdx >= count)
		{

		}
		else
		{

		}


	}
};

int main()
{
	Solution so;
	std::vector<int> numbers = {-1,0,1,2,-1,-4};
	int result = so.threeSumClosest(numbers, 3);

	return 0;

}