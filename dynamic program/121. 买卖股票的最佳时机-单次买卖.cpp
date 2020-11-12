
/*
121. 买卖股票的最佳时机
给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
如果你最多只允许完成一笔交易（即买入和卖出一支股票一次），设计一个算法来计算你所能获取的最大利润。
注意：你不能在买入股票前卖出股票。


示例 1:

输入: [7,1,5,3,6,4]
输出: 5
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。

*/


/*
暴力枚举：
class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	if(prices.empty())
    		return 0;

    	int max = 0;
    	for(int i = 0; i < prices.size(); i++)
    		for(int j = i+1; j < prices.size(); j++)
    			if(prices[j]-prices[i] > max)
    				max=prices[j]-prices[i];

    	return max;
    }
};
*/

/*因为买入卖出都是浮动的，导致二层枚举
用贪心算法的思想，不管全局最大最小，只管当前时刻的最大利润 = 当前值 - 最小值
只需遍历一次，每次更新最小值和最大利润差值，遍历完毕返回最大利润差值
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	if(prices.empty())
    		return 0;

    	int max_profit = 0;
    	int min_price = INT_MAX; //要求最小，初始化成int最大值
    	for(int i = 0; i < prices.size(); i++)
    	{
    		//更新最小值
    		if(prices[i] < min_price)
    			min_price = prices[i];
    		
    		//更新最大利润
    		if(prices[i] - min_price > max_profit)
    			max_profit = prices[i]-min_price;
    	}

    	return max_profit;
    }
};

/*
按照动态规划的思想来思考这道问题。

状态
有 买入（buy） 和 卖出（sell） 这两种状态。

转移方程
对于买来说，买之后可以卖出（进入卖状态），也可以不再进行股票交易（保持买状态）。

对于卖来说，卖出股票后不在进行股票交易（还在卖状态）。

只有在手上的钱才算钱，手上的钱购买当天的股票后相当于亏损。也就是说当天买的话意味着损失-prices[i]，当天卖的话意味着增加prices[i]，当天卖出总的收益就是 buy+prices[i] 。

所以我们只要考虑当天买和之前买哪个收益更高，当天卖和之前卖哪个收益更高。

buy = max(buy, -price[i]) （注意：根据定义 buy 是负数）
sell = max(sell, prices[i] + buy)
*/

/*
class Solution {
public:    
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1)
            return 0;
        
        int buy = -prices[0];
        int sell = 0;
        for(int i = 1; i < prices.size(); i++) {
            buy = max(buy, -prices[i]);
            sell = max(sell, prices[i] + buy);
        }
        return sell;
    }
};
*/