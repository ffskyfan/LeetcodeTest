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


	bool IsSame(const std::vector<int>& a, const std::vector<int>& b)
	{
		if(a[0]==b[0]&&a[1]==b[1]&&a[2]==b[2]) return true;

		return false;
	}

	bool IsAlreadyHave(const std::vector<std::vector<int>>& a, const std::vector<int>& b)
	{
		for(const std::vector<int> content : a)
		{
			if(IsSame(content, b)) return true;
		}

		return false;
	}

public:
	std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {

		std::vector<std::vector<int>> result;
		int count = static_cast<int>(nums.size());
		for(int i = 0; i < count; i++)
		{
			int a = nums[i];
			a = 0 - a;
			for(int j = i + 1; j < count; j++)
			{
				int b = nums[j];
				b = a - b;

				std::set<int> answerbs;

				for(int h = j + 1; h < count; h++)
				{
					int c = nums[h];
					if(c == b) 
					{ 
						std::vector<int> part = {nums[i], nums[j], nums[h]};
						std::sort(part.begin(), part.end());

						if(!IsAlreadyHave(result,  part)) {

							answerbs[nums[j]];
				
							result.push_back(part);
						}
						break;
					}
				}
			}
		}

		return result;

	}
};

int main()
{
	Solution so;
	std::vector<int> numbers = {-1,0,1,2,-1,-4};
	std::vector<std::vector<int>> result = so.threeSum(numbers);

	return 0;

}