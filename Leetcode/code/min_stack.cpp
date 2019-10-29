//--------------------------------------------------------------------
//155. Min Stack
//Easy
//Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
//
//push(x) --Push element x onto stack.
//pop() --Removes the element on top of the stack.
//top() --Get the top element.
//getMin() --Retrieve the minimum element in the stack.
//
//
//Example:
//
//MinStack minStack = new MinStack();
//minStack.push(-2);
//minStack.push(0);
//minStack.push(-3);
//minStack.getMin();   -- > Returns - 3.
//minStack.pop();
//minStack.top();      -- > Returns 0.
//minStack.getMin();   -- > Returns - 2.
//--------------------------------------------------------------------

#include <string>
#include <vector>


class MinStack {
	struct StackNode
	{
		StackNode(int v, StackNode* n) :next(n), value(v) {}

		int value;
		StackNode* next;
	};

	StackNode* topNode;
	StackNode* minNode;

public:


	/** initialize your data structure here. */
	MinStack() {
		topNode = nullptr;
		minNode = nullptr;
	}

	~MinStack() {
		StackNode* node = topNode;
		while(node != nullptr)
		{
			StackNode* temp = node;
			node = node->next;
			delete temp;
		}
	}

	void push(int x) {
		topNode = new StackNode(x, topNode);
		if(minNode == nullptr || x < minNode->value)
		{
			minNode = topNode;
		}
	}

	void pop() {
		if(topNode == nullptr) return;

		if(minNode = topNode)
		{
			StackNode* node = topNode->next;
			minNode = node;
			while(node != nullptr)
			{
				if(node->value < minNode->value)
				{
					minNode = node;
				}

				node = node->next;
			}
		}

		StackNode* temp = topNode;
		topNode = topNode->next;
		delete temp;
	}

	int top() {
		if(topNode == nullptr) return 0;
		return topNode->value;
	}

	int getMin() {
		if(minNode == nullptr) return 0;
		return minNode->value;
	}
};





//int main()
//{
//	MinStack so;
//	so.push(2);
//	so.push(0);
//	so.push(3);
//	so.push(0);
//	so.pop();
//	so.pop();
//	so.pop();
//	so.pop();
//	
//
//	return 0;
//
//}


