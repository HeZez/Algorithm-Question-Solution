/*
    给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。
    示例 1:

    输入: "(()"
    输出: 2
    解释: 最长有效括号子串为 "()"
    示例 2:

    输入: ")()())"
    输出: 4
    解释: 最长有效括号子串为 "()()"
*/

/*
    大佬的做法1.正反遍历两边字符串  进行括弧有效性验证 记录两次中最大的有效长度  但是我没看懂代码 也没想通
    另一种做法是创建一个和字符串等长的数组，一一映射把数组中有效括号的部分设置为1，无效的设置为0，之后看数组中最多有多少个连续的1
*/
class Solution {
public:
    int core(string s, char lable)
    {
        stack<char> sk;
        int len=s.length();
        if(len<=1)
            return 0;
        int maxL=0;
        int tempL=0;
        bool daduanFlag=false;
        for(int i=0;i<len;i++)
        {
            // 首先判断栈是不是空的
            if(sk.empty())
            {
                // 判断当前要入栈的这个符号是不是'('
                if(s[i]==lable)
                    sk.push(s[i]);   // 栈空的时候说明前面的一段是合法括号  这是如果入栈的下一个是左括号 是合法的 ，右括号不合法
                else
                {
                    if(tempL>maxL)
                        maxL=tempL;
                    tempL=0;  // 这一位不合法说明有效长度需要重新计算   这一位字符不入栈
                }
            }
            else
            {
                if(s[i]==lable)
                    sk.push(s[i]);
                else 
                {
                    if(sk.top()==lable)
                    {
                        // 有一个括号匹配上了
                        tempL++;
                        sk.pop();
                        if(tempL>maxL&&sk.empty())  // 注意这里的条件加上了判断是否为空 因为对于'(()'这样的样例  如果不判空会认为有效长度是2  其实是0
                            maxL=tempL;
                    }
                }
            }
        }
        return maxL*2;
    }
    
    int longestValidParentheses(string s) {
        //  根据大佬的第一种情况改了一下自己的代码
        int len=s.length();
        int result1=0;
        int result2=0;
        if(len<=1)
            return 0;
        result1=core(s, '(');
        //把字符串s倒过来   注意“(()”直接用翻转函数得到的结果是")(("  和想要的不一样
        // 于是改变策略  在正着的时候认为‘(’是左括号 反着的时候认为')'是左括号
        reverse(s.begin(),s.end());
        result2=core(s, ')');
        return max(result1, result2);
    }

    
    /*
    // 这是我的想法 但是做法想的不够全面，对于‘() ( () ’这样的样例无法通过。
    int longestValidParentheses(string s) {
        
        stack<char> sk;
        int len=s.length();
        if(len<=1)
            return 0;
        int maxL=0;
        int tempL=0;
        bool daduanFlag=false;
        for(int i=0;i<len;i++)
        {
            // 首先判断栈是不是空的
            if(sk.empty())
            {
                // 判断当前要入栈的这个符号是不是'('
                if(s[i]=='(')
                    sk.push(s[i]);   // 栈空的时候说明前面的一段是合法括号  这是如果入栈的下一个是左括号 是合法的 ，右括号不合法
                else
                {
                    tempL=0;  // 这一位不合法说明有效长度需要重新计算   这一位字符不入栈
                }
            }
            else
            {
                if(s[i]=='(')
                    sk.push(s[i]);
                else 
                {
                    if(sk.top()=='(')
                    {
                        // 有一个括号匹配上了
                        tempL++;
                        sk.pop();
                        if(tempL>maxL)
                            maxL=tempL;
                    }
                }
            }
        }
        return maxL*2;
    }
    */
};