//--------------------------------------------------------------------
//Given a string s, find the longest palindromic substring in s.You may assume that the maximum length of s is 1000.
//
//Example 1:
//
//Input: "babad"
//	Output : "bab"
//	Note : "aba" is also a valid answer.
//	Example 2 :
//
//	Input : "cbbd"
//	Output : "bb"
//--------------------------------------------------------------------

#include <string>

using namespace std;

class Solution {
public:
	void findPalindrome(string s, const int length, int& frontIdx, int& backIdx)
	{
		if(s[frontIdx] == s[backIdx])
		{
			frontIdx++;
			backIdx--;

			findPalindrome(s, length, frontIdx, backIdx);
		}
		else
		{
			frontIdx--;
			backIdx++;
		}
	}


	void findPalindrome(string s, const int length, int& frontIdx, int& backIdx, int& palindromeLength, int& palindromeBeginIdx, int& palindromeEndIdx)
	{
		bool isFindPalindrome = false;
		if(backIdx-frontIdx==2) isFindPalindrome = true;

		for(;frontIdx >= 0 && backIdx < length; frontIdx--, backIdx++)
		{
			if(s[frontIdx]==s[backIdx]) 
			{
				isFindPalindrome = true;
			}
			else
			{
				if(isFindPalindrome == true) break;
				return;
			}
		}
		frontIdx++;
		backIdx--;

		if(isFindPalindrome)
		{
			if((backIdx - frontIdx) > palindromeLength)
			{
				palindromeBeginIdx = frontIdx;
				palindromeEndIdx = backIdx;
				palindromeLength = backIdx - frontIdx;
			}
		}
	}


	string longestPalindrome(string s) {

		int count = static_cast<int>(s.size());
		if(count<=1) return s;

		int idx = (count / 2) - 1;

		int palindromeLength	= 0;
		int palindromeBeginIdx	= 0;
		int palindromeEndIdx	= 0;

		for(int i = idx; i >= 0; i--)
		{
			int frontIdx =i;
			int endIdx =i+1;
			findPalindrome(s, count, frontIdx, endIdx, palindromeLength, palindromeBeginIdx, palindromeEndIdx);

			frontIdx =i;
			endIdx =i+2;
			findPalindrome(s, count, frontIdx, endIdx, palindromeLength, palindromeBeginIdx, palindromeEndIdx);
		}

		for(int j = idx - 1; j < count-1; j++)
		{
			int frontIdx =j;
			int endIdx =j+1;
			findPalindrome(s, count, frontIdx, endIdx, palindromeLength, palindromeBeginIdx, palindromeEndIdx);

			frontIdx =j;
			endIdx =j+2;
			findPalindrome(s, count, frontIdx, endIdx, palindromeLength, palindromeBeginIdx, palindromeEndIdx);

		}

		if(palindromeLength==0) return "";

		return s.substr(palindromeBeginIdx, palindromeEndIdx-palindromeBeginIdx+1);
	}
};

int main()
{
	string a("ac");

	Solution so;
	string result = so.longestPalindrome(a);

	return 0;

}


