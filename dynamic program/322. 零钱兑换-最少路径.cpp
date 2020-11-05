
/*
322. 零钱兑换
给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。

你可以认为每种硬币的数量是无限的。

 

示例 1：

输入：coins = [1, 2, 5], amount = 11
输出：3 
解释：11 = 5 + 5 + 1
*/


 /*
 题解：
 凡是能用暴力枚举的，求最大，最小值问题，都可以用动态规划
 动态规划的关键：步骤分解
 步骤分解的套路：分解元素+最后一个元素有几种情况

 理解以上三句话，凑硬币本质是个跳台阶问题：
 有11级台阶，每次可跳1,2,5级，问最少步数？

凑成面值为 11 的最少硬币个数可以由以下三者的最小值得到：
凑成面值为 10 的最少硬币个数 + 面值为 1 的这一枚硬币；
凑成面值为 9  的最少硬币个数 + 面值为 2 的这一枚硬币；
凑成面值为 6  的最少硬币个数 + 面值为 5 的这一枚硬币。

 */



class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(coins.empty() || amount == 0)
        	return 0;
        
        /*dp下标可以取到amount,所有数组长度为amount+1
        因为是求最小，这里把dp初始化成最大，若初始化成0，dp的更新基本失效。*/
        vector<int> dp(amount + 1, amount + 1); 

        dp[0] = 0;

        for(int i = 1; i <= amount; i++)
        {
        	for(int j = 0; j < coins.size(); j++)
        	{
        		if(coins[j] <= i) //加判断，因为i-coins[j]可能为负
        			dp[i] = min(dp[i-coins[j]] + 1, dp[i]);
        	}
        }

        if(dp[amount] == amount + 1) //没有成功更新dp,即无解
        	return -1;
        else 
        	return dp[amount];
    }
};