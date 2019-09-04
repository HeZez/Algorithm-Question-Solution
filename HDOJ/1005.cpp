/*
    Problem Description
A number sequence is defined as follows:

f(1) = 1, f(2) = 1, f(n) = (A * f(n - 1) + B * f(n - 2)) mod 7.

Given A, B, and n, you are to calculate the value of f(n).
 

Input
The input consists of multiple test cases. Each test case contains 3 integers A, B and n on a single line (1 <= A, B <= 1000, 1 <= n <= 100,000,000). Three zeros signal the end of input and this test case is not to be processed.
 

Output
For each test case, print the value of f(n) on a single line.
 

Sample Input
1 1 3
1 2 10
0 0 0
 

Sample Output
2
5
*/

/*
    动态规划水题
    只需要前两个值 可以优化空间复杂度到o(1)

    dp会tle。。。。。
    因为1 <= n <= 100,000,000
    直接dp会超时

    真正的做法是找规律，这样的求余运算会在一定的范围内结果出现循环
*/

#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n=0,A=0,B=0,result=0;
    int one=1;int two=1;
    while(cin>>A>>B>>n)
    {
        if(n==0&&A==0&&B==0)
            break;
        
        for(int i=1;i<=n;i++)
        {
            if(i<=2)
            {
                continue;
            }
            else
            {
                result=(A*two+B*one)%7;
                two=one;
                one=result;
            }
        }
        result=n>2?result:1;
        cout<<result<<endl;
    }
}

