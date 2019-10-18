//--------------------------------------------------------------------
//437. Path Sum III
//Easy
//You are given a binary tree in which each node contains an integer value.
//
//Find the number of paths that sum to a given value.
//
//The path does not need to start or end at the root or a leaf, but it must go downwards(traveling only from parent nodes to child nodes).
//
//The tree has no more than 1, 000 nodes and the values are in the range - 1, 000, 000 to 1, 000, 000.
//
//Example:
//
//root = [10, 5, -3, 3, 2, null, 11, 3, -2, null, 1], sum = 8
//
//		10
//	    / \
//	   5  -3
//	  / \    \
//   3   2   11
//  / \   \
// 3  -2   1
//
//Return 3. The paths that sum to 8 are:
//
//1.  5 -> 3
//2.  5 -> 2 -> 1
//3. - 3 -> 11
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
	int findPath(TreeNode* tree, int sum, int add, bool isBegin)
	{
		if(tree==NULL) return 0;

		int selfResult = 0;
		add = tree->val + add;
		if(add == sum) selfResult = 1;

		int leftResult = findPath(tree->left, sum, add, false);
		int rightResult = findPath(tree->right, sum, add, false);

		int leftResultR = 0;
		int rightResultR = 0;
		if(isBegin == true)
		{
			leftResultR = findPath(tree->left, sum, 0, true);
			rightResultR = findPath(tree->right, sum, 0, true);
		}

		return selfResult+leftResult+rightResult+leftResultR+rightResultR;
	}

public:
	int pathSum(TreeNode* root, int sum) {
		return findPath(root, sum, 0, true);
	}

};



int main()
{
	Solution so;
	//TreeNode* root = new TreeNode(10);
	//root->left = new TreeNode(5);
	//root->right = new TreeNode(-3);
	//
	//root->right->right = new TreeNode(11);

	//root->left->left = new TreeNode(3);
	//root->left->right = new TreeNode(2);

	//root->left->left->left= new TreeNode(3);
	//root->left->left->right = new TreeNode(-2);

	//root->left->right->right = new TreeNode(1);

	TreeNode* root = new TreeNode(1);
	root->right = new TreeNode(2);
	root->right->right = new TreeNode(3);
	root->right->right->right= new TreeNode(4);
	root->right->right->right->right = new TreeNode(5);

	int  result = so.pathSum(root, 3);

	return 0;

}


