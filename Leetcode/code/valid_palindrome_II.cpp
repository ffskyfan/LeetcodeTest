//--------------------------------------------------------------------
//680. Valid Palindrome II
//Easy
//Given a non - empty string s, you may delete at most one character.Judge whether you can make it a palindrome.
//
//Example 1:
//Input: "aba"
//	Output : True
//	Example 2 :
//	Input : "abca"
//	Output : True
//	Explanation : You could delete the character 'c'.
//	Note :
//	The string will only contain lowercase characters a - z.The maximum length of the string is 50000.
//--------------------------------------------------------------------

#include <string>
#include <vector>




class Solution {


	bool validPalindrome(const std::string& s, int begin, int end, bool isSkiped) 
	{
		for(int i = begin, j = end; i <= end && j > 0 && i < j; i++, j--)
		{
			char leftChar = s[i];
			char rightChar = s[j];
			if(leftChar==rightChar)  continue;

			if(isSkiped == true) return false;

			char nextLeftChar = s[i+1];
			char nextRightChar = s[j-1];

			if(nextLeftChar == rightChar)
			{
				bool isValid = validPalindrome(s, i+1, j, true);
				if(isValid) return true;
			}

			if(nextRightChar == leftChar)
			{
				bool isValid = validPalindrome(s, i, j-1, true);
				if(isValid) return true;
			}

			return false;
		}

		return true;

	}


public:
	bool validPalindrome(std::string s) {
		int count = static_cast<int>(s.size());
		if(count==0) return true;

		return validPalindrome(s, 0, count-1, false);
	}

};



//int main()
//{
//	Solution so;
//
//	//bool result = so.isPalindrome("A man, a plan, a canal: Panama");
//	//bool result = so.isPalindrome("race a car");
//	bool result = so.validPalindrome("aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga");
//
//	return 0;
//
//}


