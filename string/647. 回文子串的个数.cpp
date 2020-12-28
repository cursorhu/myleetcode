647. 回文子串的个数.cpp
给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。

具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。

示例 1：
输入："abc"
输出：3
解释：三个回文子串: "a", "b", "c"
示例 2：

输入："aaa"
输出：6
解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa"


/*
题解：
思路：问题分解一下： 回文串 + 子串

如何判断字符串是回文？回文的特点就是镜像
用中心拓展法：从中间点比较两边，每个字符都相同就是回文字符串
什么是中心？这取决于字符个数是奇数还是偶数
奇数：L/2 + 1, 奇数：L/2， L:字符个数

下面考虑子串
不超过边界的任意连续字符串，都是子串
如何判断子串是否回文？
用上面的中心拓展思路，首先要找子串的中心和大小(或边界)

用枚举翻转思路，不用找子串的中心，而是找每个位置作为中心的子串，是否满足回文
一个位置作为中心，包含两个不相交的子集：作为奇数子串的中心，作为偶数子串的中心
因此总子串数是这两个子集计数的和
*/


class Solution {
public:
    int countSubstrings(string s) {
    	if(s.empty()) return 0;

    	int totalcount = 0;
    	for (int i = 0; i < s.size(); ++i)
    	{
    		totalcount += validSubStringCount(s, i, i); //该位置作为奇数长度子串的中心
    		totalcount += validSubStringCount(s, i, i + 1); //该位置作为偶数长度子串的中心
    	}
    	return totalcount;
    }

    int validSubStringCount(string s, int l, int r)
    {
    	//以当前中心，向两边扩展，遍历到的回文子串的计数
    	int count = 0;
    	//满足回文对称
    	while (s[l] == s[r])
    	{
    		++count;
    		--l;
    		++r;
    		//需要满足边界,注意这个判断是更新l,r之后，保证下次while判断不会访问越界
    		//也可以写到while中去，while (l >= 0 && r < s.size() && s[l] == s[r])，边界判断必须写在访问数组左侧
    		if(l < 0 || r > s.size() - 1)
    			break; 
    	}
    	return count;
    }

};