//--------------------------------------------------------------------
//32. Longest Valid Parentheses
//Hard
//Given a string containing just the characters '(' and ')', find the length of the longest valid(well - formed) parentheses substring.
//
//
//
//Example 1:
//
//Input: s = "(()"
//Output : 2
//Explanation : The longest valid parentheses substring is "()".
//Example 2 :
//
//	Input : s = ")()())"
//	Output : 4
//	Explanation : The longest valid parentheses substring is "()()".
//	Example 3 :
//
//	Input : s = ""
//	Output : 0
//
//
//	Constraints :
//
//	0 <= s.length <= 3 * 104
//	s[i] is '(', or ')'.
//--------------------------------------------------------------------

#include <string>
#include <vector>

using namespace std;


class Solution {

	int findContinousValidParentheses(const string& s, const int& length, int& idx, int& depth)
    {
        idx++;
		depth++;
        if(idx >= length)
        {
            return 0;
        }


        if(s[idx] == ')')
        {
			depth--;
            return 1;
        }
        else 
        {
			int validPCount = 0;
            for(;;)
            {
				int count = findContinousValidParentheses(s, length, idx, depth);
				validPCount += count;
				if(depth == 0) 
                    break;

				if(idx >= length)
				{
					validPCount -=count;
					if(validPCount < count)validPCount = count;
                    depth--;
					break;
				}

            }

            return validPCount;
        }

    }


public:
    int longestValidParentheses(string s) {

        int length = static_cast<int>(s.size());
		int result = 0;
        for(int i = 0; i < length; )
        {
            if(s[i] == '(')
            {
                bool isContinue = true;
                int depth = 0;
				int validPCount = findContinousValidParentheses(s, length, i, depth);
                if(validPCount > result)
                {
					result = validPCount;
                }
            }
            else
            {
                i++;
                continue;
            }
        }


        return result*2;
    }

};



int main()
{
	Solution so;
	std::string s = "(((()())())(((((((())))))";
	

	int result = so.longestValidParentheses(s);

	return 0;

}


