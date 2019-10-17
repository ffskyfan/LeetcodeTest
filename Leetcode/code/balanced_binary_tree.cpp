//--------------------------------------------------------------------
//110. Balanced Binary Tree
//Easy
//Given a binary tree, determine if it is height - balanced.
//
//For this problem, a height - balanced binary tree is defined as :
//
//a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
//
//Example 1 :
//
//	Given the following tree[3, 9, 20, null, null, 15, 7] :
//
//		3
//	   / \
//	  9  20
//	    / \
//	  15   7
//	Return true.
//
//	Example 2:
//
//Given the following tree[1, 2, 2, 3, 3, null, null, 4, 4] :
//
//		1
//	   / \
//	  2   2
//	 / \
//	3   3
// / \
//4   4
//	Return false.
//--------------------------------------------------------------------

#include <string>
#include <vector>

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };




class Solution {

	TreeNode* sortedArrayToBST(std::vector<int>& nums,int start, int end) 
	{
		int mid = start+((end-start)/2);
		TreeNode* tree = new TreeNode(nums[mid]);

		if(start==end) return tree;

		int leftStart = start;
		int leftEnd = mid-1;
		leftEnd = leftEnd < leftStart ? leftStart : leftEnd;
		if(leftStart != mid && leftEnd != mid)
		{
			TreeNode* left = sortedArrayToBST(nums, leftStart, leftEnd);
			tree->left = left;
		}

		int rightStart = mid+1;
		int rightEnd = end;
		rightStart = rightStart > end ? end : rightStart;
		if(rightStart != mid && rightEnd != mid)
		{
			TreeNode* right = sortedArrayToBST(nums, rightStart, rightEnd);
			tree->right = right;
		}

		return tree;
	}



public:
	bool isBalanced(TreeNode* root) {

	}

};



//int main()
//{
//	Solution so;
//	std::vector<int> a={-10, -3, 0, 5, 9};
//	
//
//	TreeNode*  result = so.sortedArrayToBST(a);
//
//	return 0;
//
//}


