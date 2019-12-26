/*-----------------------------------------------------------------
//56. Merge Intervals
//Medium
//Given a collection of intervals, merge all overlapping intervals.
//
//Example 1:
//
//Input: [[1,3],[2,6],[8,10],[15,18]]
//Output: [[1,6],[8,10],[15,18]]
//Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
//Example 2:
//
//Input: [[1,4],[4,5]]
//Output: [[1,5]]
//Explanation: Intervals [1,4] and [4,5] are considered overlapping.
//NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
------------------------------------------------------------------*/

#include <vector>

using namespace std;


class Solution {

	bool merge(vector<int>& a, vector<int>& b)
	{
		if( (a[0] >= b[0] && a[0] <= b[1]) ||
			(a[1] >= b[0] && a[1] <= b[1]) ||
			(b[0] >= a[0] && b[0] <= a[1]) ||
			(b[1] >= a[0] && b[1] <= a[1])
		)
		{
			a[0] = a[0]<b[0]?a[0]:b[0];
			a[1] = a[1]>b[1]?a[1]:b[1];
			b.clear();
			return true;
		}

		return false;
	}



public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		int count = static_cast<int>(intervals.size());
		if(count<=1) return intervals;

		for(int i = 0; i < count; i++)
		{
			vector<int>& intervalA = intervals[i];
			if(intervalA.empty()) continue;

			for(int j = count-1; j >= 0; j--)
			{
				if(i==j) continue;
				vector<int>& intervalB = intervals[j];
				if(intervalB.empty()) continue;
				merge(intervalA, intervalB);
			}
		}

		vector<vector<int>> result;
		for(auto interval : intervals)
		{
			if(interval.empty()) continue;
			result.push_back(interval);
		}

		return result;
	}

};


//int main()
//{
//	Solution so;
//
//	std::vector<int> a = {4,5,6,0,0,0};
//	std::vector<int> b = {1,2,3};
//
//	so.merge(a,3, b,3);
//
//	return 0;
//
//}