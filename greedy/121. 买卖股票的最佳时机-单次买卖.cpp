
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
暴力枚举：因为买入卖出都是浮动的，导致二层枚举，可能不通过

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

/*
贪心算法:
不管全局最大最小，只管当前时刻的最大利润 = 当前值 - 最小值
只需遍历一次，每次更新最小值和最大利润差值，遍历完毕返回最大利润差值

注意：
* 贪心算法只适用特定问题，需要做归纳法证明其适用
* 一般涉及时间序列的最优解问题可以用贪心算法尝试
例如，一个人在总时间T内想做尽可能多的事，第i件件事需要时间Ti, 求最多能做多少件事N
和股票问题是一类： 有限的时间天数内，第i天股价为Vi，求最多能赚多少V
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
