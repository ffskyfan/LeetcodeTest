/*-----------------------------------------------------------------
17. Letter Combinations of a Phone Number
Medium
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.



Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
------------------------------------------------------------------*/

#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {

	char getBegin(char val)
	{
		if(val < '8' )
		{
			return 'a' + ((val-'2') * 3);
		}
		else 
		{
			return 'a' + ((val - '2') * 3) + 1;
		}
	}

	int getCount(char val)
	{
		if(val < '7' || val == '8')
		{
			return 3;
		}
		else
		{
			return 4;
		}

	}


public:
	vector<string> letterCombinations(string digits) {

		vector<string> a;
		vector<string> b;

		vector<string>& refA = a;
		vector<string>& refB = b;

		size_t len = digits.length();
		for(size_t i = 0; i < len; i++)
		{

			char first = digits[i];
			char ch = getBegin(first);
			int count = getCount(first);

			for(char i = 0; i < count; i++)
			{
				char tempCh = ch + i;

				if(refA.empty())
				{
					string x;
					x.push_back(tempCh);
					refB.push_back(x);
				}
				else
				{
					for(string& x : refA)
					{
						x.push_back(tempCh);
						refB.push_back(x);
						x.pop_back();
					}
				}
			}

			vector<string>& refTemp = refA;
			refA = refB;
			refB = refTemp;
			refB.clear();
		}

		return refA;
	}
};


//int main()
//{
//	Solution so;
//	vector<string> result = so.letterCombinations("2");
//	return 0;
//
//}