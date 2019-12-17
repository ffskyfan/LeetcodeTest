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
		if(k <= 1 || head == nullptr) return head;

		ListNode** group = new ListNode*[k+2];
		for(int i=0;i<k+2;i++) group[i]=nullptr;
		ListNode* node = head;

		ListNode* result = nullptr;

		for(;;)
		{
			int i = 0;
			for(; i < k; i++)
			{
				group[i]= node;
				if(node==nullptr) break;
				node = node->next;
			}
			if(node!=nullptr) group[i] = node->next;

			if(i < k)
			{
				if(result == nullptr) result = group[0];
				if(group[k + 1] != nullptr) group[k + 1]->next = group[0];
				break;
			}

			i = i - 1;
			if(group[k + 1] != nullptr) group[k + 1]->next = group[i];
			for(; i > 0; i--)
			{
				group[i]->next = group[i-1];
			}
			group[k+1] = group[i];
			if(result == nullptr) result = group[k-1];
		}

		return result;
	}
};


//int main()
//{
//	Solution so;
//	ListNode* a1 = new ListNode(1);
//	ListNode* a2 = new ListNode(2); a1->next = a2;
//	//ListNode* a3 = new ListNode(3); a2->next = a3;
//	//ListNode* a4 = new ListNode(4); a3->next = a4;
//	//ListNode* a5 = new ListNode(5); a4->next = a5;
//
//
//
//	ListNode* result = so.reverseKGroup(a1, 3);
//
//	return 0;
//
//}