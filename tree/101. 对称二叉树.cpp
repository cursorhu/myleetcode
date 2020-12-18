101. 对称二叉树.cpp
给定一个二叉树，检查它是否是镜像对称的。
例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
    1
   / \
  2   2
 / \ / \
3  4 4  3


/*
题解：
	递归，基本思想是一生二，二生无穷
	1.基本情况：空节点或只有一个节点 ==> 对称
	2.有左右子节点：左右都空，左空右有，左有右空，左右都有
	3.对于左右都有的情况，把它视为根节点，又回到了步骤1
	4.对于左右都有的情况，怎么判对称？左左和右右对称，且左右和右左对称

	对称类型的题的解法“四步法”：
	（1）如果两个子树都为空指针，则它们相等或对称
	（2）如果两个子树只有一个为空指针，则它们不相等或不对称
	（3）如果两个子树根节点的值不相等，则它们不相等或不对称
	（4）根据相等或对称要求，进行递归处理。
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
       return root? isSymmetricRecursive(root->left, root->right): true; 
    }

   	bool isSymmetricRecursive(TreeNode* left, TreeNode* right)
   	{
   		if(!left && !right) return true;	//同时为空
   		if(!left || !right) return false;	//单边为空，因为已经排除了同时为空
   		if(left->val != right->val) return false; //非空，才能判断值
   		return isSymmetricRecursive(left->left, right->right) && isSymmetricRecursive(left->right, right->left);
   	}
};