//--------------------------------------------------------------------
//219. Contains Duplicate II
//Easy
//Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.
//
//Example 1:
//
//Input: nums = [1, 2, 3, 1], k = 3
//	Output : true
//	Example 2 :
//
//	Input : nums = [1, 0, 1, 1], k = 1
//	Output : true
//	Example 3 :
//
//	Input : nums = [1, 2, 3, 1, 2, 3], k = 2
//	Output : false
//--------------------------------------------------------------------

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		if(k == 0) return false;
		int count = static_cast<int>(nums.size());

		bool isITurn = false;
		for(int i = 0, j = 1; j < count; )
		{
			if(nums[i] == nums[j]) return true;
			if(isITurn)
			{
				i++;
				if(i == j)
				{
					isITurn = false;
					j++;
				}
			}
			else
			{
				j++;
				if((j - i) == k + 1)
				{
					isITurn = true;
					i++;
				}
			}
		}

		return false;


	}
};




//int main()
//{
//
//	Solution so;
//	vector<int> a = { 1,0,1,1 };
//	int result = so.containsNearbyDuplicate(a, 1);
//
//	return 0;
//
//}


