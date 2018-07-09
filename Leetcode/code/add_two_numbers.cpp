//--------------------------------------------------------------------
//2. Add Two Numbers
//You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
//
//You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
//Example
//
//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//Output: 7 -> 0 -> 8
//Explanation: 342 + 465 = 807.
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

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        

  }

};



int main()
{
	ListNode* node11 = new ListNode(1);
	ListNode* node12 = new ListNode(2);
	node11->next = node12;
	ListNode* node13 = new ListNode(3);
	node12->next = node13;

	ListNode* node21 = new ListNode(8);
	ListNode* node22 = new ListNode(9);
	node21->next = node22;
	ListNode* node23 = new ListNode(2);
	node22->next = node23;

	Solution so;
	ListNode* result = so.addTwoNumbers(node11,node21);

	return 0;

}


