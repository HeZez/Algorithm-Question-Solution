/*
    在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。

    示例:
    输入: 

    1 0 1 0 0
    1 0 1 1 1
    1 1 1 1 1
    1 0 0 1 0

    输出: 4
*/
/*
    动态规划 dp[m][n]表示从[0][0]到[m][n]中的最大正方形
    递推方程 dp[i][j]=1+min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])
    
    这个递推方程为什么成立呢？ 首先这样考虑
    如果dp[i-1][j],dp[i][j-1],dp[i-1][j-1] 三者相等
    举个例子
    1 1 1
    1 1 1
    1 1 x
    x这个位置可1可0  如果这个位置是0，那么dp中这个位置也是0 因为包含0就不是正方形了
    dp[i-1][j],dp[i][j-1],dp[i-1][j-1]这三个位置都是2 x如果是1 那么结果就是dp[i-1][j-1]+1
    
    如果dp[i-1][j],dp[i][j-1],dp[i-1][j-1] 三者不相等
    x为0时没变化
    dp[i][j]一定取决于dp[i-1][j],dp[i][j-1],dp[i-1][j-1]三者中最小的那个
    
*/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty()||matrix[0].empty())
            return 0;
        int m=matrix.size();
        int n=matrix[0].size();
        int maxL=0;
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0) );
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
            {
                if(matrix[i-1][j-1]=='1')
                {
                    dp[i][j]=1+min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                    maxL=max(maxL, dp[i][j]);
                }
                    
            }
        return maxL*maxL;
    }
};