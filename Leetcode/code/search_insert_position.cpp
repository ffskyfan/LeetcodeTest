//--------------------------------------------------------------------
//35. Search Insert Position
//Easy
//Given a sorted array and a target value, return the index if the target is found.If not, return the index where it would be if it were inserted in order.
//
//You may assume no duplicates in the array.
//
//Example 1:
//
//Input: [1, 3, 5, 6], 5
//	Output : 2
//	Example 2 :
//
//	Input : [1, 3, 5, 6], 2
//	Output : 1
//	Example 3 :
//
//	Input : [1, 3, 5, 6], 7
//	Output : 4
//	Example 4 :
//
//	Input : [1, 3, 5, 6], 0
//	Output : 0
//--------------------------------------------------------------------

#include <string>
#include <vector>
#include <list>




class Solution {


public:
	int searchInsert(std::vector<int>& nums, int target) {
		int start = 0;
		int end = static_cast<int>(nums.size())-1;
		int i = 0;
		for(; start <= end;)
		{
			i = start + (end - start) / 2;
			int number = nums[i];
			if(target > number)
			{
				start= i+1;
			}
			else if(target < number)
			{
				end = i-1;
			}
			else
			{
				return i;
			}
		}

		if(start >= static_cast<int>(nums.size())) start = end;
		if(end < 0) end = start;

		if(target > nums[end]) 
		{
			return end+1;
		}
		else
		{
			return end;
		}
	}


};



//int main()
//{
//	Solution so;
//	std::vector<int> nums = { 1,3,5,6 };
//
//	int result = so.searchInsert(nums, 2);
//
//	return 0;
//
//}


