/*
    给定一个字符串数组 words，找到 length(word[i]) * length(word[j]) 的最大值，并且这两个单词不含有公共字母。你可以认为每个单词只包含小写字母。如果不存在这样的两个单词，返回 0。

    示例 1:
    输入: ["abcw","baz","foo","bar","xtfn","abcdef"]
    输出: 16 
    解释: 这两个单词为 "abcw", "xtfn"。

    示例 2:
    输入: ["a","ab","abc","d","cd","bcd","abcd"]
    输出: 4 
    解释: 这两个单词为 "ab", "cd"。

    示例 3:
    输入: ["a","aa","aaa","aaaa"]
    输出: 0 
    解释: 不存在这样的两个单词。
*/
/*
    关键点在与怎样快速判断两个字符串之间有没有公共字符
    如果可以判断两者之间有没有公共字符之后。 两两相乘 二重循环来找到最小值即可
    大佬在判断这一情况的时候，想到了bitmap+位运算 学到了
*/
class Solution {
public:
    int maxProduct(vector<string>& words) {
        if(words.empty())
            return 0;
        // 一个int 32位整数 可以用来记录26个字母哪个是否出现了 作为一个bitmap
        vector<int> bmap(words.size(), 0);
        int result=0;
        // 构造bitmap
        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<words[i].size();j++)
            {
                //这里的位运算为 或运算 
                bmap[i] |= 1<<(words[i][j]-'a');
            }
        }

        // 二重循环两两判断
        int a=0,b=0;
        for(int i=0;i<words.size()-1;i++)
        {
            for(int j=i+1;j<words.size();j++)
            {
                if((bmap[i] & bmap[j])==0)  // 注意这里== 的运算优先级比 & 高...  记得加括号
                {
                    a=words[i].size();
                    b=words[j].size();
                    result=max(result, a*b);
                }
            }
        }
        return result;
    }
};