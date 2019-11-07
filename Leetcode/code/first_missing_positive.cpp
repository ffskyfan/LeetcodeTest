//-------------------------------------------------------------------------
//41. First Missing Positive
//Hard
//Given an unsorted integer array, find the smallest missing positive integer.
//
//Example 1:
//
//Input: [1, 2, 0]
//	Output : 3
//	Example 2 :
//
//	Input : [3, 4, -1, 1]
//	Output : 2
//	Example 3 :
//
//	Input : [7, 8, 9, 11, 12]
//	Output : 1
//	Note :
//
//	Your algorithm should run in O(n) time and uses constant extra space.
//---------------------------------------------------------------------------


#include <vector>
#include <algorithm> 

using namespace std;

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int count = static_cast<int>(nums.size());

		int continuMin = 0;
		int continuMax = 0;
		int needlessCount = 0;
		int result = 1;
		for(int i = 0; i < count; i++)
		{
			if(nums[i] <= 0)
			{
				needlessCount++;
				continue;
			}

			if(continuMin == 0) 
			{
				continuMin = nums[i];
				continuMax = nums[i];
			}


			if(result==nums[i]) result++;

		}

	}
};



//int main()
//{
//	Solution so;
//	vector<int> x = {2,3,4,2,4};
//	int result = so.singleNumber(x);
//	//string result = so.convert("PAYPALISHIRING", 3);
//
//	return 0;
//
//}