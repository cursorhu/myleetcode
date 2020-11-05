/*
1143. 最长公共子序列

给定两个字符串 text1 和 text2，返回这两个字符串的最长公共子序列的长度。

一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。
例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。两个字符串的「公共子序列」是这两个字符串所共同拥有的子序列。

若这两个字符串没有公共子序列，则返回 0。

 

示例 1:

输入：text1 = "abcde", text2 = "ace" 
输出：3  
解释：最长公共子序列是 "ace"，它的长度为 3。

*/

/* 说明：
所有的子序列问题都可以动态规划，动态规划本质是递推版的枚举
最长公共子序列的子问题是：找出所有公共子序列
而找公共子序列的子问题是：单个字母是否相同
dp[i][j]表示两个字符串i和j处的公共子序列，的长度
状态转移方程要考虑dp[i][j]和前面的状态： dp[i-1][j-1], dp[i-1][j], dp[i][j-1]的关系：
如果ij处成员相同，则公共子序列有了新成员
dp[i][j] = dp[i-1][j-1] + 1;
如果ij处成员不相同，则这两个成员肯定有一个或者都不属于公共子序列，
对于ij位置，公共子序列不新增成员，ij到底是不是公共子序列内，由其他位置dp决定
dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

最长公共子序列，即ij最大时的dp[i][j]，因为本问题dp[i][j]一定递增，不需要遍历求最大

 */

#include <algorithm>
#include <vector>

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
    	
    	//输入判断
        if(text1.empty() || text2.empty()) 
            return 0;
        
        int len1 = text1.size(); //字符个数，不包含'/0'
        int len2 = text2.size();
        
        vector<vector<int>> dp;
        
        //初始化dp数组为0, 这里dp比输入空间长宽+1
        for(int i = 0; i < len1 + 1; i++)
        {
        	dp.push_back(vector<int>()); //push_back一个一维vector，采用默认构造的方式
        	for(int j = 0; j < len2 + 1; j++)
        	{
        		dp[i].push_back(0); //初始化所有一维vector成员为0
        	}
        }

        //或者这样初始化二维vector成员为0
        //vector<vector<int>> dp(len1, vector<int>(len2, 0));

        //注意dp空间从[0,0]到[len1+1, len2+1],可以把边界dp[0,0], dp[0,j],dp[i,0]包含进来
        for(int i = 1; i < len1 + 1; i++)
        {
            for(int j = 1; j < len2 + 1; j++)
            {
                if(text1[i-1] == text2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                	dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        /* 返回最大的dp */
        int max_dp = dp[len1][len2]; //注意下标，实际是len+1-1

        return max_dp;
    	
    }
};