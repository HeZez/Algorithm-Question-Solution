/*
    给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度。
    如果不存在最后一个单词，请返回 0 。

    说明：一个单词是指由字母组成，但不包含任何空格的字符串。

    示例:

    输入: "Hello World"
    输出: 5
*/

/*
    倒着找最后一个单词的长度,找到倒数第一个字母的位置，开始计数，直到遇到一个空格
    空格的ascii码32
    a-z:97-122
    A-Z:65-90
*/
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len=s.size();
        int result=0;
        if(len<=0)
            return result;
        int pos=-1;
        for(pos=len-1;pos>=0;pos--)
        {
            // 找到倒数第一个字母的位置
            if( (int(s[pos])>=97&&int(s[pos])<=122) || ( int(s[pos])>=65&&int(s[pos])<=90 ) )
                break;
        }
        if(pos>=0)
        {
            while(pos>=0)
            {
                if( ( int(s[pos])>=97&&int(s[pos])<=122 ) || ( int(s[pos])>=65&&int(s[pos])<=90) )
                    result++;
                else
                    break;
                pos--;
            }
        }
        return result;
    }
};