437. 路径总和 III.cpp
给定一个二叉树，它的每个结点都存放着一个整数值。
找出路径和等于给定数值的路径总数。
路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。
二叉树不超过1000个节点，且节点数值范围是 [-1000000,1000000] 的整数。

示例：
root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

返回 3。和等于 8 的路径有:
1.  5 -> 3
2.  5 -> 2 -> 1
3.  -3 -> 11


/*
题解：
	和542.二叉树的直径解法基本一样，递归每个节点当成子树根节点
	问题是：递归中的逻辑关系，以及怎么计数？

	路径的开头可以不是根节点，结束也可以不是叶子节点，是不是有点复杂？
	递归的考虑：
	任意节点分别作为根节点，且该根节点在要求的路径内，搜索其左右子树看能否满足计数
	如何搜索其子树：
	前序遍历一遍该根节点的二叉树
	
	那么原问题可以分解成多个这个问题：
	1.对全局根节点作为根节点，预设其已经在路径内，搜索其子树之和能否满足计数条件，结果可能是0条路径或者多条路径
	2.对全局根节点的左右节点分别作为根节点，预设其在路径内，搜索其子树之和能否满足计数条件，结果可能是0条路径或者多条路径
	3.对全局根节点的左右节点的左右节点作为根节点....
	
	可见上面是个递归调用，基本结构是：
	1.一个接受任意节点作为根节点，遍历子树并计数的子函数
	2.母函数递归调用：子函数(root) + 母函数(root->left) + 母函数(root->right) 
	
	如何检验计数：
	每次递归时，由于已经假设当前根节点包含在路径，更新sum = sum - 当前根的值，传入左右子树的根，最终一定有某层的root == sum，此时计数+1
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
    int pathSum(TreeNode* root, int sum) {
    	if (!root) {
			return 0;
		}
		return TraverseForSum(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
	}
	// 辅函数: 遍历查找符合sum的计数
	int TraverseForSum(TreeNode* root, int sum) {
		if (!root) {
			return 0;
		}
		//下面三步前序遍历，根左右，顺便更新count
		int count = root->val == sum? 1: 0;
		//注意sum-root->val的含义是，当前root已经算在路径内，所以子树根的sum=sum-root->val
		//不断更新sum也保证count计数的正确：
		//找到路径的末端节点时，root->val == sum，路径计数+1，继续向下递归，输入sum=0
		//如果后续又存在路径，其多个节点之和 == sum (正负抵消)，这算另外一条路径(尽管包含上层的路径)，路径计数+1，sum又归0
		//可见对于包含关系的多条路径，计数也是正确的。
		count += TraverseForSum(root->left, sum - root->val); 
		count += TraverseForSum(root->right, sum - root->val); 
		return count;
	}

};