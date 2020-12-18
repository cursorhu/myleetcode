110. 平衡二叉树.cpp
给定一个二叉树，判断它是否是高度平衡的二叉树。

本题中，一棵高度平衡二叉树定义为：
一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。

示例 1：
输入：root = [3,9,20,null,null,15,7]
输出：true


/*
题解：
	递归比较左右子树是否高度差<=1
	如何比较高度差？首先要求高度，再作差
	求树的高度，参考题目104（左右子树递归调用maxDepth）

*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
    	if(!root) 
    		return true;
    	//下面几句也可以用 ? : 写成一行代码，但是没必要，if-else易读
    	bool isbalance = abs(maxDepth(root->left) - maxDepth(root->right)) <= 1? true: false;  
    	if(isbalance)
    		return isBalanced(root->left) && isBalanced(root->right);
    	else 
    		return false;
    }

    int maxDepth(TreeNode* root) {
    	if(!root) 
    		return 0;
    	return max(1 + maxDepth(root->left), 1 + maxDepth(root->right));
    }
};