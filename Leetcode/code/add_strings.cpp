//--------------------------------------------------------------------
//415. Add Strings
//Easy
//Given two non - negative integers num1 and num2 represented as string, return the sum of num1 and num2.
//
//Note:
//
//The length of both num1 and num2 is < 5100.
//	Both num1 and num2 contains only digits 0 - 9.
//	Both num1 and num2 does not contain any leading zero.
//	You must not use any built - in BigInteger library or convert the inputs to integer directly.
//--------------------------------------------------------------------

#include <string>
#include <vector>



using namespace std;

class Solution {


public:
	string addStrings(string num1, string num2) {
		char carry = 0;
		int num1Count = static_cast<int>(num1.size());
		int num2Count = static_cast<int>(num2.size());
		string result;
		for(int i = num1Count - 1, j = num2Count - 1; i >= 0 || j >= 0; i--, j--)
		{
			char num1Char = '0';
			if(i >= 0) num1Char = num1[i];

			char num2Char = '0';
			if(j >= 0) num2Char = num2[j];

			char x = (num1Char-'0') + (num2Char-'0') + carry;
			char unit = x % 10;
			carry = x / 10;

			result.push_back(unit);
		}
		if(carry!=0) result.push_back(carry);

		int resultCount = static_cast<int>(result.size());
		char temp = 0;
		for(int i = 0,j=resultCount-1; i <= j; i++,j--)
		{
			temp = result[i]+'0';
			result[i] = result[j]+'0';
			result[j] = temp;
		}

		return result;
	}

};



//int main()
//{
//	Solution so;
//	
//
//	std::string result = so.addStrings("9","99");
//
//	return 0;
//
//}


