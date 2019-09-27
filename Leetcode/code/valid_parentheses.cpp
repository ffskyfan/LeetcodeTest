//--------------------------------------------------------------------
//20. Valid Parentheses
//Easy
//
//Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//
//An input string is valid if:
//
//Open brackets must be closed by the same type of brackets.
//Open brackets must be closed in the correct order.
//Note that an empty string is also considered valid.
//
//Example 1:
//
//Input: "()"
//	Output : true
//	Example 2 :
//
//	Input : "()[]{}"
//	Output : true
//	Example 3 :
//
//	Input : "(]"
//	Output : false
//	Example 4 :
//
//	Input : "([)]"
//	Output : false
//	Example 5 :
//
//	Input : "{[]}"
//	Output : true
//--------------------------------------------------------------------

#include <string>
#include <vector>
#include <list>




class Solution {


public:
	//bool isValid(std::string s) {
	//	std::list<char> stack;

	//	char stackLast = 0;
	//	for(const char& ch : s)
	//	{
	//		if(ch == '(' || ch == '{' || ch == '[')
	//		{
	//			stackLast = ch;
	//			stack.push_back(ch);
	//		}

	//		if(ch == ')' || ch == '}' || ch == ']')
	//		{
	//			if((stackLast == '(' && ch == ')')||
	//				(stackLast == '[' && ch == ']') ||
	//				(stackLast == '{' && ch == '}') 
	//				)
	//			{

	//				stack.pop_back();
	//				if(!stack.empty())
	//				{
	//					stackLast = stack.back();
	//				}
	//			}
	//			else
	//			{
	//				return false;
	//			}
	//			 
	//		}
	//	}

	//	if(!stack.empty()) return false;

	//	return true;

	//}


	bool findValid(char ch, int& idx, const std::string& s)
	{
		int length = static_cast<int>(s.length());
		for(; idx < length; idx++)
		{
			char tempCh = s[idx];
			if(tempCh == '(' || tempCh == '{' || tempCh == '[')
			{
				idx++;
				bool result = findValid(tempCh, idx, s);
				if(result==false) return false;
			}

			if(tempCh == ')' || tempCh == '}' || tempCh == ']')
			{
				if((ch == '(' && tempCh == ')')||
					(ch == '[' && tempCh == ']') ||
					(ch == '{' && tempCh == '}') 
					)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		}

		return false;
	}


	bool isValid(std::string s) {
		if(s.empty()) return true;

		int length = static_cast<int>(s.length());
		for(int i = 0; i < length; i++)
		{
			char tempCh = s[i];
			if(tempCh == '(' || tempCh == '{' || tempCh == '[')
			{
				i++;
				bool result = findValid(tempCh, i, s);
				if(result==false) return false;
			}

			if(tempCh == ')' || tempCh == '}' || tempCh == ']')
			{
				return false;
			}
		}

		return true;

	}

};



//int main()
//{
//	Solution so;
//	std::string str("[]}");
//	
//
//	bool result = so.isValid(str);
//
//	return 0;
//
//}


