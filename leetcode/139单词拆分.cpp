/*
    给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。

    说明：

    拆分时可以重复使用字典中的单词。
    你可以假设字典中没有重复的单词。
    示例 1：

    输入: s = "leetcode", wordDict = ["leet", "code"]
    输出: true
    解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
    示例 2：

    输入: s = "applepenapple", wordDict = ["apple", "pen"]
    输出: true
    解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
         注意你可以重复使用字典中的单词。
    示例 3：

    输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
    输出: false
*/
/*
    树搜索， bfs和dfs应该都可解  
    
    其实是动态规划
    状态转移方程  要有两个指针 i和j
    i表示当前位，j表示当前单词开始的位置
    于是 dp[i]=dp[j]&&(s[j:i] is in dict)
    dp[0]=true
*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.empty())
            return true;
        vector<bool> dp(s.size()+1, false);
        int i=1,j=0;
        dp[0]=true;
        for(int i=1;i<s.size()+1;i++)
        {
            for(int j=0;j<i;j++)
            {
                string temp=s.substr(j, i-j);
                if(dp[j]&&(find(wordDict.begin(), wordDict.end(), temp)!=wordDict.end()))
                {
                    dp[i]=true;
                    break;
                }

            }
        }
       
        return dp[s.size()];
    }
};