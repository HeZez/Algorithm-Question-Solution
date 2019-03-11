/*
    题目描述
    一只青蛙一次可以跳上1级台阶，也可以跳上2级。
    求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
*/
/*
    分析后和斐波那契数列含义相同
*/

class Solution {
public:
    int jumpFloor(int number) {
        
        if(number<=2)
            return number;
        int result=0;
        int temp0=1;
        int temp1=2;
        for(int i=3;i<=number;i++)
        {
            result=temp0+temp1;
            temp0=temp1;
            temp1=result;
        }
        return result;
        
        /*
        int f=1,g=2;
        number--;
        while(number--)
        {
            g+=f;
            f=g-f;
        }
        return f;
        */
    }
};