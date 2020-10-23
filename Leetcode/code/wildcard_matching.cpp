//-----------------------------------------------------------------------------------------------------------------
//44. Wildcard Matching
//Hard
//
//Given an input string(s) and a pattern(p), implement wildcard pattern matching with support for '?' and '*' where:
//
//'?' Matches any single character.
//'*' Matches any sequence of characters(including the empty sequence).
//The matching should cover the entire input string(not partial).
//
//
//Example 1:
//
//Input: s = "aa", p = "a"
//	Output : false
//	Explanation : "a" does not match the entire string "aa".
//	Example 2 :
//
//	Input : s = "aa", p = "*"
//	Output : true
//	Explanation : '*' matches any sequence.
//	Example 3 :
//
//	Input : s = "cb", p = "?a"
//	Output : false
//	Explanation : '?' matches 'c', but the second letter is 'a', which does not match 'b'.
//	Example 4 :
//
//	Input : s = "adceb", p = "*a*b"
//	Output : true
//	Explanation : The first '*' matches the empty sequence, while the second '*' matches the substring "dce".
//	Example 5 :
//
//	Input : s = "acdcb", p = "a*c?b"
//	Output : false
//
//
//Constraints :
//
//	0 <= s.length, p.length <= 2000
//	s contains only lowercase English letters.
//	p contains only lowercase English letters, '?' or '*'.
//-------------------------------------------------------------------------------------------------------------
#include <string>

using namespace std;

class Solution {

	bool match(string s, string p)
	{
		size_t sLength = s.size();
		size_t sPos = 0;

		size_t pLength = p.size();
		bool isFreeToSearch = false;
		size_t pFreeSearchIdx = 0;
		size_t sFreeSearchIdx = 0;
		for(size_t i = 0; i < pLength; i++)
		{
			if(sPos >= sLength) 
			{
				for(; i < pLength; i++) 
				{
					if(p[i] != '*') return false;
				}
				return true;
			}

			char ch = p[i];
			if(ch == '*')
			{
				isFreeToSearch = true;
				pFreeSearchIdx = i;
				sFreeSearchIdx = sPos;
			}
			else if(ch == '?')
			{
				sPos++;
			}
			else
			{
				if(s[sPos] == ch)
				{
					sPos++;
					continue;
				}
				else
				{
					if(isFreeToSearch == true)
					{
						i = pFreeSearchIdx;
						sFreeSearchIdx++;
						sPos = sFreeSearchIdx;
						continue;
					}
					else
					{
						return false;
					}
				}

			}

		}

		if(sPos < sLength)
		{
			if(p[pLength-1] == '*') return true;

			return false;
		}

		
		return true;

	}

public:
	bool isMatch(string s, string p) {

		string* parts;
		bool*	isFreeSearch;
		
		size_t pLength = p.size();
		for(size_t i = 0; i < pLength; i++)
		{

		}




		return false;
	}
};


int main()
{
	Solution so;
	bool result = so.isMatch("aaaa", "*a");

	return 0;

}