//--------------------------------------------------------------------
//205. Isomorphic Strings
//Easy
//Given two strings s and t, determine if they are isomorphic.
//
//Two strings are isomorphic if the characters in s can be replaced to get t.
//
//All occurrences of a character must be replaced with another character while preserving the order of characters.No two characters may map to the same character but a character may map to itself.
//
//Example 1:
//
//Input: s = "egg", t = "add"
//	Output : true
//	Example 2 :
//
//	Input : s = "foo", t = "bar"
//	Output : false
//	Example 3 :
//
//	Input : s = "paper", t = "title"
//	Output : true
//	Note :
//	You may assume both s and t have the same length.
//--------------------------------------------------------------------

#include <string>
#include <map>





class Solution {

public:
	bool isIsomorphic(std::string s, std::string t) {
		std::map<char,char> isoSMap;
		std::map<char,char> isoTMap;

		int count = static_cast<int>(s.size());
		for(int i = 0; i < count; i++)
		{
			auto sIt = isoSMap.find(s[i]);
			auto tIt = isoTMap.find(t[i]);
			if(sIt != isoSMap.end())
			{
				if(sIt->second != t[i]) return false;
			}
			else if(tIt != isoTMap.end())
			{
				if(tIt->second != s[i]) return false;
			}
			else
			{
				isoSMap.insert(std::make_pair(s[i], t[i]));
				isoTMap.insert(std::make_pair(t[i], s[i]));
			}
		}

		return true;
	}

};



//int main()
//{
//	Solution so;
//
//	bool result = so.isIsomorphic("ab","aa");
//
//	return 0;
//
//}


