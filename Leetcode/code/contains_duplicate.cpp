//--------------------------------------------------------------------
//217. Contains Duplicate
//Easy
//Given an array of integers, find if the array contains any duplicates.
//
//Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
//
//Example 1:
//
//Input: [1, 2, 3, 1]
//	Output : true
//	Example 2 :
//
//	Input : [1, 2, 3, 4]
//	Output : false
//	Example 3 :
//
//	Input : [1, 1, 1, 3, 3, 4, 3, 2, 4, 2]
//	Output : true
//--------------------------------------------------------------------

#include <vector>
#include <algorithm>


class Solution {
public:
	bool containsDuplicate(std::vector<int>& nums) {
		int count = static_cast<int>(nums.size());
		if(count<2) return false;

		std::sort(nums.begin(), nums.end());

		int temp = 0;
		for(int i=0; i<count; i++)
		{
			if(i==0) 
			{
				temp = nums[i];
				continue;
			}

			if(temp == nums[i]) return true;
			temp = nums[i];
		}

		return false;
	}
};




//int main()
//{
//
//	Solution so;
//	int result = so.countPrimes(10);
//
//	return 0;
//
//}


