//--------------------------------------------------------------------
//67. Add Binary
//Easy
//Given two binary strings, return their sum(also a binary string).
//
//The input strings are both non - empty and contains only characters 1 or 0.
//
//Example 1:
//
//Input: a = "11", b = "1"
//	Output : "100"
//	Example 2 :
//
//	Input : a = "1010", b = "1011"
//	Output : "10101"
//--------------------------------------------------------------------

#include <string>
#include <vector>




class Solution {


public:
	std::string addBinary(std::string a, std::string b) {
		int aLength = static_cast<int>(a.length());
		int bLength = static_cast<int>(b.length());

		if(aLength==0) return b;
		if(bLength==0) return a;

		std::string result;
		
		char carry = 0;
		for(int i = aLength-1, j = bLength-1; i >= 0 || j >= 0; i--, j--)
		{
			char aCh = i>=0?a[i]:0;
			char bCh = j>=0?b[j]:0;

			if(carry == 0)
			{
				if(aCh == '1'&&bCh == '1')
				{
					result.push_back('0');
					carry=1;
				}
				else if(aCh == '1' || bCh == '1')
				{
					result.push_back('1');
				}
				else
				{
					result.push_back('0');
				}
			}
			else
			{
				if(aCh == '1'&&bCh == '1')
				{
					result.push_back('1');
					carry=1;
				}
				else if(aCh == '1' || bCh == '1')
				{
					result.push_back('0');
					carry=1;
				}
				else
				{
					result.push_back('1');
					carry=0;
				}
			}
		}

		if(carry==1)
			result.push_back('1');

		std::reverse(result.begin(), result.end());

		return result;

	}

};



//int main()
//{
//	Solution so;
//	std::string a("101101");
//	std::string b("1");
//	
//
//	std::string result = so.addBinary(a,b);
//
//	return 0;
//
//}


