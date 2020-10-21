/*-----------------------------------------------------------------
23. Merge k Sorted Lists
Hard
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
------------------------------------------------------------------*/

#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {

	ListNode* skipSameValue(ListNode* node)
	{
		while(node->next != nullptr && node->val == node->next->val)
			node = node->next;

		return node;
	}


public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {

		ListNode* node = nullptr;

		int nullListCount = 0;

		//找到根部数据最小的那个list
		size_t count = lists.size();
		for(size_t i=0; i<count; i++)
		{
			ListNode* temp =  lists[i];
			if(temp == nullptr)
			{
				nullListCount++;
				continue;
			}

			if(node ==nullptr || temp->val < node->val) 
			{
				lists[i] = node;
				node = temp;
			}
		}

		if(node==nullptr) return nullptr;

		ListNode* insertNode = node;
		nullListCount++;


		while(nullListCount!=count)
		{ 

			int smallestTail = insertNode->val;

			//开始往两个不同的前后节点之间插入能插入的所有子链
			for(size_t j = 0; j < count; j++)
			{
				//如果下一个节点的值和当前节点的值一样，那么往那么中间插数没啥意义,所以要跳过这些相同的值
				insertNode = skipSameValue(insertNode);

				ListNode* temp = lists[j];
				if(temp == nullptr)  continue;

				if(insertNode->next == nullptr)
				{
					insertNode->next = temp;
					lists[j] = nullptr;
				}
				else
				{
					if(temp->val > insertNode->next->val) continue;

					ListNode* tempHead = temp;
					while(tempHead->next != nullptr && tempHead->next->val < insertNode->next->val)
					{
						tempHead = tempHead->next;
					}

					ListNode* tempInsertNodeNext = insertNode->next;

					insertNode->next = temp;
					lists[j] = tempHead->next;
					tempHead->next = tempInsertNodeNext;
				}

				if(lists[j] == nullptr) nullListCount++;
			}

			insertNode = skipSameValue(insertNode);

			if(insertNode->next != nullptr)
				insertNode = insertNode->next;
		}

		return node;
	}
};


//int main()
//{
//	Solution so;
//	ListNode* a1 = new ListNode(2);
//	ListNode* a2 = new ListNode(2);
//	a1->next = a2;
//	ListNode* a3 = new ListNode(4);
//	a2->next = a3;
//
//
//	ListNode* b1 = new ListNode(1);
//	ListNode* b2 = new ListNode(3);
//	b1->next = b2;
//	ListNode* b3 = new ListNode(4);
//	b2->next = b3;
//
//	ListNode* c1 = new ListNode(5);
//	ListNode* c2 = new ListNode(6);
//	c1->next = c2;
//	ListNode* c3 = new ListNode(7);
//	c2->next = c3;
//
//	vector<ListNode*> lists;
//	lists.push_back(nullptr);
//	lists.push_back(a1);
//	lists.push_back(b1);
//	lists.push_back(c1);
//	
//
//	ListNode* result = so.mergeKLists(lists);
//
//	return 0;
//
//}