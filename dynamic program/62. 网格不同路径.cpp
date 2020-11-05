/*
62. 不同路径
一个机器人位于一个 m x n 网格的左上角。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角。

问总共有多少条不同的路径？
*/

/*
题解：
跳台阶问题的二维版，动态规划
步骤分解：当前位置，可能是从上一个位置向右，或向下移动的
dp[i][j]记录从[0,0]可走到[i,j]位置的路径和
转移方程：dp[i][j] = dp[i-1][j] + dp[i][j-1]
边界：dp[0][j], dp[i][0]
dp[0][j] = dp[0][j-1];
dp[i][0] = dp[i-1][0];
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
    	//输入判断
    	if(m == 0 || n == 0)
    		return 0;

    	vector<vector<int>> dp(m, vector<int>(n,0));

    	//边界：靠墙了，都是同一条路
    	dp[0][0] = 1;
    	for (int i = 1; i < m; i++) {
            dp[i][0] = dp[i-1][0]; 
        }
    	for (int j = 1; j < n; j++) {
            dp[0][j] = dp[0][j-1];
        }
        
    	for (int i = 1; i < m; i++) {
  			for (int j = 1; j < n; j++) {
            	dp[i][j] = dp[i-1][j] + dp[i][j-1]; //两种可能的子路径都属于ij处总路径的子集
        	}
  		}

  		return dp.back().back();  
  	}
};