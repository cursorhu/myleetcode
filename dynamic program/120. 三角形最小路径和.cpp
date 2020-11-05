
/*
120. 三角形最小路径和
给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。

相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。

 

例如，给定三角形：

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
*/


/*题解： 
和网格的最小路径和没什么区别，注意边界和转移方向即可
三角形可以画成这样，下降只能选正下或者右下。
[
[2],
[3,4],
[6,5,7],
[4,1,8,3]
]

*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
    	if(triangle.empty())
    		return 0;

    	int m = triangle.size();
    	int n = triangle[m-1].size(); //以最长边分配矩形dp, 尽管只用其中的三角形空间

    	//初始化dp
    	vector<vector<int>> dp(m,vector<int>(n,0));
    	
    	//边界: 起点+左边+右边，右边放在主体循环做
    	dp[0][0] = triangle[0][0];
    	for(int i = 1; i < m; i++)
    		dp[i][0] = dp[i-1][0] + triangle[i][0];
    
    	//主体
    	for(int i = 1; i < m; i++)
    	{
    		for(int j = 1; j < triangle[i].size(); j++) //注意这里不要越界，j最大值是按当前行的长度，动态分配的
    		{
    			if(j == triangle[i].size() - 1) //斜边位置，只可能选左上
    				dp[i][j] = dp[i-1][j-1] + triangle[i][j];
    			else
    				dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]) + triangle[i][j];
    		}
    	}

    	//返回dp
    	int min_dp = dp[m-1][0]; //注意初值选取，要在合理的dp域内选一个。
    	for(int j = 1; j < n; j++)
    	{
    		if(dp[m-1][j] < min_dp)
    			min_dp = dp[m-1][j];
    	}
    	return min_dp;
    }
};