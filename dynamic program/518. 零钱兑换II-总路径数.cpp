
/*
518. 零钱兑换II-总路径数
给定不同面额的硬币和一个总金额。写出函数来计算可以凑成总金额的硬币组合数。假设每一种面额的硬币有无限个。 

示例 1:

输入: amount = 5, coins = [1, 2, 5]
输出: 4
解释: 有四种方式可以凑成总金额:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
*/

/*
题解：
不同的零钱组合是不同路径，求总路径，所以dp定义为某位置（某总钱值）的总路径
步骤拆分：最后一步可选1，2, 5, 他们三个的并集才是最后一步总路径数。
dp[i] = dp[i-1] + dp[i-2] + dp[i-5]
*/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
    	if(coins.empty() || amount == 0)
        	return 0;
        
        /*dp下标可以取到amount,数组长度为amount+1
        本题求总数，dp可初始化成0 */
        vector<int> dp(amount + 1, 0); 

        dp[0] = 1; // ？？？
   		
   		//注意这里把内外循环换了，因为这是个组合问题，不是排列，一个硬币要么选要么不选，所以放在外层
   		//如果循环内层放可选硬币数，1+2和2+1将算成两种，计数重复
   		//循环变成：对一个硬币，是否会使用到凑齐总金额的步骤中，dp仍然以滑动的总金额为下标
        for(int j = 0; j < coins.size(); j++) 
        {
        	for(int i = 1; i <= amount; i++)
        	{ 
        		if(coins[j] <= i) //加判断，因为i-coins[j]可能为负
        			dp[i] += dp[i-coins[j]]; //合并每种子集
        	}
        }

        return dp[amount];
    }
};