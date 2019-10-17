//--------------------------------------------------------------------
//108. Convert Sorted Array to Binary Search Tree
//Easy
//Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
//
//For this problem, a height - balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
//
//Example:
//
//Given the sorted array : [-10, -3, 0, 5, 9],
//
//One possible answer is : [0, -3, 9, -10, null, 5], which represents the following height balanced BST :
//
//		0
//	   / \
//	  -3 9
//	 /   /
//  -10  5
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
	TreeNode* sortedArrayToBST(std::vector<int>& nums) 
	{
		if(nums.size()==0) return NULL;

		return sortedArrayToBST(nums, 0, static_cast<int>(nums.size()) - 1);
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


