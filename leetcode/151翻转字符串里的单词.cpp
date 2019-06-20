/*
    给定一个字符串，逐个翻转字符串中的每个单词。
    
    示例 1：
    输入: "the sky is blue"
    输出: "blue is sky the"
    
    示例 2：
    输入: "  hello world!  "
    输出: "world! hello"
    解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
    
    示例 3：
    输入: "a good   example"
    输出: "example good a"
    解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。

    说明：
    无空格字符构成一个单词。
    输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
    如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
*/
/*
    首先进行去空格处理
    之后把每个单词翻转，接下来翻转整个字符串
    
    看了下大佬的解决方案，自己太笨了 自愧不如
    倒序遍历整个字符串，滤掉所有空格，手动为单词之间添加空格
    即找到倒数第一个单词加入到结果中，之后手动添加空格
*/
class Solution {
public:
    string reverseWords(string s) 
    {
        string res;
        for(int i=s.size()-1;i>=0;)
        {
            while(i>=0&&s[i]==' ')
                i--;
            if(i<0)
                break;
            int j=i;
            while(j>=0&&s[j]!=' ')
                j--;
            res+=(s.substr(j+1, i-j));
            res+=(' ');
            i=j;
        }
        // 最后多加了一个空格 记得去掉
        return res.substr(0, res.size()-1);
    }
    /*
    string reverseWords(string s) {
        string res;
        for(int i = s.size() - 1;i >= 0;){
            while(i >= 0 && s[i] == ' ') i--;
            if(i < 0) break;
            int j = i - 1;
            while(j >= 0 && s[j] != ' ') j--;
            res += s.substr(j + 1,i - j);
            res.push_back(' ');
            i = j - 1;
        }
        return res.substr(0,res.size() - 1);
    }
    */
};