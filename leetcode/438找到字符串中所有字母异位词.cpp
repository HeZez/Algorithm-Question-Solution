/*
    给定一个字符串 s 和一个非空字符串 p，找到 s 中所有是 p 的字母异位词的子串，返回这些子串的起始索引。

    字符串只包含小写英文字母，并且字符串 s 和 p 的长度都不超过 20100。

    说明：

    字母异位词指字母相同，但排列不同的字符串。
    不考虑答案输出的顺序。
    示例 1:

    输入:
    s: "cbaebabacd" p: "abc"

    输出:
    [0, 6]

    解释:
    起始索引等于 0 的子串是 "cba", 它是 "abc" 的字母异位词。
    起始索引等于 6 的子串是 "bac", 它是 "abc" 的字母异位词。
     示例 2:

    输入:
    s: "abab" p: "ab"

    输出:
    [0, 1, 2]

    解释:
    起始索引等于 0 的子串是 "ab", 它是 "ab" 的字母异位词。
    起始索引等于 1 的子串是 "ba", 它是 "ab" 的字母异位词。
    起始索引等于 2 的子串是 "ab", 它是 "ab" 的字母异位词。

*/
/*
    滑动窗口，窗口大小就是p字符串的长度，关键是如何判断窗口中的字符串是p的字母异位词
    判断方法：
*/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if(s.size()<p.size())
            return res;
        int sLen=s.size();
        int pLen=p.size();
        // 用一个长度为26的数组来模拟hash表
        vector<int> hashTable(26, 0);
        for(int i=0;i<pLen;i++)
        {
            hashTable[p[i]-'a']++;
        }
        
        int l=0, r=l+pLen-1;
        int count=0;   // count用来记录窗口中符合要求的元素个数
        // 固定窗口长度
        for(int r=0;r<sLen;r++)
        {
            hashTable[s[r]-'a']--;
            if(hashTable[s[r]-'a']>=0)
                count++;
            if(r>pLen-1)
            {
                // 当r>pLen-1的时候，窗口开始整体移动
                hashTable[s[l]-'a']++;    // 当前left即将被移出窗口，还原hash
                // 这里为什么这样判断呢？ 按照这种方法，如果是字母异位词
                // 完全匹配时hash表中应该是全0的，这里在加一之后，变成了大于0，说明count应该减一，
                // 匹配上的字母少了一个
                if(hashTable[s[l]-'a']>0)    
                    count--;
                l++;   
            }
            if(count==pLen)
                res.push_back(l);
        }
        return res;
    }
};