/*
    给定两个字符串 s 和 t，它们只包含小写字母。

字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。

    请找出在 t 中被添加的字母。
     
    示例:
    输入：
    s = "abcd"
    t = "abcde"

    输出：
    e

    解释：
    'e' 是那个被添加的字母。
*/
/*
    最直接的两个想法
    1.字典序排序，直接按位对比  O(nlogn)
    2.hashmap遍历两遍，找到计数为1的那个key  O(n) 空间复杂度更高

    大佬想到的方法
    3.字符对应ascii码 用这个码来做加和 先用长的算出一个加和 再减去短的字符串字符ascii码加和 剩下的就是结果
    4.位运算  一个异或 由于添加的那个字符只出现了一次 所以在所有字符异或操作之后 剩下的那个就是添加的那个字符

    注意一些情况 比如“a” "aa" 这样的问题 用第二种方法会有问题 第二种方法应该用两个hashmap 针对两个字符建立
    之后找长的的那个字符串里那个字符在第一个Hashmap里不存在
*/
class Solution {
public:
    char findTheDifference(string s, string t) {
        if(s.empty()&&t.empty())
            return ' ';
        /*
        unordered_map<char, int> um;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=t[i])
                return t[i];
        }
        return t[t.size()-1];
        */
        // 位运算
        char result='a'^'a';     //创造一个“空”的结果
        for(auto i: s)
            result^=i;
        for(auto i: t)
            result^=i;
        return result;
    }
};