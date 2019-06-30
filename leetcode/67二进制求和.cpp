/*
    给定两个二进制字符串，返回他们的和（用二进制表示）。

    输入为非空字符串且只包含数字 1 和 0。

    示例 1:

    输入: a = "11", b = "1"
    输出: "100"
    示例 2:

    输入: a = "1010", b = "1011"
    输出: "10101"
*/
/*
    按位加之后把字符串倒转
*/

class Solution {
public:
    /*
    // 自己的写法，许多步骤比较繁琐，接下来借鉴大佬的写法优化一下
    string addBinary(string a, string b) {
        string res="";
        if(a.size()<=0||b.size()<=0) return res;
        int i=a.size()-1;
        int j=b.size()-1;
        int flag=0;  //进位标志位
        while(i>=0&&j>=0)
        {
            int numA=a[i]-'0';
            int numB=b[j]-'0';
            int temp=numA+numB+flag;
            if(temp<2)
            {
                res+=temp+'0';
                flag=0;
            }
            else
            {
                if(temp==2)
                    res+='0';
                else
                    res+='1';
                flag=1;
            }
            i--;
            j--;
        }
        if(i>=0)
        {
            while(i>=0)
            {
                int numA=a[i]-'0';
                int temp=numA+flag;
                if(temp<2)
                {
                    res+=temp+'0';
                    flag=0;
                }
                else
                {
                    res+='0';
                    flag=1;
                }
                i--;
            }
        }
        if(j>=0)
        {
            while(j>=0)
            {
                int numB=b[j]-'0';
                int temp=numB+flag;
                if(temp<2)
                {
                    res+=temp+'0';
                    flag=0;
                }
                else
                {
                    res+='0';
                    flag=1;
                }
                j--;
            }
        }
        // 考虑最后一次运算是否进位了
        if(flag)
            res+='1';
        // 翻转结果
        reverse(res.begin(), res.end());
        return res;
    }
    */
    
    // 优化一下
    string addBinary(string a, string b) {
        string res="";
        if(a.size()<=0||b.size()<=0) return res;
        int i=a.size()-1;
        int j=b.size()-1;
        int flag=0;  //进位标志位
        int numA=0;
        int numB=0;
        while(i>=0||j>=0)
        {
            if(i>=0)
                numA=a[i]-'0';
            else
                numA=0;
            if(j>=0)
                numB=b[j]-'0';
            else
                numB=0;
            int temp=numA+numB+flag;
            res+=(temp%2+'0');     //用对2取余来确定这一位的数字
            if(temp<2)
                flag=0;
            else
                flag=1;
            i--;
            j--;
        }
        // 考虑最后一次运算是否进位了
        if(flag)
            res+='1';
        // 翻转结果
        reverse(res.begin(), res.end());
        return res;
    }
};