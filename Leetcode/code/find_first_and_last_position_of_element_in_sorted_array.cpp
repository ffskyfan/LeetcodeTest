//--------------------------------------------------------------------
//34. Find First and Last Position of Element in Sorted Array
//Medium
//Given an array of integers nums sorted in ascending order, find the startingand ending position of a given target value.
//
//If target is not found in the array, return[-1, -1].
//
//Follow up : Could you write an algorithm with O(log n) runtime complexity ?
//
//
//
//Example 1 :
//
//	Input : nums = [5, 7, 7, 8, 8, 10], target = 8
//	Output : [3, 4]
//	Example 2 :
//
//	Input : nums = [5, 7, 7, 8, 8, 10], target = 6
//	Output : [-1, -1]
//	Example 3 :
//
//	Input : nums = [], target = 0
//	Output : [-1, -1]
//
//
//	Constraints :
//
//	0 <= nums.length <= 105
//	- 109 <= nums[i] <= 109
//	nums is a non - decreasing array.
//	- 109 <= target <= 109
//--------------------------------------------------------------------

#include <string>
#include <vector>


using namespace std;


class Solution {



public:
	vector<int> searchRange(vector<int>& nums, int target) {

		vector<int> result ={-1,-1};

		size_t numCount = nums.size();
		int begin = 0;
		int end = static_cast<int>(numCount)-1;
		if(nums.empty()) return result;
		if(numCount == 1)
		{
			if(nums[0] == target)
			{
				result[0] = 0;
				result[1] = 0;
			}

			return result;
		}
		if(target<nums[begin] || target>nums[end]) return result;

		int pos = -1;
		for(; begin <= end;)
		{
			int mid = begin + ((end - begin) / 2);
			if(nums[mid] == target)
			{
				pos = mid;
				break;
			}

			if(target > nums[mid])
			{
				begin = mid + 1;
			}
			else
			{
				end = mid - 1;
			}
		}

		if(pos==-1) return result;

		int rightBegin = 0;
		int rightEnd = pos;
		for(;rightBegin < rightEnd;)
		{
			int mid = rightBegin + ((rightEnd - rightBegin) / 2);
			if(nums[mid] == target)
			{
				if(mid==0) 
				{ 
					rightEnd=mid;
					break;
				}
				rightEnd = mid-1;
			}
			else
			{
				rightBegin = mid+1;
			}
		}

		if(nums[rightEnd] == target)
		{
			result[0] = rightEnd;
		}
		else
		{
			result[0] = rightEnd+1;
		}

		int leftBegin = pos;
		int leftEnd = numCount-1;
		for(;leftBegin < leftEnd;)
		{
			int mid = leftBegin + ((leftEnd - leftBegin) / 2);
			if(nums[mid] == target)
			{
				if(mid == numCount - 1)
				{
					leftBegin = mid;
					break;
				}
				leftBegin = mid+1;
			}
			else
			{
				leftEnd = mid-1;
			}
		}

		if(nums[leftBegin] == target)
		{
			result[1] = leftBegin;
		}
		else
		{
			result[1] = leftBegin-1;
		}

		return result;
	}

	

};



//int main()
//{
//	Solution so;
//	std::vector<int> nums = {1,2,2};
//
//	std::vector<int> result = so.searchRange(nums,2);
//
//	return 0;
//
//}


