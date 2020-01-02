/*-----------------------------------------------------------------
//49. Group Anagrams
//Medium
//Given an array of strings, group anagrams together.
//
//Example:
//
//Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
//Output:
//[
//  ["ate","eat","tea"],
//  ["nat","tan"],
//  ["bat"]
//]
//Note:
//
//All inputs will be in lowercase.
//The order of your output does not matter.
------------------------------------------------------------------*/

#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {


public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> result;
		unordered_map<string, int> strIdxMap;

		int count = static_cast<int>(strs.size());
		for(int i=0; i<count; i++)
		{
			string str = strs[i];
			std::sort(str.begin(), str.end());
			auto it = strIdxMap.find(str);
			if(it != strIdxMap.end())
			{
				int idx = it->second;
				result[idx].push_back(strs[i]);
			}
			else
			{
				int newIdx = static_cast<int>(result.size());
				strIdxMap.insert(std::make_pair(str, newIdx));
				vector<string> newVec;
				newVec.push_back(strs[i]);
				result.push_back(newVec);
			}
		}

		return result;

	}
};






//int main()
//{
//	Solution so;
//	vector<string> result = so.generateParenthesis(4);
//	//string result = so.convert("PAYPALISHIRING", 3);
//
//	return 0;
//
//}