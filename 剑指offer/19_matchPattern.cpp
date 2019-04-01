/*
    题目描述
    请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，
    而'*'表示它前面的字符可以出现任意次（包含0次）。 在本题中，匹配是指字符串的所有字符匹配整个模式。
    例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配
*/

class Solution {
public:
    bool match(char* str, char* pattern)
    {
        if(str==NULL||pattern==NULL)
            return false; 
        //可以用递归解决
        return matchCore(str,pattern);
    }
private:
    bool matchCore(char* str, char* pattern)
    {
        if(*str=='\0'&&*pattern=='\0')
            return true;
        if(*str!='\0'&&*pattern=='\0')
            return false;
        if(*(pattern+1)=='*')
        {
            //if(*str!=*pattern&&*pattern!='.')
            //    matchCore(str,pattern+2);
            /*
            如果模式的下一个字符是*
                如果当前字符匹配，两种情况，第一种，字符串前进一位，模式不动；第二种，字符串不动，模式中跳过*这一部分
                如果当前字符不匹配，模式中跳过*这一部分。
            */
            if(*str==*pattern||(*pattern=='.'&&*str!='\0'))
                return matchCore(str+1,pattern)||matchCore(str,pattern+2);
            else
                return matchCore(str,pattern+2);
        }
        //这个if要写在下面 因为就算当前字符串和模式相等，也要先看模式的接下来一位是否是‘*’
        //这个if放在上面先执行就无法考虑这种情况，会出现错误
        if(*str==*pattern||(*pattern=='.'&&*str!='\0'))
            return matchCore(str+1,pattern+1);
        return false;
    }
};