//--------------------------------------------------------------------
//637. Average of Levels in Binary Tree
//Easy
//Given a non - empty binary tree, return the average value of the nodes on each level in the form of an array.
//Example 1:
//Input:
//	 3
//	/ \
// 9  20
//	 / \
//  15  7
//Output: [3, 14.5, 11]
//	Explanation :
//	The average value of nodes on level 0 is 3, on level 1 is 14.5, and on level 2 is 11. Hence return[3, 14.5, 11].
//	Note :
//	The range of node's value is in the range of 32-bit signed integer.
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
	void averageOfLevels(TreeNode* tree, int level, std::vector<int>& levelCount, std::vector<double>& result) {
		if(tree==NULL) return;

		if(level >=static_cast<int>(levelCount.size())) levelCount.push_back(0);
		levelCount[level]++;
		if(level >=static_cast<int>(result.size())) result.push_back(0);
		result[level]+=tree->val;

		level++;
		averageOfLevels(tree->left, level, levelCount, result); 
		averageOfLevels(tree->right, level, levelCount, result); 
	}

public:

	std::vector<double> averageOfLevels(TreeNode* root) {

		std::vector<double> result;
		result.reserve(64);
		std::vector<int> levelCount;
		result.reserve(64);

		averageOfLevels(root, 0, levelCount, result); 

		size_t count = result.size();
		for(size_t i = 0; i < count; i++)
		{
			result[i] = result[i]/levelCount[i];
		}

		return result;
	}
	

};



//int main()
//{
//	Solution so;
//	std::vector<int> nums = {1,2,4,3,5,3,4,3,4,5,3,4,7};
//
//	int result = so.removeElement(nums, 3);
//
//	return 0;
//
//}


