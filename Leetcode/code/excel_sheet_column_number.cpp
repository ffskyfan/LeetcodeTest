//--------------------------------------------------------------------
//171. Excel Sheet Column Number
//Easy
//
//Given a column title as appear in an Excel sheet, return its corresponding column number.
//
//For example :
//
//A -> 1
//B -> 2
//C -> 3
//...
//Z -> 26
//AA -> 27
//AB -> 28
//...
//Example 1:
//
//Input: "A"
//	Output : 1
//	Example 2 :
//
//	Input : "AB"
//	Output : 28
//	Example 3 :
//
//	Input : "ZY"
//	Output : 701

//--------------------------------------------------------------------

#include <string>
#include <vector>
#include <list>




class Solution {


public:
	int titleToNumber(std::string s) {

		int result = 0;
		int length = static_cast<int>(s.length());
		for(int i = 0; i < length; i++)
		{
			int power = length-i-1;
			result += std::pow(26, power)* (s[i] - 'A' + 1);
		}

		return result;

	}


};



//int main()
//{
//	Solution so;
//
//	int result = so.titleToNumber("AB");
//
//	return 0;
//
//}


