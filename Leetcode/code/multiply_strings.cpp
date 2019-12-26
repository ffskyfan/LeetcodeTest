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

		string result;
		int carry = 0;
		for(int num1Idx = num1Count - 1; num1Idx >= 0; num1Idx--)
		{
			int beginPlusPos = num1Count - num1Idx - 1;
			int carryThisTurn = carry;
			string loopResult;
			for(int num2Idx = num2Count - 1; num2Idx >= 0; num2Idx--)
			{
				int x = ((num1[num1Idx] - '0')*(num2[num2Idx] - '0')) + carry;
				int unit = x%10;
				carry = x/10;
				loopResult.push_back(unit);
			}

			loopResult.push_back(carry);

			carry = 0;
			int resultCount = static_cast<int>(result.size());
			int loopResultCount = static_cast<int>(loopResult.size());
			for(int plusPos = beginPlusPos, i = 0; i < loopResultCount; i++, plusPos++)
			{
				int resultPosNumber = 0;
				if(plusPos<resultCount) resultPosNumber = result[plusPos];

				int y = resultPosNumber+loopResult[i]+carry;
				int unit = y%10;
				carry = y/10;

				if(plusPos < resultCount) result[plusPos] = unit;
				else result.push_back(unit);
			}

			if(carry!=0) result.push_back(carry);
		}

		int resultCount = static_cast<int>(result.size());
		for(int i = resultCount - 1; i > 0; i--) 
		{
			if(result[i]==0) result.pop_back();
			else break;
		}

		resultCount = static_cast<int>(result.size());
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
//	MinStack so;
//	string result = so.multiply("8887","0");
//
//	return 0;
//
//}


