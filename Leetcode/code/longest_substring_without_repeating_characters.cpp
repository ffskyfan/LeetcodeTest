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

	}
};


int main()
{
	string a("abcabcbb");

	Solution so;
	int result = so.lengthOfLongestSubstring(a);

	return 0;

}


