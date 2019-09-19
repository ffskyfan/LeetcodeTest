//--------------------------------------------------------------------
//13. Roman to Integer
//Roman numerals are represented by seven different symbols : I, V, X, L, C, D and M.
//
//Symbol       Value
//I             1
//V             5
//X             10
//L             50
//C             100
//D             500
//M             1000
//For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.
//
//Roman numerals are usually written largest to smallest from left to right.However, the numeral for four is not IIII.Instead, the number four is written as IV.Because the one is before the five we subtract it making four.The same principle applies to the number nine, which is written as IX.There are six instances where subtraction is used :
//
//I can be placed before V(5) and X(10) to make 4 and 9.
//X can be placed before L(50) and C(100) to make 40 and 90.
//C can be placed before D(500) and M(1000) to make 400 and 900.
//Given a roman numeral, convert it to an integer.Input is guaranteed to be within the range from 1 to 3999.
//
//Example 1:
//
//Input: "III"
//	Output : 3
//	Example 2 :
//
//	Input : "IV"
//	Output : 4
//	Example 3 :
//
//	Input : "IX"
//	Output : 9
//	Example 4 :
//
//	Input : "LVIII"
//	Output : 58
//	Explanation : L = 50, V = 5, III = 3.
//	Example 5 :
//
//	Input : "MCMXCIV"
//	Output : 1994
//	Explanation : M = 1000, CM = 900, XC = 90 and IV = 4.
//--------------------------------------------------------------------

#include <string>




class Solution {



public:
	int romanToInt(std::string s) {
		int result = 0;
		int tempValue = 0;
		for (char c : s)
		{
			switch (c)
			{
			case 'I':
				if (tempValue != 0) { result += tempValue; }
				tempValue = 1;
				break;
			case 'V':
				if (tempValue != 0)
				{
					if (tempValue == 1) { result += 5 - 1; }
					else { result += tempValue + 5; }
					tempValue = 0;
				}
				else
				{
					result += 5;
				}
				break;
			case 'X':
				if (tempValue != 0)
				{
					if (tempValue == 1) { result += 10 - 1; tempValue=0;  }
					else { result += tempValue; tempValue=10;}
				}
				else
				{
					tempValue = 10;
				}
				break;
			case 'L':
				if (tempValue != 0)
				{
					if (tempValue == 10) { result += 50 - 10;  }
					else { result += tempValue + 50; }
					tempValue = 0;
				}
				else
				{
					result += 50;
				}
				break;
			case 'C':
				if (tempValue != 0)
				{
					if(tempValue == 10) { result += 100 - 10;  tempValue = 0; }
					else { result += tempValue; tempValue = 100;}
				}
				else
				{
					tempValue = 100;
				}
				break;
			case 'D':
				if (tempValue != 0)
				{
					if (tempValue == 100) { result += 500 - 100;  }
					else { result += tempValue + 500; }
					tempValue = 0;
				}
				else
				{
					result += 500;
				}
				break;
			case 'M':
				if (tempValue != 0)
				{
					if (tempValue == 100) { result += 1000 - 100;  }
					else { result += tempValue+1000; }
					tempValue = 0;
				}
				else
				{
					result += 1000;
				}
				break;
			default:
				break;


			}

		}

		result += tempValue;
		return result;
	}

	

};



int main()
{
	Solution so;
	int result = so.romanToInt("MCMXCIV");

	return 0;

}


