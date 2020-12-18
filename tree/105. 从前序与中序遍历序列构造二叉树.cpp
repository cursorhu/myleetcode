105. 从前序与中序遍历序列构造二叉树.cpp

根据一棵树的前序遍历与中序遍历构造二叉树。

注意:你可以假设树中没有重复的元素。

例如，给出
前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7


/*
题解：基础例题，需要理解清除两种遍历数据分块的含义，哈希由值直接获得位置索引是重要技巧。

对于任意一颗树而言，前序遍历的形式总是

[ 根节点, [左子树的前序遍历结果], [右子树的前序遍历结果] ]
即根节点总是前序遍历中的第一个节点。而中序遍历的形式总是

[ [左子树的中序遍历结果], 根节点, [右子树的中序遍历结果] ]
只要我们在中序遍历中定位到根节点，那么我们就可以分别知道左子树和右子树中的节点数目。由于同一颗子树的前序遍历和中序遍历的长度显然是相同的，因此我们就可以对应到前序遍历的结果中，对上述形式中的所有左右括号进行定位。

这样以来，我们就知道了左子树的前序遍历和中序遍历结果，以及右子树的前序遍历和中序遍历结果，我们就可以递归地对构造出左子树和右子树，再将这两颗子树接到根节点的左右位置。

小结：
	递归新建当前根节点，传入左右子树边界，终结条件是左边界>右边界
	前序得到根节点值，中序得到左右子树大小，用于下次递归
	建立中序的哈希，快速得到根在中序数组的位置。

*/


class Solution {
private:
	unordered_map <int, int> hash;

public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if(preorder.empty())
			return nullptr;

		//构造哈希映射，目的是已知根节点的值，得到其在中序数组的位置，进而得到左右子树的大小。
        //unordered_map<T, T>适用任何类型的哈希映射。本题的值和索引都是int，直接定义数组int index[]作为哈希映射也可以
		int size = preorder.size();
		for (int i = 0; i < size; ++i)
		{
			hash[inorder[i]] = i; //反向映射：根据值，得到索引
		}

		return buildTreeRecursive(preorder, inorder, 0, size-1, 0, size-1);
	}


	TreeNode* buildTreeRecursive(vector<int>& preorder, vector<int>& inorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right)
	{
		//这个判断非常重要,是递归的边界：子树为空
		if(preorder_left > preorder_right)
        	return nullptr;
		
		//根据先序，构建当前根节点
		//前序遍历中的第一个节点就是根节点
		int preorder_root = preorder_left;
		TreeNode* root = new TreeNode(preorder[preorder_root]);
		
		//根据当前根节点值和hash，得到根在后序中的位置索引，进而可得到左右子树大小, 进而得到下一轮的子树边界
		int inorder_root = hash[preorder[preorder_root]];
		int left_subtree_size = inorder_root - inorder_left;

		//递归调用，建立左右子树的根
		//先序遍历中「从 左边界+1 开始的 左子树大小」个元素就对应了中序遍历中「从 左边界 开始到 根节点定位-1」的元素
		//先序遍历中「从 左边界+1+左子树大小 开始到 右边界」的元素就对应了中序遍历中「从 根节点定位+1 到 右边界」的元素
		root->left = buildTreeRecursive(preorder, inorder, preorder_left+1, preorder_left+left_subtree_size, inorder_left, inorder_root-1);
		root->right = buildTreeRecursive(preorder, inorder, preorder_left+left_subtree_size+1, preorder_right, inorder_root+1, inorder_right);

		//返回当前递归的节点
		return root;
	}

};