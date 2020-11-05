/*63. 不同路径 II
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？



网格中的障碍物和空位置分别用 1 和 0 来表示。

说明：m 和 n 的值均不超过 100。

示例 1:

输入:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
输出: 2
解释:
3x3 网格的正中间有一个障碍物。
从左上角到右下角一共有 2 条不同的路径：
1. 向右 -> 向右 -> 向下 -> 向下
2. 向下 -> 向下 -> 向右 -> 向右
*/


/*
题解：
网格不同路径的带条件版
步骤分解：当前位置，可能是从上一个位置向右，或向下移动的
dp[i][j]记录从[0,0]可走到[i,j]位置的路径和
对障碍物的处理： [i][j]处是障碍物，则dp[i][j]=0，对其右侧和下侧的dp，按常规转移方程递推，无需特殊处理
转移方程：dp[i][j] = dp[i-1][j] + dp[i][j-1]
边界：dp[0][j], dp[i][0]
dp[0][j] = dp[0][j-1];
dp[i][0] = dp[i-1][0];
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    	//输入判断
    	if(obstacleGrid.empty())
    		return 0;
    	int m = obstacleGrid.size();
    	int n = obstacleGrid[0].size();
    	vector<vector<int>> dp(m, vector<int>(n,0));

    	//边界
    	if(obstacleGrid[0][0] == 1) //注意双等号！
    		dp[0][0] = 0;
    	else
    		dp[0][0] = 1;

    	for (int i = 1; i < m; i++) {
    		if(obstacleGrid[i][0] == 1)
    			dp[i][0] = 0;
    		else
            	dp[i][0] = dp[i-1][0]; 
        }
    	for (int j = 1; j < n; j++) {
    		if(obstacleGrid[0][j] == 1)
    			dp[0][j] = 0;
    		else
            	dp[0][j] = dp[0][j-1];
        }
        
        //主体
    	for (int i = 1; i < m; i++) {
  			for (int j = 1; j < n; j++) {
  				if(obstacleGrid[i][j] == 1) //注意双等号！
  					dp[i][j] = 0;
  				else
            		dp[i][j] = dp[i-1][j] + dp[i][j-1];
        	}
  		}

  		return dp.back().back(); 
    }
};
