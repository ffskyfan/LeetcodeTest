//--------------------------------------------------------------------
//111. Minimum Depth of Binary Tree
//Easy
//Given a binary tree, find its minimum depth.
//
//The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
//
//Note: A leaf is a node with no children.
//
//	Example :
//
//	Given binary tree[3, 9, 20, null, null, 15, 7],
//
//	 3
//	/ \
//	9  20
//	  / \
//	 15  7
//	return its minimum depth = 2.
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
	int minDepth(TreeNode* root) {
		if(root == NULL) return 0;
		if(root->left == NULL && root->right == NULL) return 1; 

		int minRight = minDepth(root->right);
		int minLeft = minDepth(root->left);

		if(minRight==0) return ++minLeft;
		if(minLeft==0) return ++minRight;

		return minRight < minLeft ? ++minRight : ++minLeft;
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


