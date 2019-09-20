//--------------------------------------------------------------------
//28. Implement strStr()
//Easy
//
//Implement strStr().
//
//Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
//
//Example 1:
//Input: haystack = "hello", needle = "ll"
//Output : 2
//
//Example 2 :
//Input : haystack = "aaaaa", needle = "bba"
//Output : -1
//Clarification :
//
//What should we return when needle is an empty string ? This is a great question to ask during an interview.
//
//For the purpose of this problem, we will return 0 when needle is an empty string.This is consistent to C's strstr() and Java's indexOf().

//--------------------------------------------------------------------

#include <string>
#include <vector>




class Solution {

public:
	int strStr(std::string haystack, std::string needle) {
		size_t needleSize = needle.length();
		if(needleSize==0) return 0;
		size_t haystackSize = haystack.length();
		if(haystackSize==0) return -1;
		for(size_t i = 0; i < haystackSize; i++)
		{
			if(haystackSize - i < needleSize) return -1;

			size_t matchCount = 0;
			for(size_t j = 0, tempI = i; j < needleSize && tempI < haystackSize; j++, tempI++)
			{
				if(haystack[tempI] == needle[j])
				{
					matchCount++;
					continue;
				}
				else
					break;
			}

			if(matchCount == needleSize) return (int)i;
		}

		return -1;

	}

	

};



int main()
{
	Solution so;

	int result = so.strStr("hello","ll");

	return 0;

}


