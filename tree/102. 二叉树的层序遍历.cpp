102. 二叉树的层序遍历.cpp

给你一个二叉树，请你返回其按 层序遍历 得到的节点值。（即逐层地，从左到右访问所有节点）。

示例：
二叉树：[3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：
[
  [3],
  [9,20],
  [15,7]
]

/*
题解：本题是二叉树程序遍历的基础例题，理解怎么实现的即可
基本流程：
    1.定义队列，放入根节点，初始化要求的全局变量
    2.while循环，结束条件是队空
        3.循环内，获取当前队列大小
        4.根据此值, for()多次
            5.front+pop获取该行当前节点值，顺便做题目要求的计算，更新全局变量
            6.当前节点左右节点入队，for结束后下一行所有节点都会入队

*** 类似的一套题目：
	107.二叉树的层次遍历 II
	515.在每个树行中找最大值
	116.填充每个节点的下一个右侧节点指针
	429.N叉树的层序遍历
	199.二叉树的右视图

	解答参考：
	https://leetcode-cn.com/problems/binary-tree-level-order-traversal/solution/er-cha-shu-ceng-xu-bian-li-deng-chang-wo-yao-da-sh/

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        //先定义题目所求的变量，后面会在遍历中更新
        //返回值类型是二维vector, root为空时不能返回nullptr而是空vector，所以定义放最前面
        vector<vector<int>> result;
        if(!root) return result;

        //队列存储每层的节点
        queue<TreeNode*> q;
        //先把全局root入队
        q.push(root);
        
        //开始每层遍历，q包含每层节点，q非空即该层节点还遍历没完
        while (!q.empty()) {
        	//保存当前层的节点个数
            int size = q.size();
            //题目要求每层一个vector，所以在每次循环内定义
            vector<int> vec;
            //循环处理当前行的每个节点
            //这里一定要使用固定大小size，而非q.size()，因为q.size是不断变化的
            for (int i = 0; i < size; i++) {
            	//front获取当前层(行)的左侧节点，并pop删除之
                TreeNode* node = q.front();
                q.pop();
                //写值到当前行的vector
                vec.push_back(node->val);
                //下一行的两个节点按序入队，先左后右
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            //当前行完成，行vector追加到全局二维vector中
            result.push_back(vec);
        }
        return result;
    }
};