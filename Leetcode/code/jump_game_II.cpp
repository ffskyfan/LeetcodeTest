//--------------------------------------------------------------------
//45. Jump Game II
//Hard
//Given an array of non - negative integers nums, you are initially positioned at the first index of the array.
//
//Each element in the array represents your maximum jump length at that position.
//
//Your goal is to reach the last index in the minimum number of jumps.
//
//You can assume that you can always reach the last index.
//
//
//
//Example 1:
//
//Input: nums = [2, 3, 1, 1, 4]
//Output : 2
//Explanation : The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
//Example 2 :
//
//	Input : nums = [2, 3, 0, 1, 4]
//	Output : 2
//
//
//	Constraints :
//
//	1 <= nums.length <= 3 * 104
//	0 <= nums[i] <= 105
//--------------------------------------------------------------------

#include <vector>
#include <algorithm>

using namespace std;

class Solution {

	int jumpEx(vector<int>& nums,const int& count, int idx)
	{
		vector<int> allPossibleIdx;
		for(int i = idx-1; i >= 0; i--)
		{
			int number = nums[i];
			if(i + number >= idx)
			{
				allPossibleIdx.push_back(i);

			}
		}

		std::sort(allPossibleIdx.begin(), allPossibleIdx.end());
		if(allPossibleIdx[0]==0) return 1;

		int possibleCount = static_cast<int>(allPossibleIdx.size());
		int result = 0;
		for(int j = 0 ; j < possibleCount; j++)
		{
			int pIdx = allPossibleIdx[j];
			int x = jumpEx(nums, count, pIdx);

			if(x == 0) continue;

			if(result == 0) result = x;
			else if(x < result) result = x;

		}
			
		if(result == 0) return 0;
		else return result + 1;
	}


public:
    int jump(vector<int>& nums) {

		int count = static_cast<int>(nums.size());
		if(count<=1) return 0;
		int result = jumpEx(nums, count, count-1);

		return result;
    }
};




int main()
{
	vector<int> candidates = { 5,6,4,4,6,9,4,4,7,4,4,8,2,6,8,1,5,9,6,5,2,7,9,7,9,6,9,4,1,6,8,8,4,4,2,0,3,8,5 };

	Solution so;
	int result = so.jump(candidates);

	return 0;

}


