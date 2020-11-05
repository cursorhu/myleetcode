/*
72. 编辑距离
给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。

你可以对一个单词进行如下三种操作：

插入一个字符
删除一个字符
替换一个字符
 

示例 1：

输入：word1 = "horse", word2 = "ros"
输出：3
解释：
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e')
示例 2：

输入：word1 = "intention", word2 = "execution"
输出：5
解释：
intention -> inention (删除 't')
inention -> enention (将 'i' 替换为 'e')
enention -> exention (将 'n' 替换为 'x')
exention -> exection (将 'n' 替换为 'c')
exection -> execution (插入 'u')

*/


/*
说明：动态规划
子问题：子串的编辑距离
子问题递推化：使用某操作（增删改），使有单个差异字母的两个子串变成相同
dp[i][j]递推:从[i-1,j-1]或[i,j-1]或[i-1,j]到ij处，子串同一化的步数
题解： 
i指向word1某字符，j指向word2某字符, dp[i][j]表示ij处子串的编辑距离
若当前字母相同，则dp[i][j] = dp[i - 1][j - 1];
否则取增删替三个操作的最小值 + 1， 即:
dp[i][j] = min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]) + 1

示例：
str1: aac
str2: aab

假设ij都指向最后位置
考虑前面可能发生的操作：
1.最后一步是改：str1的c改成b
2.最后一步是删：str1插入b -> aabc, 删掉c -> aab
3.最后一步是增：str1删除c -> aa, 增加b -> aab
就像平行宇宙，只要指向位置的字符不同就一定要操作，且最后一步操作可以有三种可能。
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));

        //边界
        for (int i = 0; i < dp.size(); i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j < dp[0].size(); j++) {
            dp[0][j] = j;
        }

        for (int i = 1; i < dp.size(); i++) {
            for (int j = 1; j < dp[i].size(); j++) {
            	if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1]; //不需修改
                }
                else
                	dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1; //有修改，选操作最少的修改路径
            }
        }

        return dp.back().back();
    }
};
