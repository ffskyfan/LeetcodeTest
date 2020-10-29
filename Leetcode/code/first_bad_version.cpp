//--------------------------------------------------------------------
//278. First Bad Version
//Easy
//You are a product manager and currently leading a team to develop a new product.Unfortunately, the latest version of your product fails the quality check.Since each version is developed based on the previous version, all the versions after a bad version are also bad.
//
//Suppose you have n versions[1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.
//
//You are given an API bool isBadVersion(version) which returns whether version is bad.Implement a function to find the first bad version.You should minimize the number of calls to the API.
//
//
//
//Example 1:
//
//Input: n = 5, bad = 4
//Output : 4
//Explanation :
//	call isBadVersion(3) -> false
//	call isBadVersion(5) -> true
//	call isBadVersion(4) -> true
//	Then 4 is the first bad version.
//	Example 2 :
//
//	Input : n = 1, bad = 1
//	Output : 1
//
//
//	Constraints :
//
//	1 <= bad <= n <= 231 - 1
//--------------------------------------------------------------------

#include <string>
#include <vector>


using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
bool isBadVersion(int version)
{
	return true;
}

class Solution {



public:
	int firstBadVersion(int n) {


		int begin = 1;
		int end = n;
		for(;begin < end;)
		{
			int mid = begin + ((end - begin) / 2);
			if(isBadVersion(mid) == true)
			{
				if(mid==1) 
				{ 
					end=mid;
					break;
				}
				end = mid-1;
			}
			else
			{
				begin = mid+1;
			}
		}

		if(isBadVersion(end) == true)
		{
			return end;
		}
		else
		{
			return end + 1;
		}


	}

	

};

//简单的二分法，因为坏掉的版本一定在数列的右边，比如1,2,3,4,5,6,6,6,6,6,6,6。这样只要与n做比较就行了
//等于n就说明右边全是n，往左找就行了，如果不等于n，那么说明右边还有不是n的数，往右找。如此循环就找到最早的那个n了。


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


