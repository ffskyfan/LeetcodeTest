//--------------------------------------------------------------------
//112. Path Sum
//Easy
//
//Given a binary tree and a sum, determine if the tree has a root - to - leaf path such that adding up all the values along the path equals the given sum.
//
//Note: A leaf is a node with no children.
//
//	Example :
//
//	Given the below binary tree and sum = 22,
//
//	    5
//	   / \
//	  4   8
//	 /   / \
//  11  13  4
// / \       \
//7   2       1
//	return true, as there exist a root - to - leaf path 5->4->11->2 which sum is 22.
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
	bool findPath(TreeNode* tree, int sum, int add)
	{
		if(tree==NULL) return false;

		add = tree->val + add;
		if(tree->left == NULL && tree->right == NULL)
		{
			if(add == sum) return true;
		}

		bool leftResult = findPath(tree->left, sum, add);
		bool rightResult = findPath(tree->right, sum, add);
		if(leftResult||rightResult)  return true;

		return false;
	}

public:
	bool hasPathSum(TreeNode* root, int sum) {
		return findPath(root, sum, 0);
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


