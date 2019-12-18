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


	int combinationSum(vector<int>& candidates, int begin, int end, int target, vector<vector<int>>& result)
	{
		int resultEndIdx = static_cast<int>(result.size()-1);

		if(target == 0)
		{
			result.push_back(vector<int>());
			return resultEndIdx + 1;
		}

		bool haveNewContent = false;
		int closestIdx = searchClosestTarget(candidates,begin, end ,target);
		for(int i = closestIdx; i >= 0; i--)
		{
			int nextTarget = target - candidates[i];

			int pushBeginIdx = combinationSum(candidates, begin, i, nextTarget, result);
			if(pushBeginIdx > resultEndIdx) haveNewContent = true;
			int resultCount = static_cast<int>(result.size());
			for(int j = pushBeginIdx; j < resultCount; j++)
			{
				result[j].push_back(candidates[i]);
			}
		}

		if(haveNewContent) return resultEndIdx + 1;
		else return resultEndIdx;
	}


public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

		vector<vector<int>> result;
		std::sort(candidates.begin(), candidates.end());

		int begin = 0;
		int end = static_cast<int>(candidates.size())-1;

		combinationSum(candidates, begin, end, target, result);

		return result;
	}
};


//
//


int main()
{
	vector<int> candidates = { 2,3,6,7 };

	Solution so;
	vector<vector<int>> result = so.combinationSum(candidates, 10);

	return 0;

}


