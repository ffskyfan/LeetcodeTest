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

//1 pass�Ľⷨ
//���������㷨�����ȱ���һ�飬�õ�����Ԫ��������Ȼ���ڼ�ȥnֵ���õ�����������λ�ã�Ȼ���ٱ�������Ӧλ��ɾ��
//���Ǳ�������Ҫ�������飬����һ��ķ�����������
//����������ָ�룬һ��ָ��Ͷ���ָ�룬һ��ָ���ȱ���n����Ȼ��һ�źͶ�������ָ��ͬʱ����������һ��ָ���������β��ʱ��
//����ָ���λ�������ǴӶ�β��ǰ�ƶ�nλ��λ�ã�֮�󽫶���ָ�봦��һ�¾ͺá�

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


