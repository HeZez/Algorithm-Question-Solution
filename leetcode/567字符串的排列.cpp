/*
    给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。

    换句话说，第一个字符串的排列之一是第二个字符串的子串。

    示例1:
    输入: s1 = "ab" s2 = "eidbaooo"
    输出: True
    解释: s2 包含 s1 的排列之一 ("ba").


    示例2:
    输入: s1= "ab" s2 = "eidboaoo"
    输出: False


    注意：
    输入的字符串只包含小写字母
    两个字符串的长度都在 [1, 10,000] 之间
*/
/*
    和438题很想，依旧使用滑动窗口
*/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s1Len=s1.size();
        int s2Len=s2.size();
        if(s1Len>s2Len)
            return false;
        vector<int> hashTable(26,0); 
        for(int i=0;i<s1Len;i++)
            hashTable[s1[i]-'a']++;
        int l=0,count=0;
        for(int r=0;r<s2Len;r++)
        {
            hashTable[s2[r]-'a']--;
            if(hashTable[s2[r]-'a']>=0)
                count++;
            if(r>=s1Len)
            {
                hashTable[s2[l]-'a']++;
                if(hashTable[s2[l]-'a']>0)
                    count--;
                l++;
            }
            if(count==s1Len)
                return true;
        }
        return false;
    }
};