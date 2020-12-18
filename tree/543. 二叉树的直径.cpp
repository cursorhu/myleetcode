543. 二叉树的直径.cpp

给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过也可能不穿过根结点。

示例 :
给定二叉树
          1
         / \
        2   3
       / \     
      4   5    
返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。
注意：两结点之间的路径长度是以它们之间边的数目表示
 
/*
思路一：
	等价于左右子树最大深度的和？（错误），原因：最大长度路径不一定经过根节点，比如，单边倾斜的树：
          1
         /
        2 
       / \     
      4   5
     /     \
    6       7
	
	
思路二：
	扩展思路一，要考虑根节点是树的任意节点
	因此maxDepth修改成：
	维护全局变量maxlen，保存全局最长路径
	对任意节点，求其左右最深值，如果其和大于全局最深值，则更新全局最深值。
	返回左右子树里较大的深度值。

	参考：https://leetcode-cn.com/problems/diameter-of-binary-tree/solution/hot-100-9er-cha-shu-de-zhi-jing-python3-di-gui-ye-/

	总结：二叉树的深度，边长这种问题，通常可以转化成求最大深度(递归)，只不过求深度过程中掺杂其他计算
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
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int maxlen = 0;
        maxDepth(root,maxlen);
        return maxlen;
    }

    int maxDepth(TreeNode* node, int& maxlen){
        if(!node) return 0;
        //获取左子树的最大深度
        int l = maxDepth(node->left,maxlen);
        //获取右子树的最大深度
        int r = maxDepth(node->right,maxlen);
        //获取以所有结点作为根节点时，各自的直径中的最大值
        //比较现存的maxlen和当前节点的左右路径和
        maxlen = max(maxlen, l+r);
        //返回这个树的最大深度
        return max(l,r)+1;
    }
};
