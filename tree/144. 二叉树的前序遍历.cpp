144. 二叉树的前序遍历.cpp
给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
用递归和非递归分别实现

示例 1：
输入：root = [1,null,2,3]
输出：[1,2,3]

/*
题解：
	递归不用说，非递归考察的是递归的本质
	递归，实际隐式利用了栈，层层调用递归函数就是不断入栈，达到终结条件后，层层出栈，最终返回全局结果
	非递归方法，就是手动实现栈的pop,push过程

关于二叉树的前中后序遍历的非迭代写法，参考
https://leetcode-cn.com/problems/binary-tree-preorder-traversal/solution/dai-ma-sui-xiang-lu-chi-tou-qian-zhong-hou-xu-de-d/
*/


/*递归*/
class Solution {
private:
	vector<int> preorder; //返回数据定义为类成员，可省去多次传参
public:
    vector<int> preorderTraversal(TreeNode* root) { 
        if (!root) return preorder; //返回空vector 
        preorderTraversalRecursive(root);
       	return preorder;    
    }

    void preorderTraversalRecursive(TreeNode* root)
    {
    	if (!root) return; //void的返回方法
    	preorder.push_back(root->val); //根
       	preorderTraversal(root->left); //左子树所有节点
       	preorderTraversal(root->right); //右子树所有节点
    }
};



/*非递归，用栈保证按序遍历*/
class Solution {
private:
	vector<int> preorder; 
	stack<TreeNode*> s;
public:
    vector<int> preorderTraversal(TreeNode* root) { 
        if (!root) return preorder;
        preorderTraversalByStack(root);
       	return preorder;    
    }

    /*用栈做树的x序遍历，非常类似用队列做树的层序遍历，体会一下*/
    void preorderTraversalByStack(TreeNode* root)
    {
    	if (!root) return; 
    	s.push(root); //当前根入栈，作为初始状态
    	while(!s.empty()) //循环：节点出栈取值，右左节点入栈
    	{
    		//从栈中取当前根值
    		TreeNode* cur_root = s.top();
    		s.pop();
    		//写入前序数组
    		preorder.push_back(cur_root->val); 
    		//左右根入栈，注意，先右后左入栈，下一轮取值才是先左后右
    		if(cur_root->right)
    			s.push(cur_root->right);
    		if(cur_root->left)
    			s.push(cur_root->left);
    	}
    }
};