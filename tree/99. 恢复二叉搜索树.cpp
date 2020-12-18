99. 恢复二叉搜索树.cpp
给你二叉搜索树的根节点 root ，该树中的两个节点被错误地交换。请在不改变其结构的情况下，恢复这棵树。

进阶：使用 O(n) 空间复杂度的解法很容易实现。你能想出一个只使用常数空间的解决方案吗？

示例 1：
输入：root = [1,3,null,null,2]
输出：[3,1,null,null,2]
解释：3 不能是 1 左孩子，因为 3 > 1 。交换 1 和 3 使二叉搜索树有效。

/*

中序遍历BST，得到数组的值是递增的，错误的BST会破坏递增性，就能定位出错误。
错误只会有两种：
错误1，出现了两对不满足前小后大，将第一对的第一个元素与第二对的第二个元素交换。
错误2，只出现一对不满足前小后大，交换这一对就行。

画图参考：
https://leetcode-cn.com/problems/recover-binary-search-tree/solution/tu-jie-hui-fu-yi-ge-er-cha-sou-suo-shu-by-hyj8/

*/

class Solution {
private:
	TreeNode *err1, *err2;
	TreeNode *prev_root;

public:
    void recoverTree(TreeNode* root) {
    	err1 = nullptr;
    	err2 = nullptr;
    	prev_root = nullptr;
    	
    	inorder(root);
    	swap(err1, err2);
    }

    void swap(TreeNode *p1, TreeNode *p2)
    {
    	if(!p1 || !p2) return;
    	int temp = p1->val;
    	p1->val = p2->val;
    	p2->val = temp;
    }


   	void inorder(TreeNode* root)
   	{
   		if(!root) return;
   		//中序遍历，先左递归
   		if(root->left)
   			inorder(root->left);

   		//当前根节点的处理：判断是否有逆序的一对值
   		//如果有一对，这两个即为要交换的位置
   		//如果有两对，取第一对的左侧为第一交换点，第二队右侧为第二交换点
   		if(prev_root && prev_root->val > root->val)
   		{
   			if(!err1 && !err2) //err1,err2均为空，即当前找到第一个错误对
   			{
   				err1 = prev_root;  //inorder数组内，prev_root是当前错误对中靠左的
   				err2 = root;  //root是当前错误对靠右的
   			} 
   			else
   				err2 = root; //找到第二个错误对(若存在)，取靠右的节点，即root
   		}
   		//更新下一轮的prev根
   		//prev_root仅能表示当前递归层和其下层的父子节点关系
   		//左递归的初始prev_root就是nullptr，到叶节点才会不断向上迭代prev_root
   		//右递归的初始prev_root是全局root，递归时不断向下迭代prev_root
   		prev_root = root; 

   		//最后右递归
   		if(root->right)
   			inorder(root->right);
   	}
};