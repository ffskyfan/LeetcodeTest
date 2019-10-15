//--------------------------------------------------------------------
//107. Binary Tree Level Order Traversal II
//Easy
//Given a binary tree, return the bottom - up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
//
//For example :
//Given binary tree[3, 9, 20, null, null, 15, 7],
//	3
// / \
//9  20
//	 / \
//	15   7
//return its bottom - up level order traversal as :
//[
//	[15, 7],
//	[9, 20],
//	[3]
//]
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


	void levelOrderBottom(TreeNode* tree, size_t idx, std::vector<std::vector<int>>& result) {
		if(tree == NULL) return;

		if(idx >= result.size())
		{
			std::vector<int> thisLevelResult;
			result.push_back(thisLevelResult);
		}

		result[idx].push_back(tree->val);

		idx++;
		levelOrderBottom(tree->left, idx, result);
		levelOrderBottom(tree->right, idx, result);
	}

public:
	std::vector<std::vector<int>> levelOrderBottom(TreeNode* root) {

		std::vector<std::vector<int>> result;
		size_t idx = 0;
		levelOrderBottom(root, idx, result);
		std::reverse(result.begin(), result.end());

		return result;
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


