//--------------------------------------------------------------------
//19. Remove Nth Node From End of List
//Medium
//Given a linked list, remove the n - th node from the end of list and return its head.
//
//Example:
//
//Given linked list : 1->2->3->4->5, and n = 2.
//
//After removing the second node from the end, the linked list becomes 1->2->3->5.
//Note :
//
//	Given n will always be valid.
//
//	Follow up :
//
//Could you do this in one pass ?
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
#include <vector>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//1 pass的解法
//最正常的算法就是先遍历一遍，得到链表元素数量，然后在减去n值，得到正方向数的位置，然后再遍历到对应位置删除
//但是本方法需要遍历两遍，遍历一遍的方法是这样：
//我们用两个指针，一号指针和二号指针，一号指针先遍历n步，然后一号和二号两个指针同时步进，这样一号指针遍历到队尾的时候，
//二号指针的位置正好是从队尾往前移动n位的位置，之后将二号指针处理一下就好。

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* dummy= new ListNode(0);
		dummy->next = head;

		ListNode* first=dummy;
		ListNode* second=dummy;
		for(int i=0; i<= n ; i++)
		{
			first = first->next;
		}

		while(first!=nullptr)
		{
			first = first->next;
			second = second->next;
		}

		second->next = second->next->next;
		return dummy->next;
	}
};



int main()
{
	ListNode* node1 = new ListNode(1);


	Solution so;
	ListNode* result = so.removeNthFromEnd(node1, 1);

	return 0;

}


