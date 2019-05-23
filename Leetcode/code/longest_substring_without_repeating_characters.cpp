//--------------------------------------------------------------------
//Given a string, find the length of the longest substring without repeating characters.
//
//Example 1:
//
//Input: "abcabcbb"
//	Output : 3
//	Explanation : The answer is "abc", with the length of 3.
//	Example 2 :
//
//	Input : "bbbbb"
//	Output : 1
//	Explanation : The answer is "b", with the length of 1.
//	Example 3 :
//
//	Input : "pwwkew"
//	Output : 3
//	Explanation : The answer is "wke", with the length of 3.
//	Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
//--------------------------------------------------------------------

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <string>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		size_t count = s.size();
		if(count<=1) return count;

		size_t subBeginIdx = 0;
		size_t subEndIdx = 0;
		int maxLength = 0;
		for(; subEndIdx < count;)
		{
			subEndIdx++;

			char endValue = 0;
			if(subEndIdx != count) endValue = s[subEndIdx];

			int tempMaxLength = 0;
			for(size_t i = subBeginIdx; i <= subEndIdx; i++)
			{
				if(i == count) break;

				tempMaxLength++;

				if(i == subEndIdx) break;

				if(s[i] == endValue)
				{
					subBeginIdx = i + 1;
					break;
				}
			}


			if(tempMaxLength > maxLength)
			{
				maxLength = tempMaxLength;
			}

		}

		return maxLength;
	}
};


int main()
{
	string a("bb");

	Solution so;
	int result = so.lengthOfLongestSubstring(a);

	return 0;

}


