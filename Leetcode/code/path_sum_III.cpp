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
	int findPath(TreeNode* tree, int sum, int add)
	{
		if(tree==NULL) return 0;

		int selfResult = 0;
		add = tree->val + add;
		if(add == sum) selfResult = 1;

		int leftResult = findPath(tree->left, sum, add);
		int rightResult = findPath(tree->right, sum, add);

		int leftResultR = findPath(tree->left, sum, tree->val);
		int rightResultR = findPath(tree->right, sum, tree->val);

		return selfResult+leftResult+rightResult+leftResultR+rightResultR;
	}

public:
	int pathSum(TreeNode* root, int sum) {
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


