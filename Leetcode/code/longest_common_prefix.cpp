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
		if(strs.empty()) return "";

		int minLength = static_cast<int>(strs[0].length());
		for(const std::string& str : strs)
		{
			int length = static_cast<int>(str.length());
			if(length < minLength) minLength = length;
		}

		if(minLength==0) return "";

		std::string prefix("");

		for(int i = 0; i < minLength; i++)
		{
			bool isMatch = true;
			char tempCh = 0;
			for(const std::string& str : strs)
			{
				if(tempCh == 0)
				{
					tempCh = str[i];
					continue;
				}

				if(tempCh == str[i])
				{
					continue;
				}
				else
				{
					isMatch = false;
					break;
				}
			}

			if(isMatch==true)
				prefix.push_back(tempCh);
			else
				break;
		}

		return prefix;

	}

};



//int main()
//{
//	Solution so;
//	//std::vector<std::string> strs = { "flow","flower","flaw" };
//	std::vector<std::string> strs = { "","b" };
//	
//
//	std::string result = so.longestCommonPrefix(strs);
//
//	return 0;
//
//}


