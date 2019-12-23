//--------------------------------------------------------------------
//43. Multiply Strings
//Medium
//Given two non - negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
//
//Example 1:
//
//Input: num1 = "2", num2 = "3"
//	Output : "6"
//	Example 2 :
//
//	Input : num1 = "123", num2 = "456"
//	Output : "56088"
//	Note :
//
//	The length of both num1 and num2 is < 110.
//	Both num1 and num2 contain only digits 0 - 9.
//	Both num1 and num2 do not contain any leading zero, except the number 0 itself.
//	You must not use any built - in BigInteger library or convert the inputs to integer directly.
//--------------------------------------------------------------------

#include <string>
#include <vector>

using namespace std;

class MinStack {

public:
	string multiply(string num1, string num2) {

		int num1Count = static_cast<int>(num1.size());
		int num2Count = static_cast<int>(num2.size());

		int carry = 0;
		for(int num1Idx = num1Count - 1; num1Idx >= 0; num1Idx--)
		{
			int carryThisTurn = carry;
			for(int num2Idx = num2Count - 1; num2Idx >= 0; num2Idx--)
			{
				int x = (num1[num1Idx]-'0')*(num2[num2Idx]-'0');
				int unit = x%10;
				carry = x/10;
			}




		}



	}
};





//int main()
//{
//	MinStack so;
//	so.push(2);
//	so.push(0);
//	so.push(3);
//	so.push(0);
//	so.pop();
//	so.pop();
//	so.pop();
//	so.pop();
//	
//
//	return 0;
//
//}


