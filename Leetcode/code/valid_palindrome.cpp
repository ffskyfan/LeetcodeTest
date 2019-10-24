//--------------------------------------------------------------------
//125. Valid Palindrome
//Easy
//Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
//
//Note: For the purpose of this problem, we define empty string as valid palindrome.
//
//	Example 1 :
//
//	Input : "A man, a plan, a canal: Panama"
//	Output : true
//	Example 2 :
//
//	Input : "race a car"
//	Output : false
//--------------------------------------------------------------------

#include <string>
#include <vector>




class Solution {

	enum class FindDirection
	{
		ToRight,
		ToLeft,

	};

	char FindValidChar(const std::string& s, FindDirection direction, int& i)
	{
		size_t count = s.size();
		for(; i < count&&i>=0; )
		{
			char c = s[i];
			if((c>='A'&&c<='Z') || (c>='a'&&c<='z')||(c>='0'&&c<='9'))
			{
				return c;
			}
			else
			{
				if(direction == FindDirection::ToRight)
					i++;
				else
					i--;
			}
		}

		return 0;
	}


public:
	bool isPalindrome(std::string s) {
		int count = static_cast<int>(s.size());
		if(count==0) return true;

		for(int i = 0, j = count - 1; i<count && j>0&&i<j; i++, j--)
		{
			char leftChar = FindValidChar(s, FindDirection::ToRight , i);
			char rightChar = FindValidChar(s, FindDirection::ToLeft , j);
			if(leftChar >= 'A'&&leftChar <= 'Z') leftChar += 32;
			if(rightChar >= 'A'&&rightChar <= 'Z') rightChar += 32;
			if(leftChar!=rightChar)  return false;
		}

		return true;
	}

};



//int main()
//{
//	Solution so;
//
//	//bool result = so.isPalindrome("A man, a plan, a canal: Panama");
//	//bool result = so.isPalindrome("race a car");
//	bool result = so.isPalindrome("0P");
//
//	return 0;
//
//}


