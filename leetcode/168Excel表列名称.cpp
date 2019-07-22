/*
    给定一个正整数，返回它在 Excel 表中相对应的列名称。

例如，

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
    ...
    示例 1:

    输入: 1
    输出: "A"
    示例 2:

    输入: 28
    输出: "AB"
    示例 3:

    输入: 701
    输出: "ZY"
*/
/*
    和10进制转2进制类似  这里是除26取余，倒序排序
*/
class Solution {
public:
    string convertToTitle(int n) {
        string res="";
        if(n<=0) return res;
        int temp=n;
        int remainder=0;
        char c='A';
        while(temp>0)
        {
            remainder=temp%26;
            if(remainder==0)
            {
                c='Z';
                // 注意这里需要对原数字处理一下，因为这个26进制有点不一样， 有Z的出现
                // 相对于一般的进制 比如10进制 取余结果0-9是直接对应的 没有10出现
                // 而这里，对26取余余数为0-25，对应1-25对应A-Y 0对应Z
                // 在余数等于0的时候，这里需要减掉一个数 1-26均可
                temp-=26;  
            }
            else
            {
                c='A'+remainder-1;
            }
            res+=c;
            temp/=26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};