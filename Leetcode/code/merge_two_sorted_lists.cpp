/*-----------------------------------------------------------------
//21. Merge Two Sorted Lists
//Easy
//Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
//
//Example:
//
//Input: 1->2->4, 1->3->4
//Output: 1->1->2->3->4->4
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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if(l2==NULL) return l1;

		while(l1 != NULL)
		{
			if(l1->val <= l2->val)
			{
				ListNode* temp = l1->next;
				l1->next = l2;
				l2 = l1;
				l1 = temp;
			}
			else 
			{
				ListNode* traveseNode = l2;
				while(traveseNode != NULL)
				{
					if(traveseNode->next == NULL)
					{
						ListNode* temp = l1->next;
						l1->next = NULL;
						traveseNode->next = l1;
						l1 = temp;
						break;
					}
					else
					{
						if(l1->val <= traveseNode->next->val)
						{
							ListNode* temp = l1->next;
							l1->next = traveseNode->next;
							traveseNode->next = l1;
							l1 = temp;
							break;
						}
						else
						{
							traveseNode = traveseNode->next;
						}
					}

				}
			}

		}

		return l2;

	}
};


//int main()
//{
//	Solution so;
//	ListNode* a1 = new ListNode(2);
//	//ListNode* a2 = new ListNode(2);
//	//a1->next = a2;
//	//ListNode* a3 = new ListNode(4);
//	//a2->next = a3;
//
//
//	ListNode* b1 = new ListNode(1);
//	//ListNode* b2 = new ListNode(3);
//	//b1->next = b2;
//	//ListNode* b3 = new ListNode(4);
//	//b2->next = b3;
//
//	ListNode* result = so.mergeTwoLists(a1, b1);
//
//	return 0;
//
//}