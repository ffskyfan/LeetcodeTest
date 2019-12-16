/*-----------------------------------------------------------------
//25. Reverse Nodes in k-Group
//Hard
//Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
//
//k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
//
//Example:
//
//Given this linked list: 1->2->3->4->5
//
//For k = 2, you should return: 2->1->4->3->5
//
//For k = 3, you should return: 3->2->1->4->5
//
//Note:
//
//Only constant extra memory is allowed.
//You may not alter the values in the list's nodes, only nodes itself may be changed.
------------------------------------------------------------------*/

#include <string>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {

		vector<ListNode*> group;
		group.resize(k+1, nullptr);

		for(;;)
		{
			for(int i = 0; i < k; i++)
			{

			}

		}




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