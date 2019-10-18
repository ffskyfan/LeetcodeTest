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
	bool isBalanced(TreeNode* tree,int& depth)
	{
		if(tree==NULL) return true;

		int leftDepth = 0;
		bool isLeftBalanced = isBalanced(tree->left, leftDepth);

		int rightDepth = 0;
		bool isRightBalanced = isBalanced(tree->right, rightDepth);

		if(!isLeftBalanced || !isRightBalanced) return false;
		if(abs(leftDepth-rightDepth) >1) return false;

		depth = leftDepth > rightDepth ? ++leftDepth : ++rightDepth;
		return true;
	}

public:
	bool isBalanced(TreeNode* root) {
		int depth = 0;
		return isBalanced(root, depth);
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


