/*
    给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。

    返回被除数 dividend 除以除数 divisor 得到的商。

    示例 1:
    输入: dividend = 10, divisor = 3
    输出: 3
    
    示例 2:
    输入: dividend = 7, divisor = -3
    输出: -2
    说明:

    被除数和除数均为 32 位有符号整数。
    除数不为 0。
    假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231,  231 − 1]。本题中，如果除法结果溢出，则返回 231 − 1。
*/
/*
    相当于是个整数除法，除法本质上是减法，可以通过减法计数来实现
    先确定结果的正负，之后计数，这样效率比较低
    
    或者我觉得可以通过位运算实现，效率更高
    找到 被除数>=除数 * 2^i 关系成立时最大的那个i，之后结果加上2^i，被除数减去 除数 * 2^i，接下来继续进行循环，直到被除数小于除数
    如何处理溢出值？
    
*/
class Solution {
public:
    /*
    int divide(int dividend, int divisor) {
        if(dividend==0)
            return 0;
        bool flag=true;
        if( (dividend>0&&divisor>0) || (dividend<0&&divisor<0) )
            flag=true;
        if( (dividend<0&&divisor>0) || (dividend>0&&divisor<0) )
            flag=false;
        int temp=abs(dividend);
        divisor=abs(divisor);
        int res=0;
        while(true)
        {
            temp-=divisor;
            if(temp>=0)
                res++;
            else
                break;
        }
        if(!flag)
            res=0-res;
        return res;
    }
    */
    int divide(int dividend, int divisor) {
        
        if(dividend==0)
            return 0;
        
        if(dividend==INT_MIN && divisor==-1)
            return INT_MAX;
            
        bool flag=true;
        flag=(dividend^divisor)<0;    // 这个异或主要是看符号位，00 11的时候符号位异或后为0，反之则为1 符号位为1是负数
        long dividendCopy=labs(dividend); // 注意 long的绝对值函数labs（）
        long d=labs(divisor);
        long res=0;
        while(dividendCopy>=d)
        {
            long temp=d, t=1;
            while(temp<<1 <= dividendCopy)
            {
                t<<=1;
                temp<<=1;
            }
            res+=t;
            dividendCopy-=temp;
        }
        return flag?-res:res;
        
        /*
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        long dvd = labs(dividend), dvs = labs(divisor), ans = 0;
        int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
        while (dvd >= dvs) {
            long temp = dvs, m = 1;
            while (temp << 1 <= dvd) {
                temp <<= 1;
                m <<= 1;
            }
            dvd -= temp;
            ans += m;
        }
        return sign * ans;
        */
    }
};