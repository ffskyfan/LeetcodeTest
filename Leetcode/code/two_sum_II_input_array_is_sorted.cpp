/*-----------------------------------------------------------------
//167. Two Sum II - Input array is sorted
//Easy
//Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.
//
//The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.
//
//Note:
//
//Your returned answers (both index1 and index2) are not zero-based.
//You may assume that each input would have exactly one solution and you may not use the same element twice.
//Example:
//
//Input: numbers = [2,7,11,15], target = 9
//Output: [1,2]
//Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
------------------------------------------------------------------*/

#include <vector>


class Solution {

public:
	std::vector<int> twoSum(std::vector<int>& numbers, int target) {

		int count = static_cast<int>(numbers.size());
		for(int i = 0; i < count; i++)
		{
			if(numbers[i] > target) return std::vector<int>();

			int subTarget = target - numbers[i];

			int start = i+1;
			int end = count - 1;
			for(;start<=end;)
			{
				int mid = start + ((end - start) / 2);
				if(numbers[mid]==subTarget) 
				{
					std::vector<int> result;
					result.push_back(i+1);
					result.push_back(mid+1);
					return result;
				}

				if(subTarget > numbers[mid])
				{
					start = mid + 1;
				}
				else
				{
					end = mid-1;
				}
			}
		}

		return std::vector<int>();

	}
};

//int main()
//{
//	Solution so;
//	std::vector<int> numbers = {-1,0};
//	std::vector<int> result = so.twoSum(numbers,-1);
//
//	return 0;
//
//}