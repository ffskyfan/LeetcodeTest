//--------------------------------------------------------------------
//58. Length of Last Word
//Easy
//
//Given a string s consists of upper / lower - case alphabets and empty space characters ' ', return the length of last word in the string.
//
//If the last word does not exist, return 0.
//
//Note: A word is defined as a character sequence consists of non - space characters only.
//
//	Example :
//
//	Input : "Hello World"
//	Output : 5
//--------------------------------------------------------------------

#include <string>
#include <vector>




class Solution {



public:
	int lengthOfLastWord(std::string s) {
		int length = static_cast<int>(s.length());
		int lastWordLength = 0;
		bool haveLastWord = false;
		for(int i = length-1; i >= 0; i--)
		{
			if(s[i]==' ') 
			{
				if(lastWordLength != 0)
				{
					return lastWordLength;
				}
			}
			else
			{
				lastWordLength++;
			}
		}

		return lastWordLength;
	}

};



//int main()
//{
//	Solution so;
//	std::string str("inivn aidfn idan aidfn");
//	
//
//	int result = so.lengthOfLastWord(str);
//
//	return 0;
//
//}


