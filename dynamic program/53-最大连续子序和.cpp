/*
53. 最大连续子序和
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4]
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
进阶:
如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
*/

/* 说明： 
连续序列的动态规划都只需要管理前一相邻成员
dp[i]= max(dp[i-1] + nums[i], dp[i-1])
将每个位置i的结果还是存在dp[i]
最后遍历dp[i]取得最大值
*/

#include<algorithm>

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    	if(nums.empty())
    		return 0;

    	int len = nums.size();

    	//初始化dp[]
    	vector<int> dp;
    	for(int i = 0; i < len; i++)
    		dp.push_back(0);

    	dp[0] = nums[0]; //边界dp[0]单独更新

    	//遍历输入，更新dp[]
    	for(int i = 1; i < len; i++)
    	{
    		//dp[i] = max(dp[i-1] + nums[i], dp[i-1]); //注意这种是不连续和
    		dp[i] = max(dp[i-1] + nums[i], nums[i]); //当前数为主体，考虑要不要丢掉之前的dp[i]
    	}

    	//输出dp[]最大值
    	int max_dp = dp[0]; //注意max_dp初值从dp[]中取，不能随意赋值0
    	for(int i = 0; i < len; i++)
    	{
    		if(dp[i] > max_dp)
    			max_dp = dp[i];
    	}

    	return max_dp;
    }
};