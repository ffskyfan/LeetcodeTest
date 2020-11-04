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

		vector<int> numsLessTheCount;
		numsLessTheCount.resize(count + 1, 0);

		for(int i = 0; i < count; i++)
		{
			int num = nums[i];
			if(num<0) continue;
			if(num <= count)
			{
				numsLessTheCount[num] = num;
			}
		}

		for(int i = 1; i < count+1; i++)
		{
			if(numsLessTheCount[i]==0) return i;
		}

		return count+1;
	}
};



//int main()
//{
//	Solution so;
//	vector<int> x = {1,2,0};
//	int result = so.firstMissingPositive(x);
//	//string result = so.convert("PAYPALISHIRING", 3);
//
//	return 0;
//
//}