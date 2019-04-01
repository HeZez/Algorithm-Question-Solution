/*
    题目描述
    给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
*/

class Solution {
public:
    double Power(double base, int exponent) {
        if(base==0.0&&exponent==0)
            return 0.0;
        int exponentNoSign=exponent;
        double result=1.0;
        if(exponent<0)
        {
            exponentNoSign=0-exponentNoSign;
            result=powerByLogN(base,exponentNoSign);
            result=1.0/result;
        }
        else
        {
            result=powerByLogN(base,exponentNoSign);
        }
        return result;
    }
private:
    double powerByNum(double base,int exponentNoSign)
    {
        double result=1.0;
        for(int i=1;i<=exponentNoSign;i++)
        {
            result=result*base;
        }
        return result;
    }
    double powerByNumF(double base,int exponentNoSign)
    {
        double result=1.0;
        if(exponentNoSign==0)
            return 1.0;
        if(exponentNoSign%2==0)
        {
            for(int i=1;i<=exponentNoSign>>1;i++)
                result=result*base;
            result*=result;
        }
        else
        {
            for(int i=1;i<=exponentNoSign>>1;i++)
                result=result*base;
            result*=result;
            result*=base;
        }
        return result;
    }
    //O(logN)的解法
    double powerByLogN(double base,int exponentNoSign)
    {
        if(exponentNoSign==0)
            return 1.0;
        if(exponentNoSign==1)
            return base;
        double result=powerByLogN(base,exponentNoSign>>1);
        result*=result;
        if(exponentNoSign&1==1)
            result*=base;
        return result;
    }
};