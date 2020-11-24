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
		int oldCount = 0;

        if(idx >= length)
        {
            return 0;
        }

		int validPCount = 0;
		bool canLink = true;
		for(;;)
		{

			if(idx >= length) break;
			if(depth < oldDepth) break;//小于意味着更上层的收括号让我找到了

			if(s[idx] == ')')
			{
				if(depth != 0)
				{
					depth--;
					validPCount++;
				}
				else
				{
					canLink = false;
				}

				idx++;
				continue;
			}
			else
			{
				depth++;
				idx++;
				if(idx >= length) break;

				int count = findContinousValidParentheses(s, length, idx, depth);
				if(count == 0) continue;

				if(depth > oldDepth)canLink = false;

				if(canLink == true)
				{
					validPCount += count;
				}
				else
				{
					if(validPCount>oldCount) oldCount = validPCount;
					validPCount = count;

					if(canLink == true) { canLink = false; }
					else { canLink = true; }
				}
			}

		}


		if(validPCount > oldCount) oldCount = validPCount;

		return oldCount;

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



//int main()
//{
//	Solution so;
//	std::string s = ")()())()()(";
//	
//
//	int result = so.longestValidParentheses(s);
//
//	return 0;
//
//}


