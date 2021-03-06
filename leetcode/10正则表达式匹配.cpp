/*
    给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。

    '.' 匹配任意单个字符
    '*' 匹配零个或多个前面的那一个元素
    所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。

    说明:

    s 可能为空，且只包含从 a-z 的小写字母。
    p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。
    示例 1:

    输入:
    s = "aa"
    p = "a"
    输出: false
    解释: "a" 无法匹配 "aa" 整个字符串。
    示例 2:

    输入:
    s = "aa"
    p = "a*"
    输出: true
    解释: 因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
    示例 3:

    输入:
    s = "ab"
    p = ".*"
    输出: true
    解释: ".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
    示例 4:

    输入:
    s = "aab"
    p = "c*a*b"
    输出: true
    解释: 因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。
    示例 5:

    输入:
    s = "mississippi"
    p = "mis*is*p*."
    输出: false
*/

/*
    状态转换
    正则表达式中主要有两个特殊字符 .和*
    .就是匹配任意字符很直接
    *的话会出现几种情况
    
    第一种方法是基于递归的暴力解法，思路就是只看当前这一位，如果只是一般情况，正常匹配即可
    如果当前位后面跟着* 递归的话只看当前位，对于这个带星的有两种选择匹配一次，或者跳过这个带*的部分
    
    
    第二种高效一些的解决这一问题的过程。主要应用了动态规划，感觉这一类字符串的问题一般都会用动态规划或者滑动窗口
    dp[i][j] i表示字符串长度，j表示正则表达式长度 dp[i][j]表示长度为i的s和长度为j的p能否匹配成功
    状态转移方程：
    dp[i][j]=dp[i-1][j-1]&&s[i]==p[j] if p[j]!=*
    
    p[j]是*的时候有两种情况 分别对应*这部分跳过或者带*的匹配一次
    dp[i][j]=dp[i][j-2]||dp[i][j-1]  if p[j]==*
*/
class Solution {
public:
    
    bool isMatch(string s, string p) {
        /*
        // 递归暴力方法，穷举所有可能
        // 递归边界，正则表达式为空，字符串也为空的时候，匹配成功，
        // 但是字符串为空，正则表达式不为空的时候是可能匹配成功的，这个要注意 例如“”和“a*”，只要带星的匹配0次即可
        if(p.empty())
            return s.empty();
        if(p.size()>=2&&p[1]=='*')
        {
            // 存在* 两种情况，
            // 1 是当前位匹配，则字符串步进一位，正则表达式不同
            // 2 是直接跳过正则表达式中带*的这一部分，s不动
            return (!s.empty()&&(s[0]==p[0]||p[0]=='.')&&isMatch(s.substr(1), p)) 
                || isMatch(s, p.substr(2));
               
        }
        // 不存在*的时候， 要求当前位，和下一位都能匹配的上
        else
        return !s.empty()&&(s[0]==p[0]||p[0]=='.') && isMatch(s.substr(1), p.substr(1));
    */
        
        
        // 动态规划
        vector<vector<bool>> dp(s.size()+1, vector<bool>(p.size()+1, false));
        dp[0][0]=true;
        // 先处理边界值  也就是当前正则表达式和空字符串之间的匹配关系
        for(int i=1;i<=p.size();i++)
        {
            if(p[i-1]!='*')
                dp[0][i]=false;
            else
                dp[0][i]=dp[0][i-2];
        }
        for(int i=1;i<=s.size();i++)
        {
            for(int j=1;j<=p.size();j++)
            {
                if(p[j-1]!='*')
                    dp[i][j]=dp[i-1][j-1]&&(p[j-1]==s[i-1]||p[j-1]=='.');
                else
                {
                    //  如果p的当前位是* 那么就看s当前字符和*前面的字符是否一致
                    //  如果一致则*可能匹配1次或多次
                    //  如果*前面是‘.’ 则可以匹配0次 1次 或多次
                    //  这几种情况都要考虑
                    //  dp[i-1][j]表示匹配多次，即j不动 i步进一位
                    //  dp[i][j-2]表示匹配0次
                    if(p[j-2]==s[i-1]||p[j-2]=='.')
                    {
                        // 如果*前面的字符和s中的当前字符能够匹配上，可以选择匹配0次或者多次
                        dp[i][j]=dp[i-1][j]||dp[i][j-2];
                    }
                    else
                    {
                        // 否则匹配不上的话，只能选择匹配0次
                         dp[i][j]=dp[i][j-2];
                    }
                }
            }
        }
        return dp[s.size()][p.size()];
    }
};