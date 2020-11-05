/*

300. 最长上升子序列
给定一个无序的整数数组，找到其中最长上升子序列的长度。

示例:

输入: [10,9,2,5,3,7,101,18]
输出: 4 
解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
说明:

可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
你算法的时间复杂度应该为 O(n2) 。
进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?

*/



/* 说明： dp[i]为当前位置i的最大上升序列的长度 
   状态方程为： 如果当前位置成员nums[i]大于之前的某个成员nums[j], 
   则nums[i]可以合并到nums[j]处的上升序列dp[j]中，即：dp[i] = dp[j] + 1
   但是i左边有很多个j符合要求，要选最大的dp[i]
   二层循环实现:遍历i, 且找到符合条件的j，计算出dp[i]的操作。
   单次循环实现：找到dp[]的最大值。
*/

#include<algorithm>
#include <vector>

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        //输入判断，注意测试用例包含这个
        if(nums.empty()) 
            return 0;
        
        int len = nums.size();
        vector<int> dp;
        
        //初始化dp数组为1
        for(int i = 0; i < len; i++)
        {
            dp.push_back(1);
        }

        for(int i = 0; i < len; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(nums[j] < nums[i])
                	/* 同一个i,有多个j,有多次dp[i]更新成dp[j]+1，
                	要取最大的dp[i],每次更新前要和之前的dp[i]比较 */
                    dp[i] = max(dp[j] + 1, dp[i]); 
            }
        }

        /* 返回最大的dp: 遍历dp数组 */
        int max_dp = dp[0];
        for(int i = 0; i < len; i++)
        {
            if(max_dp < dp[i])
                max_dp = dp[i];
        }

        return max_dp;
    }
};