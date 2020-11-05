/* 674. 最长连续递增序列
给定一个未经排序的整数数组，找到最长且 连续递增的子序列，并返回该序列的长度。

连续递增的子序列 可以由两个下标 l 和 r（l < r）确定，
如果对于每个 l <= i < r，都有 nums[i] < nums[i + 1] ，
那么子序列 [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] 就是连续递增子序列。
*/

/* 说明： 可以说是最长上升序列--动态规划解法的简化版，
连续序列，只需要比较当前a[i]>a[i-1]即可，状态转移方程也只需要dp[i]和dp[i-1]
将每个位置i的结果还是存在dp[i]
最后遍历dp[i]取得最大值
*/

#include <vector>

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
    	if(nums.empty())
    		return 0;

    	int len = nums.size();

    	//初始化dp[]
    	vector<int> dp;
    	for(int i = 0; i < len; i++)
    		dp.push_back(1);

    	//遍历输入，更新dp[]
    	for(int i = 1; i < len; i++)
    	{
    		if(nums[i] > nums[i-1])
    			dp[i] = dp[i-1] + 1;
    		else
    			dp[i] = 1; //如果断开连续递增，要复位
    	}

    	//输出dp[]最大值
    	int max_dp = 0;
    	for(int i = 0; i < len; i++)
    	{
    		if(dp[i] > max_dp)
    			max_dp = dp[i];
    	}

    	return max_dp;
    }
};