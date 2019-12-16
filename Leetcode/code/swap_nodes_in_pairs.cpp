/*-----------------------------------------------------------------
//24. Swap Nodes in Pairs
//Medium
//Given a linked list, swap every two adjacent nodes and return its head.
//
//You may not modify the values in the list's nodes, only nodes itself may be changed.
//
//
//
//Example:
//
//Given 1->2->3->4, you should return the list as 2->1->4->3.
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
	ListNode* swapPairs(ListNode* head) {
		if(head == nullptr || head->next == nullptr) return head;

		ListNode* result = head->next;


		ListNode* lastSecond = nullptr;
		ListNode* first = head;
		ListNode* second = head->next;
		ListNode* temp = head->next->next;
		for(;;)
		{
			if(lastSecond != nullptr)
			{
				lastSecond->next = second;
			}

			if(first==nullptr) break;
			if(second==nullptr) break;

			second->next = first;
			first->next = temp;


			lastSecond = first;
			first = temp;
			if(temp==nullptr) break;
			second = temp->next;
			if(second==nullptr) break;
			temp = temp->next->next;
		}

		return result;

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