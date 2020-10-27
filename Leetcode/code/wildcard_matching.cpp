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

public:
	bool isMatch(string s, string p) {
		string begin;
		string end;
		vector<string*> freeParts;

		size_t sLength = s.size();
		size_t pLength = p.size();
		if(pLength == 0)
		{
			if(sLength == 0) return true;
			return false;
		}
		if(pLength == 1 && p[0] == '*') return true;

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

		bool isHaveFreeSearch = false;
		string* str = new string;
		for(; i <= j; i++)
		{
			char ch = p[i];
			if(p[i] != '*')
			{
				str->push_back(ch);
			}
			else
			{
				isHaveFreeSearch = true;
				if(str->empty()) continue;
				freeParts.push_back(str);

				str = new string;
			}
		}
		if(!str->empty()) freeParts.push_back(str);



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
				if(m > n) return false;

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
		else
		{
			if(isHaveFreeSearch == false)
			{
				if(m <= n) return false;
			}
		}


		return true;
	}
};

//�ⷨ��p�ֳ�3���֣���*��Ϊ�ָ������ַ�����ͷbegin���ַ���βend����������ƥ���freeparts(�Ǹ��ַ���������)��
//����a*b*c*d����ôa����begin��d����end��freeparts����һ���ַ���b��c
//���begin���ڣ���ôs�Ŀ�ͷ������ȫƥ��begin�����end���ڣ�s��β��������ȫƥ��end
//֮�����freepart���ڣ���ô��ȥbegin��endƥ����ò��֣�һ��һ��������û��freepart��Ĳ��֣�ֱ����s����ַ������Ĺ⣬�����ƥ�䵽�ˣ���ȷ��ƥ��ɹ������û�У���ʧ��


//int main()
//{
//	Solution so;
//	bool result = so.isMatch("c", "*?*");
//
//	return 0;
//
//}