//--------------------------------------------------------------------
//104. Maximum Depth of Binary Tree
//Easy
//Given a binary tree, find its maximum depth.
//
//The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
//
//Note: A leaf is a node with no children.
//
//	Example :
//
//	Given binary tree[3, 9, 20, null, null, 15, 7],
//
//	 3
//	/ \
// 9  20
//	  / \
//	15   7
//	return its depth = 3.
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


public:
	int maxDepth(TreeNode* root) {
		if(root == NULL) return 0;

		int maxRight = maxDepth(root->right);
		int maxLeft = maxDepth(root->left);
		return maxRight > maxLeft ? ++maxRight : ++maxLeft;
	}

};



//int main()
//{
//	Solution so;
//	std::vector<int> a={1,2,-4,-5,6,3,6,-1,5,9,-6};
//	
//
//	int result = so.maxSubArray(a);
//
//	return 0;
//
//}


