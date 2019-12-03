/*-----------------------------------------------------------------
//15. 3Sum
//Medium
//Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
//
//Note:
//
//The solution set must not contain duplicate triplets.
//
//Example:
//
//Given array nums = [-1, 0, 1, 2, -1, -4],
//
//A solution set is:
//[
//  [-1, 0, 1],
//  [-1, -1, 2]
//]
------------------------------------------------------------------*/

#include <vector>
#include <set>
#include <algorithm>

class Solution {
	const int MaxDepth = 2;

	void Check(const std::vector<int>& nums, int begin, int end, int want, int depth, std::vector<int>& result, std::vector<std::vector<int>>& allResult)
	{
		for(int i = begin; i < end; i++)
		{
			int a = nums[i];
			if(i > begin&& a == nums[i - 1]) continue;

			if(depth == MaxDepth)
			{
				if(a != want) continue;

				result.push_back(a);
				allResult.push_back(result);
				result.pop_back();
				return;
			}
			else
			{
				result.push_back(a);

				a = want - a;
				Check(nums, i + 1, end, a, depth + 1, result, allResult);
				result.pop_back();
			}

		}

	}


public:
	std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {


		std::sort(nums.begin(), nums.end());

		std::vector<int> result;
		std::vector<std::vector<int>> allResult;

		int count = static_cast<int>(nums.size());

		Check(nums, 0, count, 0, 0, result, allResult);


		return allResult;

	}
};

int main()
{
	Solution so;
	std::vector<int> numbers = {-1,0,1,2,-1,-4};
	std::vector<std::vector<int>> result = so.threeSum(numbers);

	return 0;

}