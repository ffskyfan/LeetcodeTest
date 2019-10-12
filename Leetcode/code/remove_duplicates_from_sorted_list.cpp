/*-----------------------------------------------------------------
83. Remove Duplicates from Sorted List
Easy
Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:

Input: 1->1->2
Output: 1->2
Example 2:

Input: 1->1->2->3->3
Output: 1->2->3
------------------------------------------------------------------*/

#include <string>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* node = head;
		while(node != NULL && node->next != NULL)
		{
			if(node->val == node->next->val)
			{
				ListNode* nodeDel = node->next;
				node->next = node->next->next;
				delete nodeDel;
			}
			else
			{
				node = node->next;
			}
		}

		return head;

	}
};


//int main()
//{
//	Solution so;
//	ListNode* a1 = new ListNode(2);
//	ListNode* a2 = new ListNode(2);
//	a1->next = a2;
//	ListNode* a3 = new ListNode(4);
//	a2->next = a3;
//	ListNode* a4 = new ListNode(4);
//	a3->next = a4;
//
//
//
//	ListNode* result = so.deleteDuplicates(a1);
//
//	return 0;
//
//}