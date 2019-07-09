/*
    给定一个字符串 S 和一个字符串 T，计算在 S 的子序列中 T 出现的个数。

    一个字符串的一个子序列是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相对位置所组成的新字符串。（例如，"ACE" 是 "ABCDE" 的一个子序列，而 "AEC" 不是）

    示例 1:

    输入: S = "rabbbit", T = "rabbit"
    输出: 3
    解释:

    如下图所示, 有 3 种可以从 S 中得到 "rabbit" 的方案。
    (上箭头符号 ^ 表示选取的字母)

    rabbbit
    ^^^^ ^^
    rabbbit
    ^^ ^^^^
    rabbbit
    ^^^ ^^^
    示例 2:

    输入: S = "babgbag", T = "bag"
    输出: 5
    解释:

    如下图所示, 有 5 种可以从 S 中得到 "bag" 的方案。 
    (上箭头符号 ^ 表示选取的字母)

    babgbag
    ^^ ^
    babgbag
    ^^    ^
    babgbag
    ^    ^^
    babgbag
      ^  ^^
    babgbag
        ^^^
*/
/*
    按照样例的形式，这道题的意思应该是S有哪些子序列可以构成T
    不小心看到了评论，可以用dp解，自己想一想dp的具体形式吧
    这个问题要是从递归的角度来考虑，用dp[m][n]来记录结果 dp[i][j]表示长度为i的S和长度为j的T的不同子序列结果
    考虑第i位和第j位是否相等可以得到如下方程
    
    递归方程：
    if s[i]=t[j]:
        dp[i][j]=dp[i-1][j-1]+dp[i-1][j]    
    else:
        dp[i][j]=dp[i-1][j]
    直观意思就是如果这一位相等，那么不同子序列数就等于s t的前一位的匹配数量加上s前一位与t当前位匹配的个数
    
    初始状态 s长度+1为横坐标， t长度+1为纵坐标 dp[i][0]=1
*/
class Solution {
public:
    int numDistinct(string s, string t) {
        if(s.empty()||t.empty())
            return 0;
        vector<vector<long> > dp(s.size()+1, vector<long> (t.size()+1, 0));
        for(int i=0;i<dp.size();i++)
            dp[i][0]=1;
        for(int i=1;i<dp.size();i++)
        {
            for(int j=1;j<dp[0].size();j++)
            {
                if(s[i-1]==t[j-1])
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        return dp[s.size()][t.size()];
    }
};