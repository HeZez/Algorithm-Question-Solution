/*
    实现 strStr() 函数。

    给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

    示例 1:

    输入: haystack = "hello", needle = "ll"
    输出: 2
    示例 2:

    输入: haystack = "aaaaa", needle = "bba"
    输出: -1
    说明:

    当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。

    对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。

*/
/*
    直接的想法就是按位对比，注意，只需要对比前haystack.size()-needle.size()+1位即可
    如果needle的长度大于haystack则不存在结果
    我的想法就是暴力匹配，但是在最后结果上还比挺多人都快
    
    按照评论区大佬的说法，更高级的解法是KMP算法
    
*/

class Solution {
public:
    /*
    // 暴力匹配
    int strStr(string haystack, string needle) {
        if(needle.size()==0)
            return 0;
        if(needle.size()>haystack.size())
            return -1;
        int index=0;
        int res=-1;
        for(int i=0;i<=haystack.size()-needle.size();i++)
        {
            index=0;
            while(index<needle.size())
            {
                if(needle[index]!=haystack[i+index])
                    break;
                index++;
                
            }
            if(index==needle.size())
            {
                res=i;
                break;
            }
        }
        return res;
    }
    */
    
    /*
    // KMP 算法实现
    int strStr(string haystack, string needle) 
    {
        if(needle.empty())
            return 0;
        vector<int> next=getNext(needle);
        int i=0,j=0;
        while(i<haystack.size()&&j<needle.size())
        {
            if(j==0||haystack[i]==needle[j])
            {
                if(j==0)
                {
                    if(haystack[i]==needle[j])
                    {
                        i++;
                        j++;
                    }
                    else
                        i++;
                }
                else
                {
                    i++;
                    j++;
                }
            }
            else
                j=next[j-1];
        }
        if(j==needle.size())
            return i-j;
        return -1;
    }
    
    // KMP算法中需要匹配字符串的next数组
    vector<int> getNext(string needle)
    {
        vector<int> next(needle.size(), 0);
        int i=1,j=0;
        while(i<needle.size())
        {
            if(j==0||needle[i]==needle[j])
            {
                if(j==0)
                {
                    if(needle[i]==needle[j])
                        next[i++]=++j;
                    else
                        next[i++]=j;
                }
                else
                    next[i++]=++j;
            }
            else
            {
                j=next[j-1];
            }
        }
        return next;
    }
    */
    
    // 对next数组优化的kmp算法
    // KMP 算法实现
    int strStr(string haystack, string needle) 
    {
        if(needle.empty())
            return 0;
        vector<int> next=getNext(needle);
        /*
        for(auto i:next)
            cout<<i<<",";
        cout<<endl;
        */
        int i=0,j=0;
        int sizeH=haystack.size();
        int sizeN=needle.size();
        while( i<sizeH && j<sizeN )
        {
            if( j==-1||haystack[i]==needle[j])
            {
                i++;
                j++;
            }
            else
            {
                j=next[j];
                /*
                这里很奇怪 j=-1 needle.size()=2  j < needle.size()的结果居然是false 只好用一个变量来替换一下 
                cout<<j<<","<<needle.size()<<"qwe"<<endl;
                int size=needle.size();
                cout<<( j < size )<<"hjk"<<endl;
                cout<<(-1<2)<<"hjk"<<endl;
                */
            }
        }
        // cout<<i<<","<<j<<"dasdsad"<<endl;
        if(j==needle.size())
            return i-j;
        return -1;
    }
    
    // KMP算法中需要匹配字符串的next数组  优化一下，采用j=-1为初始值，简化编程
    vector<int> getNext(string needle)
    {
        vector<int> next(needle.size(), 0);
        // 这里的j=-1, i可以从0开始 编程更方便
        int i=0,j=-1;
        next[0]=-1;
        while(i<needle.size()-1)
        {
            if(j==-1||needle[i]==needle[j])
            {
                next[++i]=++j;
            }
            else
            {
                j=next[j];
            }
        }
        return next;
    }
};