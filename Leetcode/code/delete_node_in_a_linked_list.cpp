

//--------------------------------------------------------------------
//237. Delete Node in a Linked List
//
//
//Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.
//
//Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list should become 1 -> 2 -> 4 after calling your function.
//
//
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
    void deleteNode(ListNode* node) {

		*node = *(node->next);
		if (node->next) {
			delete node->next;
		}
		//node->val = node->next->val;
		//node->next = node->next->next;
        
    }
};



int main()
{
	ListNode* node1 = new ListNode(1);
	ListNode* node2 = new ListNode(2);
	node1->next = node2;
	ListNode* node3 = new ListNode(3);
	node2->next = node3;


	Solution so;
	so.deleteNode(node1);
	//string result = so.convert("PAYPALISHIRING", 3);

	return 0;

}


