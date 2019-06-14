/*
    实现 int sqrt(int x) 函数。
    计算并返回 x 的平方根，其中 x 是非负整数。

    由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

    示例 1:

    输入: 4
    输出: 2
    示例 2:

    输入: 8
    输出: 2
    说明: 8 的平方根是 2.82842..., 
         由于返回类型是整数，小数部分将被舍去。
*/
class Solution {
public:
    int mySqrt(int x) {
        if(x==0||x==1)
            return x==0?0:1;
        long result=1;
        int l=1;
        int r=x/2;
        /*
        最直接的顺次找，太慢了
        while(true)
        {
            if(result*result<=x && (result+1)*(result+1)>x)
                break;
            result++;
        }
        return int(result);
        */
        
        //二分查找
        while(true)
        {
            result=(l+r)/2;
            if(result*result>x)
                r=result-1;
            else if((result+1)*(result+1)>x)
                break;
            else
                l=result+1;
        }
        return result;
    }
};