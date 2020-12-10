/*
188. 买卖股票的最佳时机 IV

给定一个整数数组 prices ，它的第 i 个元素 prices[i] 是一支给定的股票在第 i 天的价格。
设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

示例 1：
输入：k = 2, prices = [2,4,1]
输出：2
*/

/*
(错误)解题思路：
贪心算法

这个问题介于单次交易和无限次交易之间，融合两者的关键点：
单次：总利润最大
无限次：只在赚的时候交易，亏的时候不交易

因此本问题可分解成：
1. 找出所有赚的交易
2. 在其中挑出k个最大利润的交易，总利润一定最大
数组保存赚的交易，再排序，对最大的k个求和即可。

错误原因：
不满足无后效性，由于次数有限，前面买卖影响后面买卖
只能覆盖相邻天买入卖出的情况，一次交易跨多天的没有覆盖

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
    	vector<int> profit;
    	int totalProfit = 0;
    	
    	for (int i = 1; i < prices.size(); ++i)
    	 {
    	 	if(prices[i] - prices[i-1] > 0)
    	 		profit.push_back(prices[i] - prices[i-1]);
    	 } 

    	 sort(begin(profit), end(profit));

		 int start = profit.size()-k > 0 ? profit.size()-k : 0;
    	 for(int i = start; i < profit.size(); ++i)
    	 	totalProfit += profit[i];

    	 return totalProfit;
    }
};

*/


/*
正解：动态规划+贪心
注意题目中说的交易次数K其实是一买一卖算作一次交易，而不是买卖各算一次。
因此当K >= N / 2时，其实就相当于无限交易了，用贪心算法。

当K < N/2 用DP
枚举三种选择的不同状态，
第一维：天数1~N（或0~N-1），
第二维：最大交易次数1~K，
第三维：股票状态：持有还是没有持有（有时还会有cool down）。
再麻烦点会加上交易费，那个在买或者卖算利润时减掉即可。

*/


// Handle extreme large K
int maxProfit_unlimited_greedy(vector<int>& prices) {
    int res = 0;
    for (int i = 1;  i < prices.size(); i++) {
        res += (prices[i] - prices[i - 1] > 0) * (prices[i] - prices[i - 1]);
    }
    return res;
}

class Solution {
public:
    int maxProfit(int K, vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
    
        // All the stock problems only have 3 states variable:
        // i.e: N (days), K (maximum transaction times), S(State: hold or not hold)
        // Since this problem K = 1, therefore, can remove K dimension.
        int N = prices.size();
        if (K >= N / 2) {
            return maxProfit_unlimited_greedy(prices);
        }

        int S = 2;
        vector<vector<vector<int>>> dp(N, vector<vector<int>>(K + 1, vector<int>(S, 0)));
        
        // When k = 0, no transaction allowed, maximum profit is always zero
        for (int i = 0; i < N; i++) {
            for (int k = 1; k <= K; k++) {
                if (i == 0) {
                    dp[i][k][0] = 0;
                    dp[i][k][1] = -prices[0];
                    continue;
                } 
                dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i]);
                dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i]);
            }
        }
        
        return dp[N - 1][K][0];           
    }
};
