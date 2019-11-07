//--------------------------------------------------------------------
//206. Reverse Linked List
//Easy
//Reverse a singly linked list.
//
//Example:
//
//Input: 1->2->3->4->5->NULL
//	Output : 5->4->3->2->1->NULL
//	Follow up :
//
//	   A linked list can be reversed either iteratively or recursively.Could you implement both ?
//--------------------------------------------------------------------

#include <string>
#include <vector>


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

class Solution {

public:
	ListNode* reverseList(ListNode* head) {
		if(head == nullptr || head->next == nullptr) return head;

		ListNode* temp = head->next;
		ListNode* tempNext = head->next->next;
		head->next = nullptr;
		while(temp!=nullptr)
		{
			temp->next = head;
			head = temp;

			temp = tempNext;
			if(tempNext != nullptr)
			{
				tempNext = tempNext->next;
			}

		}

		return head;
	}

};



//int main()
//{
//	Solution so;
//
//	ListNode* a1 = new ListNode(1);
//	ListNode* a2 = new ListNode(2);
//	a1->next = a2;
//	ListNode* a3 = new ListNode(3);
//	a2->next = a3;
//	ListNode* a4 = new ListNode(4);
//	a3->next = a4;
//	ListNode* a5 = new ListNode(5);
//	a4->next = a5;
//
//
//	ListNode* result = so.reverseList(a1);
//
//	return 0;
//
//}


