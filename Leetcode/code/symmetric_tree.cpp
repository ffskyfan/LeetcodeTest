//--------------------------------------------------------------------
//101. Symmetric Tree
//Easy
//Given a binary tree, check whether it is a mirror of itself(ie, symmetric around its center).
//
//For example, this binary tree[1, 2, 2, 3, 4, 4, 3] is symmetric :
//
//1
/// \
//2   2
/// \ / \
//3  4 4  3
//
//
//But the following[1, 2, 2, null, 3, null, 3] is not:
//
//1
/// \
//2   2
//\   \
//3    3
//
//
//Note:
//Bonus points if you could solve it both recursively and iteratively.
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

	bool isSymmetric(TreeNode* left, TreeNode* right) 
	{	
		if(left == NULL && right == NULL) return true;
		if(left == NULL || right == NULL) return false;
		if(left->val != right->val) return false;

		if(isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left)) return true;

		return false;
	}

	bool isSymmetric(TreeNode* p) {

		if(p == NULL ) return true;

		return isSymmetric(p->left, p->right);
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


