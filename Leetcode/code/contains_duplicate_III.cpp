//--------------------------------------------------------------------
//220. Contains Duplicate III
//Medium
//Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.
//
//Example 1:
//
//Input: nums = [1, 2, 3, 1], k = 3, t = 0
//	Output : true
//	Example 2 :
//
//	Input : nums = [1, 0, 1, 1], k = 1, t = 2
//	Output : true
//	Example 3 :
//
//	Input : nums = [1, 5, 9, 1, 5, 9], k = 2, t = 3
//	Output : false
//--------------------------------------------------------------------

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		if(k == 0) return false;
		int count = static_cast<int>(nums.size());

		bool isITurn = false;
		for(int i = 0, j = 1; ; )
		{
			if(abs(nums[i] - nums[j]) <= t) return true;
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

				if(j == count)
				{
					j = count - 1;
					isITurn = true;
					i++;
				}
				else if((j - i) == k + 1 )
				{
					isITurn = true;
					i++;
				}

			}

			if(i == j && i == k - 1) break;
		}

		return false;


	}
};




//int main()
//{
//
//	Solution so;
//	vector<int> a = { 7,1,3 };
//	bool result = so.containsNearbyAlmostDuplicate(a, 2, 3);
//
//	return 0;
//
//}


