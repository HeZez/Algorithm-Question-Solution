/*
    题目描述
    在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置, 
    如果没有则返回 -1（需要区分大小写）.
*/
/*
    思路：可以用一个hashMap来记录各个字符的出现次数，注意这里都是字符型的，
    只有256种不同的可能，于是可以用一个整形数组来模拟这个hashmap
    先扫描一遍字符串记录出现次数，
    之后再扫描一遍字符串得到第一个计数为1的字符
*/

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        int n=str.length();
        int hashMap[256]={0};
        int result=-1;
        for(int i=0;i<n;i++)
        {
            hashMap[str[i]]++;
        }
        for(int i=0;i<n;i++)
        {
            if(hashMap[str[i]]==1)
            {
                result=i;
                break;
            }
        }
        return result;
    }
};