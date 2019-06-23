/*
    给你一个仅由大写英文字母组成的字符串，你可以将任意位置上的字符替换成另外的字符，总共可最多替换 k 次。在执行上述操作后，找到包含重复字母的最长子串的长度。

    注意:
    字符串长度 和 k 不会超过 104。

    示例 1:

    输入:
    s = "ABAB", k = 2

    输出:
    4

    解释:
    用两个'A'替换为两个'B',反之亦然。
    示例 2:

    输入:
    s = "AABABBA", k = 1

    输出:
    4

    解释:
    将中间的一个'A'替换为'B',字符串变为 "AABBBBA"。
    子串 "BBBB" 有最长重复字母, 答案为 4。

*/
/*
    滑动窗口，移动左指针的条件是r-l+1-maxCount>k ，这意味着当前窗口中字符数减去最多重复的字符数，结果比k大，
    也就无法通过修改k个字符来使整个窗口内的字符串全部重复
*/
class Solution {
public:
    int characterReplacement(string s, int k) {
        int sLen=s.size();
        //if(sLen<k)
        //    return 0;
        vector<int> hashTable(26, 0);
        int l=0,maxCount=0,result=0;
        for(int r=0;r<sLen;r++)
        {
            maxCount=max(++hashTable[s[r]-'A'], maxCount);
            if(r-l+1-maxCount>k)
            {
                hashTable[s[l++]-'A']--;
            }
            result=max(r-l+1, result);
        }
        return result;
    }
};