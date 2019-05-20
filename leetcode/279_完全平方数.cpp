class Solution {
/*
题目描述：
    给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。
    示例 1:
    输入: n = 12
    输出: 3 
    解释: 12 = 4 + 4 + 4.
    示例 2:
    输入: n = 13
    输出: 2
    解释: 13 = 4 + 9.
*/
    
/*
    有人给出过用广搜来寻找最短路径的方法
    对于动态规划的思路有人给出，具体递推方程是这样的
    f(n)=1+min[f(n-1^2),f(n-2^2),f(n-3^2).....f(n-k^2)]  k为符合要求的最大值 k^2<=n
    f(0)=0
*/

public:
    int numSquares(int n) {
        vector<int> f(n+1, 0);
        for(int i=1;i<n+1;i++)
        {
            int minV=INT_MAX;
            for(int j=1;j*j<=i;j++)
            {
                minV=min(minV,f[i-j*j]);
            }
            f[i]=minV+1;
        }
       
        return f[n];
    }
};