/*
    给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。

    返回 s 所有可能的分割方案。

    示例:
    输入: "aab"
    输出:
    [
      ["aa","b"],
      ["a","a","b"]
    ]
*/
/*
    要求输出所有结果，那就回溯
    关键是如何判断一个字符串是回文串
    暴力判断一个字符串从头开始的所有情况，两端对比？感觉有点慢
*/
class Solution {
public:
    vector<vector<string>> results;
    void partitionCore(string s, vector<string>& temp)
    {
        // 递归边界
        if(s.empty())
        {
            results.push_back(temp);
            return ;
        }
        // 判断从当前字符串头开始的回文串
        for(int i=0;i<s.size();i++)
        {
            // substr方法的参数，第一个是pos，开始的位置，第二个参数时截取的字符数
            string t=s.substr(0, i+1);
            //判断回文
            bool flag=true;
            for(int j=0, k=t.size()-1; j<=k; j++,k--)
            {
                if(t[j]!=t[k])
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
            {
                // 回文
                temp.push_back(t);
                partitionCore(s.substr(i+1, s.size()-i-1), temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        if(s.empty())
            return results;
        vector<string> temp;
        partitionCore(s, temp);
        return results;
    }
};