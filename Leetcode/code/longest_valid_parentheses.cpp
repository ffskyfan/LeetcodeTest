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
		int oldDepth = depth;

        if(idx >= length)
        {
            return 0;
        }


        bool canLink = true;

		if(depth != 0 && s[idx] == ')')
        {
			depth--;
            return 1;
        }
        else 
        {
            if(s[idx] == ')') return 0;

			depth++;

			int validPCount = 0;
            for(;;)
            {
				idx++;
				if(idx >= length) break;

				int count = findContinousValidParentheses(s, length, idx, depth);
                if(count==0) continue;

                if(depth == oldDepth && canLink == true)
                {
					validPCount += count;
                }
                else
                {
					if(count > validPCount)
					{
						validPCount = count;
					}

					if(canLink == true) { canLink = false; }
					else { canLink = true; }
                }


            }

            return validPCount;
        }

    }


public:
    int longestValidParentheses(string s) {

        int length = static_cast<int>(s.size());

        int idx = 0;
		int depth = 0;
		int result = findContinousValidParentheses(s, length, idx, depth);

        return result*2;
    }

};



int main()
{
	Solution so;
	std::string s = "(()())";
	

	int result = so.longestValidParentheses(s);

	return 0;

}


