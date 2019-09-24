//--------------------------------------------------------------------
//14. Longest Common Prefix
//Easy
//
//Write a function to find the longest common prefix string amongst an array of strings.
//
//If there is no common prefix, return an empty string "".
//
//Example 1:
//
//Input: ["flower", "flow", "flight"]
//	Output : "fl"
//	Example 2 :
//
//	Input : ["dog", "racecar", "car"]
//	Output : ""
//	Explanation : There is no common prefix among the input strings.
//	Note :
//
//	All given inputs are in lowercase letters a - z.
//--------------------------------------------------------------------

#include <string>
#include <vector>




class Solution {


public:
	std::string longestCommonPrefix(std::vector<std::string>& strs) {

	}

};



int main()
{
	Solution so;
	std::vector<std::string> strs = { "flow","flower","flaw" };
	

	std::string result = so.longestCommonPrefix(strs);

	return 0;

}


