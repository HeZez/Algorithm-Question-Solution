/*
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
    经典动态规划 二维数组 dp(m,n)记录从出发点到（m,n）的最小路径和
    dp方程为 dp(m,n)=min(dp(m-1,n)+grid(m,n), dp(m,n-1)+grid(m,n))
    初始值dp(0,0)=0  网络只有一行或一列的时候值很容易求得
    
    评论区大佬的做法也主要是在空间复杂度上做出优化
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if(m==0||n==0)
            return 0;
        int **dp=new int*[m];
        for(int i=0;i<m;i++)
            dp[i]=new int[n];
        //先初始化一部分dp矩阵值
        /*
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0||j==0)
                {
                    if(i==0&&j==0)
                        dp[i][j]=grid[0][0];
                    else if(i==0)
                        dp[i][j]=grid[i][j]+dp[i][j-1];
                    else if(j==0)
                        dp[i][j]=grid[i][j]+dp[i-1][j];
                }
                else
                    dp[i][j]=min(dp[i-1][j]+grid[i][j], dp[i][j-1]+grid[i][j]);
            }
        }
        */
        
        
        dp[0][0]=grid[0][0];
        for(int i=1;i<m;i++)
        {
            dp[i][0]=grid[i][0]+dp[i-1][0];
        }
        for(int i=1;i<n;i++)
        {

            dp[0][i]=grid[0][i]+dp[0][i-1];
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
                dp[i][j]=min(dp[i-1][j]+grid[i][j], dp[i][j-1]+grid[i][j]);
        }
        
        return dp[m-1][n-1];
    }
};