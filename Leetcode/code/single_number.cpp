//-------------------------------------------------------------------------
//136. Single Number
//Given an array of integers, every element appears twice except for one.Find that single one.
//
//Note:
//Your algorithm should have a linear runtime complexity.Could you implement it without using extra memory ?
//---------------------------------------------------------------------------


#include <vector>
#include <algorithm> 

using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		//std::sort(nums.begin(), nums.end());

		//vector<int>::iterator  it = nums.begin();
		//vector<int>::iterator  it_end = nums.end();
		//for (; it != it_end;) {
		//	int a = *it;
		//	it++;
		//	int b = *it;

		//	if (a == b) {
		//		it++;
		//	}
		//	else {
		//		return a;
		//	}
		//}

		//return 0;

		size_t count = nums.size();
		for (int i = 1; i < count; ++i) nums[0] ^= nums[i];//通过方法xor可以将两个不同的数字

		return nums[0];
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