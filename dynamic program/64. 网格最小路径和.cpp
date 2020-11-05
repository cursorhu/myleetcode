/*
64. 最小路径和
给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。

示例:

输入:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 7
解释: 因为路径 1→3→1→1→1 的总和最小。
*/

/*
题解：带加权的二维路径，且权值非负，只增不减
分解：
[i,j]处的路径和 = [i-1,j]的路径和+[i,j]值，或者[1,j-1]的路径和+[i,j]值
哪个小，选哪个
转移方程：
dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + a[i][j];
边界条件：
dp[0][j] = dp[0][j-1] + a[0][j];
dp[i][0] = dp[i-1][0] + a[i][0];

*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
    	if(grid.empty())
    		return 0;
    	int m = grid.size();
    	int n = grid[0].size();
    	vector<vector<int>> dp(m, vector<int>(n, 0));

    	//边界
    	dp[0][0] = grid[0][0];
    	for (int i = 1; i < m; i++) {
            dp[i][0] = dp[i-1][0] + grid[i][0]; 
        }
    	for (int j = 1; j < n; j++) {
            dp[0][j] = dp[0][j-1] + grid[0][j];
        }
        
        for (int i = 1; i < m; i++) {
  			for (int j = 1; j < n; j++) {
            	dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
        	}
  		}

  		return dp.back().back(); 
    }
};
