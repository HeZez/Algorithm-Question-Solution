/*
    给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字母的最小子串。

示例：

输入: S = "ADOBECODEBANC", T = "ABC"
输出: "BANC"
说明：

如果 S 中不存这样的子串，则返回空字符串 ""。
如果 S 中存在这样的子串，我们保证它是唯一的答案。

*/
/*
    滑动窗口：找到一个最小的窗口，可以包含T中的所有字母,需要记录窗口位置
    用一个长度为256的数组模拟Hash表
*/
    
class Solution {
public:
    string minWindow(string s, string t) {
        int sLen=s.size();
        int tLen=t.size();
        vector<int> hashTable(256, 0);
        for(int i=0;i<tLen;i++)
            hashTable[t[i]]++;
        int l=0,count=tLen, max=sLen+1;
        string res="";
        for(int r=0;r<sLen;r++)
        {
            
            hashTable[s[r]]--;
            
            if(hashTable[s[r]]>=0)
                count--;
            // 为什么整个过程中没有count加一的步骤呢？
            // 仔细分析一下整个过程
            // 我觉得可以这么认为，这个count只是在判定第一个符合要求的子串的时候有用
            // 在接下来的过程中不起作用
            // 这种滑动窗口+计数的方法真的是很巧妙，我一时理解不太上去，还是需要更多的练习
            /*
                为什么这里count不需要++操作，注意这里左指针移动的条件
                是要hash[s[l]]<0才能移动，整个hash table在一开始的时候对t的字符进行了记录，剩下的都是值0
                举个例子，如果t字符串中有'A' 而且现在hash表中'A'的值又小于零，这说明窗口中的A的个数是大于需求的
                所以这个时候l指针可以向前移动，如果当前字符不是t中所包含的，那么l指针的移动就更加理所当然了
                
                也就是说 count只是用来记录当前窗口中包含了多少个t中的字符
                而按照我们维护窗口的方式，一旦count这个个数应该是只增不减的
            */
            while(l<r && hashTable[s[l]]<0)
            {
                hashTable[s[l]]++;
                l++;
            }
            if(count==0&&r-l+1<max)
            {
                max=r-l+1;
                res=s.substr(l, r-l+1);
            }
        }
        return res;
    }
};