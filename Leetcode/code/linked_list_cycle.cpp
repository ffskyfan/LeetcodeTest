/*-----------------------------------------------------------------
//141. Linked List Cycle
//Easy
//Given a linked list, determine if it has a cycle in it.
//
//To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.
//
//
//
//Example 1:
//
//Input: head = [3,2,0,-4], pos = 1
//Output: true
//Explanation: There is a cycle in the linked list, where tail connects to the second node.
//
//
//Example 2:
//
//Input: head = [1,2], pos = 0
//Output: true
//Explanation: There is a cycle in the linked list, where tail connects to the first node.
//
//
//Example 3:
//
//Input: head = [1], pos = -1
//Output: false
//Explanation: There is no cycle in the linked list.
//
//
//
//
//Follow up:
//
//Can you solve it using O(1) (i.e. constant) memory?
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
	bool hasCycle(ListNode *head) {
		if(head == nullptr) return false;
		ListNode* stepOneIt = head;
		ListNode* stepTwoIt = head;
		for(;;)
		{
			stepOneIt = stepOneIt->next;
			if(stepOneIt == nullptr) return false;
			stepTwoIt = stepTwoIt->next;
			if(stepTwoIt == nullptr) return false;
			stepTwoIt = stepTwoIt->next;
			if(stepTwoIt == nullptr) return false;

			if(stepOneIt == stepTwoIt || stepTwoIt->next == stepOneIt) return true;
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