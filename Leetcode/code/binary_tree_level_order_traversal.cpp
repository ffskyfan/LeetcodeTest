//--------------------------------------------------------------------
//102. Binary Tree Level Order Traversal
//Medium
//Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
//
//For example :
//Given binary tree[3, 9, 20, null, null, 15, 7],
//	3
// / \
//9  20
//	 / \
//  15  7
//return its level order traversal as :
//[
//	[3],
//	[9, 20],
//	[15, 7]
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


	void levelOrder(TreeNode* tree, size_t idx, std::vector<std::vector<int>>& result) {
		if(tree == NULL) return;

		if(idx >= result.size())
		{
			std::vector<int> thisLevelResult;
			result.push_back(thisLevelResult);
		}

		result[idx].push_back(tree->val);

		idx++;
		levelOrder(tree->left, idx, result);
		levelOrder(tree->right, idx, result);
	}

public:
	std::vector<std::vector<int>> levelOrder(TreeNode* root) {

		std::vector<std::vector<int>> result;
		result.reserve(64);
		size_t idx = 0;
		levelOrder(root, idx, result);

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


