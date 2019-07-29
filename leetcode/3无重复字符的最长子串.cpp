/*
    给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
    示例 1:

    输入: "abcabcbb"
    输出: 3 
    解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
    示例 2:

    输入: "bbbbb"
    输出: 1
    解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
    示例 3:

    输入: "pwwkew"
    输出: 3
    解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
         请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

*/
/*
    用一个256的数组来模拟hash表，因为字符只有256个
    
    
    hash表记录的是某一个字符上一次出现的位置 key为字符的ascii码值， value为在字符串中最新的出现位置
    同时用一个left值记录当前无重复子串最左边的字符
    其实就是滑动窗口
    
    如果当前的字符是第一次出现或者上一次出现在left之前，也就是窗口外，可以记录这个结果
    
    如果当前字符重复出现，那么就把当前字符设置为left指针的位置，重新开始计算最长子串
    
    每一次访问记得更新当前字符出现的位置
    
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int result=0;
        int hash[256]={0};
        int length=s.length();
        for(int i=0;i<length;i++)
        {
            // 这个判断条件的意思是，如果这个字符第一次出现，或者这个字符上一次出现
            // 在当前子串开始位置之前，计算长度
            if(hash[s[i]]==0||hash[s[i]]<left)
            {
                result=max(result,i-left+1);
            }
            else
            {
                // 否则的话，记录当前子串最左的位置
                left=hash[s[i]];
            }
            hash[s[i]]=i+1;
        }
        return result;
    }
};