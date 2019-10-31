//--------------------------------------------------------------------
//169. Majority Element
//Easy
//Given an array of size n, find the majority element.The majority element is the element that appears more than ⌊ n / 2 ⌋ times.
//
//You may assume that the array is non - empty and the majority element always exist in the array.
//
//Example 1:
//
//Input: [3, 2, 3]
//	Output : 3
//	Example 2 :
//
//	Input : [2, 2, 1, 1, 1, 2, 2]
//	Output : 2
//--------------------------------------------------------------------

#include <string>
#include <vector>
#include <map>




class Solution {

	std::map<int ,int> numCounts;

public:
	int majorityElement(std::vector<int>& nums) {

		int maxCount = 0;
		int size = static_cast<int>(nums.size());
		int threshold = size/2;

		for(int i = 0; i < size; i++)
		{
			int value = nums[i];
			int count = 0;
			if(numCounts.find(value) != numCounts.end())
			{
				count = ++numCounts[value];
			}
			else
			{
				count = 1;
				numCounts[value] = count;
			}

			if(count > threshold) return value;
		}

		return 0;
	}

};



//int main()
//{
//	Solution so;
//	std::vector<int> digits={1};
//	
//
//	int result = so.majorityElement(digits);
//
//	return 0;
//
//}


