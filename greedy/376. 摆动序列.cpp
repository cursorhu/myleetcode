/*376. 摆动序列

如果连续数字之间的差严格地在正数和负数之间交替，则数字序列称为摆动序列。
第一个差（如果存在的话）可能是正数或负数。少于两个元素的序列也是摆动序列。
例如， [1,7,4,9,2,5] 是一个摆动序列，因为差值 (6,-3,5,-7,3) 是正负交替出现的。
相反, [1,4,7,2,5] 和 [1,7,4,5,5] 不是摆动序列，第一个序列是因为它的前两个差值都是正数，第二个序列是因为它的最后一个差值为零。
给定一个整数序列，返回作为摆动序列的最长子序列的长度。 
通过从原始序列中删除（或提取）符合条件的元素来获得子序列，并保持其原始顺序。

示例 1:
输入: [1,7,4,9,2,5]
输出: 6 

*/

/*
题解一：动态规划
最长XX子序列问题，都容易想到动态规划
本题是求最长“摇摆”子序列的长度，注意子序列是从原序列“非连续”提取的
求解的过程类似最长上升子序列，不过是需要判断两个序列

考虑子序列最后一个元素：
1.若差为负，则前面的（不一定连续）必须差为正
2.若差为正，则前面的必须差为负

对于原序列第i个元素
1.若被提取到子序列，则满足上述条件
2.若没被提取，遍历其它元素

用二维dp表示子序列长度
dp[i][0]表示位置i前面，差为负
dp[i][1]表示位置i前面，差为正
*/

#include <algorithm>

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
    	
    	if(nums.empty())
    		return 0;
    	
    	//dp为最长摆动子序列的长度，先定义成输入序列长度
    	vector< vector<int> > dp(nums.size(), vector<int>(2, 0));

    	//边界
    	dp[0][0] = 1;
    	dp[0][1] = 1;

    	//迭代dp
    	for (int i = 1; i < nums.size(); ++i)
    	{
    		if(nums[i]-nums[i-1] > 0)
    			dp[i][1] = max(dp[i-1][0] + 1, dp[i-1][1]); 
    		else if(nums[i]-nums[i-1] < 0)
    			dp[i][0] = max(dp[i-1][1] + 1, dp[i-1][0]); 
    		else
    		{
    			dp[i][0] = dp[i-1][0];
    			dp[i][1] = dp[i-1][1];
    		}
    	}

    	return max(dp[dp.size()-1][0], dp[dp.size()-1][1]);

    }
};

/*
* 题解二：优化的dp
有up/down记录前一次序列变化是正还是负
连续上升和下降都不计数，因此最终序列一定是up,down,up,down...,或者down,up,down,up... 持平和连续升降的成员不需计数
*/
#include <algorithm>
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() < 2)
            return nums.size();

        int down = 1, up = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1])
                up = down + 1;
            else if (nums[i] < nums[i - 1])
                down = up + 1;
        }
        return max(down, up);
    }
};

/*
题解三：贪心：局部更新，遍历之后直接得到全局结果
每个成员的趋势有三种状态;
1.上升
2.下降
3.持平

而‘摇摆’表示1和2的组合，用两个变量保存两个状态，可以判断是否摇摆
贪心的每一步迭代状态即可。
*/

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        int curDiff = 0; // 当前一对差值
        int preDiff = 0; // 前一对差值
        int result = 1;  // 记录峰值个数，序列默认序列最右边有一个峰值
        for (int i = 1; i < nums.size(); i++) {
            curDiff = nums[i] - nums[i - 1];
            // 出现升降变化，注意等号是上一次持平
            if ((curDiff > 0 && preDiff <= 0) || (curDiff < 0 && preDiff >= 0)) {
                result++;
                preDiff = curDiff; //这个状态转换是关键
            }
        }
        return result;
    }
};
