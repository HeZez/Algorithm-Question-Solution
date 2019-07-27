/*
    给定一个字符串 s，你可以通过在字符串前面添加字符将其转换为回文串。找到并返回可以用这种方式转换的最短回文串。

    示例 1:

    输入: "aacecaaa"
    输出: "aaacecaaa"
    示例 2:

    输入: "abcd"
    输出: "dcbabcd"
*/

/*
    思路还是很清晰的，只要找到从头开始最长的回文串，之后把后面不回文那部分翻转过来接到前面就行了
    关键是如何高效判断回文， 直接首尾向中间对比会超时
    
    官方题解中的暴力法效率比我写的暴力方法高一些，官方题解中直接把原字符串翻转
    之后比对原字符串s和反转字符串rev中开头和末尾的子串是否相同，c++里也可以想python一样，用substr实现类似切片的操作
    并使用==直接对比子串，这样的暴力方法效率高一些
    
    KMP算法:
    效率更高的是根据KMP算法来解决问题，巧妙地把找回文的那一部分转换成了KMP算法中的求前后缀问题
    比如s=abbac rev=cabba  把这两个字符串进行拼接 形成新的一个字符串 abbac#cabba
    这里中间加了一个#是为了防止出现aaaa这样的情况 全a 在拼接之后变成了aaaaaaaa，无法具体区分，所以加了一个#来分割
    
    这样只要求str_new=abbac#cabba的next数组，就可以得到str_new的后缀和前缀的最长匹配
    而这个最长匹配的长度就是源字符串中最长回文部分的长度
    
*/
class Solution {
public:
    string shortestPalindrome(string s) {
        /*
        // 自己的暴力算法，判断回文的方法是自己写的，首尾对比，效率较低
        string tempS="";
        for(int i=0;i<s.size();i++)
        {
            //tempS=s.substr(s.begin(), s.begin()+(s.size()-i));
            tempS=s.substr(0, s.size()-i);
            if(isPalindrome(tempS))
                break;
        }
        int length=tempS.size();
        // string part=s.substr(s.begin()+tempS.size(), s.end());
        string part=s.substr(tempS.size(), s.size()-tempS.size());
        reverse(part.begin(), part.end());
        string res=part+s;
        return res;
        */
        
        /*
        // 官方题解的暴力方法
        // 但是这个官方暴力题解现在也不过了全是"aaaaaaaaa"的那个样例了
        string rev(s);
        reverse(rev.begin(), rev.end());
        int length=0;
        for(int i=0;i<s.size();i++)
        {
            if(s.substr(0, s.size()-i)==rev.substr(i, rev.size()))
                return rev.substr(0,i)+s;
        }
        return "";
        */
        
        // 基于KMP算法的方法
        string rev(s);
        reverse(rev.begin(),rev.end());
        string str_new=s+"#"+rev;
        vector<int> next(str_new.size(), 0);
        next[0]=0;
        int i=1,j=0;
        // 这里的next数组求法是原始的
        // 在正常的KMP算法实现中，next数组一般会进行一位偏移，那样在编程的时候更方便一些
        while(i<str_new.size())
        {
            if(j==0 || str_new[i]==str_new[j])
            {
                if(j==0)
                {
                    if(str_new[i]==str_new[j])
                        next[i++]=++j;
                    else
                        next[i++]=j;
                }
                else
                    next[i++]=++j;
            }
            else
                j=next[j-1];
        }
        // 这个next数组最后一位存的就是s的后缀与rev前缀中最长的匹配长度，也就是s中最长的回文部分长度
        return rev.substr(0,rev.size()-next[str_new.size()-1])+s;
        
    }
    
    /*
    // 自己的低效率回文判断
    bool isPalindrome(string s)
    {
        int i=0,j=s.size()-1;
        while(i<=j)
        {
            if(s[i++]!=s[j--])
                return false;
        }
        return true;
    }
    */
};