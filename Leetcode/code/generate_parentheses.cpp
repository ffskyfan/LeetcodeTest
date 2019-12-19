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

/* 解法解析：

递归过程记录几个数 1. 所有(左括号的数量 2.没有闭合的(左括号的数量

后面的步骤

生成函数
1. 如果左括号数量不为零，塞一个左括号,(先塞左括号是因为无论如何，先塞都不会错) 递归生成函数
2. 如果没有闭合的左括号数量不为零，那就塞个右括号 递归生成函数






			   





*/








//int main()
//{
//	Solution so;
//	vector<string> result = so.generateParenthesis(4);
//	//string result = so.convert("PAYPALISHIRING", 3);
//
//	return 0;
//
//}