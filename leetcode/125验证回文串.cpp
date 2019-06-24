/*
    给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

    说明：本题中，我们将空字符串定义为有效的回文串。

    示例 1:

    输入: "A man, a plan, a canal: Panama"
    输出: true
    示例 2:

    输入: "race a car"
    输出: false
*/
/*
    双指针，从两头向中间遍历，遇到非字母字符就跳过
    a-z ascii码 97-122
    A-Z ascii码 65-90
    0-9 ascii码 48-57
*/
class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty())
            return true;
        int r=s.size()-1;
        int l=0;
        while(l<r)
        { 
            while(l<r && !(s[l]>=97&&s[l]<=122) && !(s[l]>=65&&s[l]<=90) && !(s[l]>=48&&s[l]<=57))
                l++;
            while( l<r && !(s[r]>=97&&s[r]<=122) && !(s[r]>=65&&s[r]<=90) && !(s[r]>=48&&s[r]<=57) )
                r--;
            if(l<r)
            {
                // 全都转换成小写字母
                if(s[l]>=65&&s[l]<=90)
                    s[l]+=32;
                if(s[r]>=65&&s[r]<=90)
                    s[r]+=32;
                if(s[l++]!=s[r--])
                    return false;    
            }   
        }
        return true;
    }
};