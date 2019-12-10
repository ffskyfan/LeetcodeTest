/*-----------------------------------------------------------------
//22. Generate Parentheses
//Medium
//Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
//
//For example, given n = 3, a solution set is:
//
//[
//  "((()))",
//  "(()())",
//  "(())()",
//  "()(())",
//  "()()()"
------------------------------------------------------------------*/

#include <vector>
#include <set>

using namespace std;

class Solution {


	string generatePerfectParenthesis(int n) 
	{
		string result;
		result.reserve(128);
		
		for(int i = 0; i < n; i++) result.push_back('(');
		for(int i = 0; i < n; i++) result.push_back(')');

		return result;
	}



	 void generateParenthesis(int n, std::vector<string>& result) 
	 {
		for(int i = 1; i <= n; i++)
		{
			int wantSub = n-i;
			generateParenthesis(wantSub,  result);
		}


	 }


public:
	std::vector<string> generateParenthesis(int n) {
		std::vector<string> result;
		if(n<=0) return result;

		generateParenthesis(n, result);

		return result;
	}
};


int main()
{
	Solution so;
	vector<string> result = so.generateParenthesis(3);
	//string result = so.convert("PAYPALISHIRING", 3);

	return 0;

}