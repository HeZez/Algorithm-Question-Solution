/*
    给定三个字符串 s1, s2, s3, 验证 s3 是否是由 s1 和 s2 交错组成的。

    示例 1:

    输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
    输出: true
    示例 2:

    输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
    输出: false
*/
/*
    一开始的想法，s3逐位和s1 s2 对比，两个中有一个相同的就可以继续进行，去一个相同的字母
    继续对比，直到三个字符串都为空，或者有一位对不上
    但是这样有一个问题，就是如果s1 和s2的当前位都和s3的这一位相同时，不能确定具体选哪个一个，
    如果选错了，可能影响到最后的结果
    
    很惭愧，还是看了评论，知道了应该用动态规划来解
    dp[i,j]表示s1前i位，s2前j位，对于s3 i+j位能否符合交错字符串
    if(s1[i]==s3[i+j])
        dp[i,j]=d[i-1, j]
    if(s1[i]==s3[i+j])
        dp[i,j]=d[i, j-1]
*/
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size())
            return false;
        vector<vector<bool>> dp(s1.size()+1, vector<bool>(s2.size()+1, false));
        dp[0][0]=true;
        for(int i=0; i++<s1.size()&&dp[i-1][0]; )
            dp[i][0]=(s1[i-1]==s3[i-1]);
        
        for(int i=0; i++<s2.size()&&dp[0][i-1]; )
            dp[0][i]=(s2[i-1]==s3[i-1]);
            
        for(int i=1;i<=s1.size();i++)
        {
            for(int j=1;j<=s2.size();j++)
            {
                if(s1[i-1]==s3[i+j-2+1])
                    dp[i][j]=dp[i][j] || dp[i-1][j];
                if(s2[j-1]==s3[i+j-2+1])
                    dp[i][j]=dp[i][j] || dp[i][j-1];
            }
        }
        return dp[s1.size()][s2.size()];
    }
};