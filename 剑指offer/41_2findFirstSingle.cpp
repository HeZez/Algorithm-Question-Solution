/*
    题目描述
    请实现一个函数用来找出字符流中第一个只出现一次的字符。
    例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。
    当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。
    输出描述:
    如果当前字符流没有存在出现一次的字符，返回#字符。
*/
/*
    可以用一个hash表来记录字符出现的次数，用一个字符串把字符流记录下来，之后操作哈希表
    插入完成后再遍历字符串找目标
*/
class Solution
{
public:
    string str;
    int count[256]={0};
  //Insert one char from stringstream
    void Insert(char ch)
    {
        str+=ch;
        count[ch]++;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        int lengthOfStr=str.length();
        char result='#';
        for(int i=0;i<lengthOfStr;i++)
        {
            if(count[str[i]]==1)
            {
                result=str[i];
                break;
            }
        }
        return result;
    }

};