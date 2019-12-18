//--------------------------------------------------------------------
//39. Combination Sum
//Medium
//Given a set of candidate numbers(candidates) (without duplicates) and a target number(target), find all unique combinations in candidates where the candidate numbers sums to target.
//
//The same repeated number may be chosen from candidates unlimited number of times.
//
//Note:
//
//All numbers(including target) will be positive integers.
//The solution set must not contain duplicate combinations.
//Example 1 :
//
//	Input : candidates = [2, 3, 6, 7], target = 7,
//	A solution set is :
//[
//	[7],
//	[2, 2, 3]
//]
//Example 2 :
//
//	Input : candidates = [2, 3, 5], target = 8,
//	A solution set is :
//[
//	[2, 2, 2, 2],
//	[2, 3, 3],
//	[3, 5]
//]
//--------------------------------------------------------------------

#include <vector>
#include <algorithm>

using namespace std;

class Solution {

	int searchClosestTarget(vector<int>& candidates,int begin, int end ,int target)
	{
		int mid = 0;
		for(; begin <= end;)
		{
			mid = begin + ((end - begin) / 2);
			if(candidates[mid] == target) break;

			if(target > candidates[mid]) { begin = mid + 1; }
			else { end = mid - 1; }
		}

		return mid;
	}


	vector<int> combinationSum(vector<int>& candidates, int begin, int end, int target, vector<vector<int>>& result)
	{
		if(target==0) return;

		int closestIdx = searchClosestTarget(candidates,begin, end ,target);
;
		for(int i = closestIdx; i >= 0; i--)
		{
			int nextTarget = target - candidates[i];

			vector<int> newResult = combinationSum(candidates, begin, i, nextTarget, result);
		}

	}


public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

		vector<vector<int>> result;
		std::sort(candidates.begin(), candidates.end());

		int begin = 0;
		int end = static_cast<int>(candidates.size())-1;
		int closestIdx = searchClosestTarget(candidates,begin, end ,target);
;
		for(int i = closestIdx; i >= 0; i--)
		{
			int nextTarget = target - candidates[i];
			if(nextTarget==0) continue;
			



		}




	}
};


//
//


//int main()
//{
//
//	Solution so;
//	int result = so.countPrimes(10);
//
//	return 0;
//
//}


