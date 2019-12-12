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


	void generateParenthesis(int n, int globalRemainedLeftNum, int uncloseLeftNum, int currentIdx,std::vector<string>& result)
	{
		bool   needNewStr = false;
		string temp		  = result[currentIdx];

		//push left
		if(globalRemainedLeftNum - 1 >= 0)
		{
			//add(
			result[currentIdx].append("(");
			generateParenthesis(n, globalRemainedLeftNum-1, uncloseLeftNum+1, currentIdx, result);

			needNewStr = true;
		}

		//push right
		if(uncloseLeftNum > 0)
		{
			//add)
			if(needNewStr)
			{
				string newResStr = temp;
				newResStr.append(")");
				result.push_back(newResStr);
				generateParenthesis(n, globalRemainedLeftNum, uncloseLeftNum - 1, static_cast<int>(result.size()) - 1, result);
			}
			else
			{
				result[currentIdx].append(")");
				generateParenthesis(n, globalRemainedLeftNum, uncloseLeftNum - 1, currentIdx, result);
			}
		}
		
	}

public:
	std::vector<string> generateParenthesis(int n) {
		std::vector<string> result;
		if(n<=0) return result;

		result.push_back("");
		generateParenthesis(n, n, 0, 0, result);

		return result;
	}
};


//int main()
//{
//	Solution so;
//	vector<string> result = so.generateParenthesis(4);
//	//string result = so.convert("PAYPALISHIRING", 3);
//
//	return 0;
//
//}