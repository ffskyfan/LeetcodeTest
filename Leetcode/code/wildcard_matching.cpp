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
#include <vector>

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
		string begin;
		string end;
		vector<string*> freeParts;

		size_t pLength = p.size();
		size_t i = 0;
		for(; i < pLength ; i++)
		{
			char ch = p[i];
			if(p[i] != '*')
			{
				begin.push_back(ch);
			}
			else 
				break;
		}

		int j = static_cast<int>(pLength)-1;
		for(; j >= 0 && j > i; j--)
		{
			char ch = p[j];
			if(p[j] != '*')
			{
				end.push_back(ch);
			}
			else 
				break;
		}

		string* str = new string;
		for(; i < j; i++)
		{
			char ch = p[i];
			if(p[i] != '*')
			{
				str->push_back(ch);
			}
			else
			{
				if(str->empty()) continue;
				freeParts.push_back(str);

				str = new string;
			}
		}
		if(!str->empty()) freeParts.push_back(str);


		size_t sLength = s.size();

		int m = 0;
		if(!begin.empty())
		{
			size_t matchLength =  begin.size();
			for(; m < sLength && m < matchLength; m++)
			{
				char beginChar = begin[m];
				if(beginChar=='?') continue;
				if(beginChar == s[m]) continue;
				
				return false;
			}

			if(m<matchLength) return false;
		}

		int n = sLength - 1;
		if(!end.empty())
		{
			size_t matchLength =  end.size();
			int matchEndPoint = sLength-matchLength;
			for(size_t i = 0; i < matchLength && n >= 0 && n >= matchEndPoint && n >= m; i++,n--)
			{
				char endChar = end[i];
				if(endChar=='?') continue;
				if(endChar == s[n]) continue;
				
				return false;
			}

			if(n>=matchEndPoint && n<m) return false;
		}

		if(!freeParts.empty())
		{
			for(string* part : freeParts)
			{
				if(m >= n) return false;

				int partLength = static_cast<int>(part->size());
				for(int i = 0; i < partLength; i++)
				{
					if(m > n) return false;
					if(partLength-i < m-n) return false;

					char ch = part->at(i);
					if(s[m] == ch || ch=='?')
					{
						m++;
					}
					else
					{
						m = m - i + 1;
						i = -1;
					}
				}
			}

		}

		if(m<=n) return false;

		return true;
	}
};


int main()
{
	Solution so;
	bool result = so.isMatch("aa", "a");

	return 0;

}