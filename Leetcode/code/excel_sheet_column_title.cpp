//--------------------------------------------------------------------
//168. Excel Sheet Column Title
//Easy
//Given a positive integer, return its corresponding column title as appear in an Excel sheet.
//
//For example :
//
//1->A
//2->B
//3->C
//...
//26->Z
//27->AA
//28->AB
//...
//Example 1:
//
//Input: 1
//	Output : "A"
//	Example 2 :
//
//	Input : 28
//	Output : "AB"
//	Example 3 :
//
//	Input : 701
//	Output : "ZY"

//--------------------------------------------------------------------

#include <string>
#include <vector>
#include <list>




class Solution {


public:
	void convertToTitle(int n, std::string& result)
	{
		n = n-1;
		if(n<0) return;

		int a = n%26;
		result.insert(result.begin(), 'A' + a );

		int b = (n-a)/26;
		if(b > 0)
		{
			convertToTitle(b, result);
		}
	}

	std::string convertToTitle(int n) {
		if(n<0) return "";

		std::string result("");
		convertToTitle(n, result);

		return result;
	}


};



//int main()
//{
//	Solution so;
//
//	std::string result = so.convertToTitle(701);
//
//	return 0;
//
//}


