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

		if(target < candidates[0]) return resultEndIdx;

		bool haveNewContent = false;
		int closestIdx = searchClosestTarget(candidates, begin, end, target);
		for(int i = closestIdx; i >= 0; i--)
		{
			int nextTarget = target - candidates[i];

			int resultEndIdxInThisLoop = static_cast<int>(result.size() - 1);
			int pushBeginIdx = combinationSum(candidates, begin, i, nextTarget, result);
			if(pushBeginIdx == resultEndIdxInThisLoop)  continue;

			haveNewContent = true;
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


//解法：先让数列从小到大排列，从数列里找到最接近目标数的那个数 closestTar，然后从closestTar开始，
//从大到小依次次用目标数减去数列里小于目标值的数，
//每次减去后会得到一个余数，这个数作为下一层级的目标数继续用上面的方法求解。这样递归下去。
//随着递归一层层深入，每次减出0来了，就得到一个完整的组合数。


//int main()
//{
//	vector<int> candidates = { 2,3,6,7,10 };
//
//	Solution so;
//	vector<vector<int>> result = so.combinationSum(candidates, 10);
//
//	return 0;
//
//}


