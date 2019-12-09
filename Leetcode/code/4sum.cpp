/*-----------------------------------------------------------------
//18. 4Sum
//Medium
//Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
//
//Note:
//
//The solution set must not contain duplicate quadruplets.
//
//Example:
//
//Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
//
//A solution set is:
//[
//  [-1,  0, 0, 1],
//  [-2, -1, 1, 2],
//  [-2,  0, 0, 2]
//]
------------------------------------------------------------------*/

#include <vector>
#include <set>
#include <algorithm>

class Solution {
	const int MaxDepth = 3;

	void Check(const std::vector<int>& nums, int begin, int end, int want, int depth, std::vector<int>& result, std::vector<std::vector<int>>& allResult)
	{
		if(depth == MaxDepth) 
		{
			if(want<nums[begin] || want>nums[end]) return;
			for(; begin <= end;) 
			{
				int mid = begin + ((end - begin) / 2);
				if(nums[mid] == want) 
				{
					result.push_back(want);
					allResult.push_back(result);
					result.pop_back();
					return;
				}

				if(want > nums[mid]) 
				{
					begin = mid + 1;
				}
				else 
				{
					end = mid - 1;
				}
			}
		}
		else
		{
			if(depth == 1)
			{
				if(want >= 0 && nums[end] < 0) return;
				if(want <= 0 && nums[begin] > 0) return;
			}

			for(int i = begin; i < end; i++)
			{
				int a = nums[i];
				if(i > begin&& a == nums[i - 1]) continue;

				result.push_back(a);

				a = want - a;
				Check(nums, i + 1, end, a, depth + 1, result, allResult);
				result.pop_back();
			}
		}



	}


public:
	std::vector<std::vector<int>> fourSum(std::vector<int>& nums,int target) {

		std::vector<std::vector<int>> allResult;

		int count = static_cast<int>(nums.size());
		if(count < 3) return allResult;

		std::sort(nums.begin(), nums.end());

		std::vector<int> result;
		Check(nums, 0, count-1, target, 0, result, allResult);

		return allResult;
	}
};

//int main()
//{
//	Solution so;
//	std::vector<int> numbers = {-1,0,1,2,-1,-4};
//	std::vector<std::vector<int>> result = so.fourSum(numbers);
//
//	return 0;
//
//}