//--------------------------------------------------------------------
//203. Remove Linked List Elements
//Easy
//Remove all elements from a linked list of integers that have value val.
//
//Example:
//
//Input:  1->2->6->3->4->5->6, val = 6
//	Output : 1->2->3->4->5
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
	ListNode* removeElements(ListNode* head, int val) {
		ListNode* currentNode = head;
		ListNode* previousNode = nullptr;
		while(true)
		{
			if(currentNode==nullptr) break;

			if(currentNode->val == val)
			{
				if(previousNode != nullptr)
				{
					previousNode->next = currentNode->next;
				}

				if(currentNode == head)
				{
					head = currentNode->next;
				}

				ListNode* temp = currentNode;
				currentNode = currentNode->next;
				delete temp;
			}
			else
			{
				previousNode = currentNode;
				currentNode = currentNode->next;
			}

		}

		return head;

	}

};



//int main()
//{
//	Solution so;
//	std::vector<int> nums = {1,2,4,3,5,3,4,3,4,5,3,4,7};
//
//	int result = so.removeElement(nums, 3);
//
//	return 0;
//
//}


