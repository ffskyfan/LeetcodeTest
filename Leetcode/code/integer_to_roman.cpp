//--------------------------------------------------------------------
//12. Integer to Roman
//Medium
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
//Given an integer, convert it to a roman numeral.Input is guaranteed to be within the range from 1 to 3999.
//
//Example 1:
//
//Input: 3
//	Output : "III"
//	Example 2 :
//
//	Input : 4
//	Output : "IV"
//	Example 3 :
//
//	Input : 9
//	Output : "IX"
//	Example 4 :
//
//	Input : 58
//	Output : "LVIII"
//	Explanation : L = 50, V = 5, III = 3.
//	Example 5 :
//
//	Input : 1994
//	Output : "MCMXCIV"
//	Explanation : M = 1000, CM = 900, XC = 90 and IV = 4.

//--------------------------------------------------------------------

#include <string>
#include <vector>




class Solution {
	std::string UnitGetRoman(int idx, int num)
	{
		char a = '1';
		char b = '1';
		char c = '1';
		switch(idx)
		{
		case 0:
			a = 'I'; b = 'V'; c = 'X';
			break;
		case 1:
			a = 'X'; b = 'L'; c = 'C';
			break;
		case 2:
			a = 'C'; b = 'D'; c = 'M';
			break;
		case 3:
			a = 'M'; 
			break;
		default:
			return "";
		}

		std::string result = "";

		if(num == 0) return result;
		if(num <= 3)
		{
			for(int i = 0; i < num; i++)
			{
				result.push_back(a);
			}
		}
		else if(num == 4)
		{
			result.push_back(a);
			result.push_back(b);
		}
		else if(num <= 8)
		{
			result.push_back(b);
			for(int i = 5; i < num; i++)
			{
				result.push_back(a);
			}
		}
		else
		{
			result.push_back(a);
			result.push_back(c);
		}

		return result;
	}


public:
	std::string intToRoman(int num) {

		std::string result;
		for(int i = 0; i < 4; i++)
		{
			int a = num % 10;
			std::string part = UnitGetRoman(i, a);

			result = part + result;

			num = num / 10;
			if(num == 0) break;
		}

		return result;
	}

};



//int main()
//{
//	Solution so;
//
//	std::string result = so.intToRoman(1994);
//
//	return 0;
//
//}


