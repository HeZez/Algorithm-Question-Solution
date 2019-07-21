/*
    给定两个整数，分别表示分数的分子 numerator 和分母 denominator，以字符串形式返回小数。

    如果小数部分为循环小数，则将循环的部分括在括号内。

    示例 1:

    输入: numerator = 1, denominator = 2
    输出: "0.5"
    示例 2:

    输入: numerator = 2, denominator = 1
    输出: "2"
    示例 3:

    输入: numerator = 2, denominator = 3
    输出: "0.(6)"
*/
/*
    如何模拟除法，同时关键是如何判断循环
    可以先求整数部分结果，之后再求分数部分
    如果认为判断循环，循环就是除过一次之后，余数没有改变，这种方法只能判断出一位循环，无法判断多位
    
    比如4/333=0.00(675)
    官方题解用hash表来记录之前出现过的所有余数
    
    这题还会卡数据
    -1
    -2147483648
    很恶心
*/
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        
        string res="";
        // 整数部分
        // 判断结果正负
        long long numeratorLong=numerator;
        long long denominatorLong=denominator;
        bool flag=false;
        if((numeratorLong>0&&denominatorLong<0) || (numeratorLong<0&&denominatorLong>0))
            flag=true;
        long long num=abs(numeratorLong)/abs(denominatorLong);
        if(num>0)
        {
            int temp=0;
            while(num>0)
            {
                temp=num%10;
                char c='0'+temp;
                res+=c;
                num/=10;
            }
            if(flag)
                res+='-';
            reverse(res.begin(),res.end());
        }
        else
        {
            if(flag)
                res+='-';
            res+='0';
        }
        
        // 判断是否整除
        if(abs(numeratorLong)%abs(denominatorLong)==0)
            return res;
        else
        {
            // 没整除有小数部分
            unordered_map<long long, int> m;  //用于记录出现过的余数
            res+='.';
            long long remainder1=abs(numeratorLong)%abs(denominatorLong);
            int index=0;   //记录循环部分长度
            while(remainder1!=0&&(m.find(remainder1)==m.end()))
            {
                m[remainder1]=index++;
                remainder1*=10;
                int resOnebit=abs(remainder1)/abs(denominatorLong);
                res+='0'+resOnebit;
                remainder1=abs(remainder1)%abs(denominatorLong);
            }
            // 判断是否是因为出现了循环而结束的上一个while语句
            if(m.find(remainder1)!=m.end())
            {
                //循环部分长度
                int length=index-m[remainder1];
                res.insert(res.end()-length,'(');
                res+=')';
            }
        }
        return res;
    }
};