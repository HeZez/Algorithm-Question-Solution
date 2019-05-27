/*
    题目描述：
    给定两个单词 word1 和 word2，计算出将 word1 转换成 word2 所使用的最少操作数 。

    你可以对一个单词进行如下三种操作：

    插入一个字符
    删除一个字符
    替换一个字符
    示例 1:

    输入: word1 = "horse", word2 = "ros"
    输出: 3
    解释: 
    horse -> rorse (将 'h' 替换为 'r')
    rorse -> rose (删除 'r')
    rose -> ros (删除 'e')
    示例 2:

    输入: word1 = "intention", word2 = "execution"
    输出: 5
    解释: 
    intention -> inention (删除 't')
    inention -> enention (将 'i' 替换为 'e')
    enention -> exention (将 'n' 替换为 'x')
    exention -> exection (将 'n' 替换为 'c')
    exection -> execution (插入 'u')
*/

/*
    这个问题中，所有的操作都是可以在任意位置进行的
    经过评论区大佬的分析，动态规划在分析时子问题分了三种情况
    1.w1[0:i-1]到w2[0:j-1]需要k步，那么w1[0:i]到w2[0:j]需要多少步  如果w1[i]=w2[i] 那么就是k步  如果不一样就进行一次替换 k+1次
    2.w1[0:i-1]到w2[0:j]需要k步 w1[0:i]到w2[0:j]需要多少步  把w1[i]删掉即可 k+1步
    3.w1[0:i]到w2[0:j-1]需要k步  w1[0:i]到w2[0:j]需要多少步  在w1后面加上w2[j]即可 k+1步
    结果是这三种情况中最小的那个
    用一个矩阵记录结果 dp[m][n] 表示长度为m n 的两个字符串的编辑长度
    
    dp[m][n]=min(dp[m-1][n]+1, dp[m][n-1]+1, dp[m][n])  if s1[m]==s2[n]
            =min(dp[m-1][n]+1, dp[m][n-1]+1, dp[m][n]+1)  if s1[m]!=s2[n]
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        // 特殊情况
        if(m<=0||n<=0)
            return m>n?m:n;
        int **dp=new int*[m+1];
        for(int i=0;i<m+1;i++)
            dp[i]=new int[n+1];
        //初始化初值
        for(int i=1;i<m+1; i++)
            dp[i][0]=i;
        for(int i=1;i<n+1;i++)
            dp[0][i]=i;
        dp[0][0]=0;
        for(int i=1;i<m+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                if(word1[i-1]==word2[j-1])
                {
                    dp[i][j]=min(dp[i-1][j-1], min(dp[i][j-1]+1 ,dp[i-1][j]+1));
                }
                else
                    dp[i][j]=min(dp[i-1][j-1]+1, min(dp[i][j-1]+1 ,dp[i-1][j]+1));
            }
        }
        return dp[m][n];
    }
};