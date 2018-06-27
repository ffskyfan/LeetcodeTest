//4. Median of Two Sorted Arrays
//There are two sorted arrays nums1 and nums2 of size m and n respectively.
//
//Find the median of the two sorted arrays.The overall run time complexity should be O(log(m + n)).
//
//Example 1:
//nums1 = [1, 3]
//nums2 = [2]
//
//The median is 2.0
//Example 2 :
//	nums1 = [1, 2]
//	nums2 = [3, 4]
//
//The median is(2 + 3) / 2 = 2.5



#include <vector>

using namespace std;

namespace
{
	bool compare(vector<int>& nums, size_t count,  int& idx, int& temp_big, int& temp_small,bool& is_get_value)
	{
		is_get_value = false;
		if (idx >= count) {
			return true;
		}

		int number = nums[idx];
		is_get_value = true;
		if (number >= temp_big) {
			temp_small = temp_big;
			temp_big = number;
			idx++;
			return true;
		} else {
			if (number > temp_small) {
				temp_small = number;
			}
		}

		idx++;
		return false;
	}

}

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		size_t count1 = nums1.size();
		size_t count2 = nums2.size();
		size_t totalCount = count1 + count2;
		bool isEvent = (totalCount % 2 == 0) ? true : false;
		size_t midPos = 0;
		if (totalCount == 0) {
			return 0;
		}else if (totalCount == 1) {
			 midPos = 1;
		}else {
			 midPos = totalCount / 2;
		}

		int numsIdx1 = 0;
		int numsIdx2 = 0;
		int temp_big = 0;
		int temp_small = 0;

		bool isItNums1 = true;
		int pos = 0;
		while (true)
		{
			bool isFlop;
			bool isGetValue;
			if (isItNums1) {
				isFlop = compare(nums1, count1, numsIdx1, temp_big, temp_small,isGetValue);
				isItNums1 = isItNums1 && !isFlop;
			} else {
				isFlop = compare(nums2, count2, numsIdx2, temp_big, temp_small,isGetValue);
				isItNums1 = isItNums1 || isFlop;
			}

			if (!isGetValue && (numsIdx1<count1||numsIdx2<count2)) continue;

			if (pos == midPos) {

				int temp_big_big = temp_big;
				int temp_big = temp_small;
				if (isItNums1) {
					isFlop = compare(nums1, count1, numsIdx1, temp_big_big, temp_big, isGetValue);
				} else {
					isFlop = compare(nums2, count2, numsIdx2, temp_big_big, temp_big, isGetValue);
				}

				if (!isGetValue) {
					temp_big = temp_big_big;
				}

				if (isEvent) {
					return double(temp_big + temp_small) / 2.0;
				}
				else {
					return temp_big;
				}
			}

			pos++;
		}
        
    }
};


int main()
{
	vector<int> nums1 = {1,2};
	vector<int> nums2 = {1,1};

	Solution so;
	double result = so.findMedianSortedArrays(nums1, nums2);

	return 0;
}