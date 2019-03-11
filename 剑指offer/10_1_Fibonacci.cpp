/*
    题目描述
    大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。
    n<=39
*/

/*
    自底向上 没啥好说的 主要是动态规划的思想
*/
class Solution {
public:
    int Fibonacci(int n) {
        if(n==0||n==1)
            return n;
        int result=0;
        int temp0=0;
        int temp1=1;
        for(int i=2;i<=n;i++)
        {
            result=temp0+temp1;
            temp0=temp1;
            temp1=result;
        }
        return result;
    }
};