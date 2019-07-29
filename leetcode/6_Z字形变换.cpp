/*
    将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。

    比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：

    L   C   I   R
    E T O E S I I G
    E   D   H   N
    之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。

    请你实现这个将字符串进行指定行数变换的函数：

    string convert(string s, int numRows);
    示例 1:

    输入: s = "LEETCODEISHIRING", numRows = 3
    输出: "LCIRETOESIIGEDHN"
    示例 2:

    输入: s = "LEETCODEISHIRING", numRows = 4
    输出: "LDREOEIIECIHNTSG"
    解释:

    L     D     R
    E   O E   I I
    E C   I H   N
    T     S     G

*/
/*
    本质上是把原字符串进行一个N字形变化，之后按行输出字符
    如果不要求空间复杂度的话，其实可以建一个矩阵按照规则变换一下，之后按行输出矩阵中的值
    但是其实可以直接找规律在原地完成这个转换
*/


class Solution {
public:
    string convert(string s, int numRows) {
        //找规律，只看竖着的列，不看中间斜着的列，两列之间差了2*（numRows-1）-1个字符
        //包含斜着的部分，比如实例2中，第二行E和O差了3，等于（4-2）*2-1
        // 每行的终止条件是加上上面这两个值之后不越界，如果超过字符串长度，就换下一行。
        int flag=0;
        int len=s.size();
        string result;
        if(numRows==1)
            return s;
        for(int i=0;i<numRows;i++)
        {
            flag=i;
            result+=s[flag];
            if(i==0||i==numRows-1)   // 第一行和最后一行没有斜着的部分
            {
                while(flag+2*(numRows-1)<=len-1)
                {
                    flag=flag+2*(numRows-1);
                    result+=s[flag];
                }
            }
            else
            {
                while(true)
                {
                    if(flag+2*(numRows-i-1)<=len-1)
                    {
                        result+=s[flag+2*(numRows-i-1)];
                    }
                    else
                        break;
                    if(flag+2*(numRows-1)<=len-1)
                    {
                        flag=flag+2*(numRows-1);
                        result+=s[flag];
                    }
                    else
                        flag=flag+2*(numRows-1);
                }
            }
        }
        return result;
    }
};