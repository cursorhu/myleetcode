669. 修剪二叉搜索树.cpp
给你二叉搜索树的根节点 root ，同时给定最小边界low 和最大边界 high。通过修剪二叉搜索树，使得所有节点的值在[low, high]中。
修剪树不应该改变保留在树中的元素的相对结构（即，如果没有被移除，原有的父代子代关系都应当保留）。可以证明，存在唯一的答案。
所以结果应当返回修剪好的二叉搜索树的新的根节点。注意，根节点可能会根据给定的边界发生改变。

示例 1：
输入：root = [1,0,2], low = 1, high = 2
输出：[1,null,2]



/*
利用二叉查找树的有序性，利用递归遍历树，只保留范围内的节点
记住，每次只处理当前根，对于本题，判断当前根节点是否在范围内，左右节点交给下轮递归处理
leetcode不要求释放节点内存，只需要修改指针即可
*/


class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(!root) return nullptr;

        //先序遍历，先做当前根的处理:
        //当前节点是否在范围内，如果不在，递归找可能在范围内的节点
        //注意这里是直接return，而不是root=root->right
        if(root->val < low)
        	return trimBST(root->right, low, high);
        
        else if(root->val > high)
        	return trimBST(root->left, low, high);

        //当前节点在范围内，递归左右剪枝
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);

        return root;
    }

};