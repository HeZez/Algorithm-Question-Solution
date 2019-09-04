/*
    Input
    Input contains multiple test cases, and one case one line. Each case starts with an integer N, and then N integers follow in the same line. 
    

    Output
    For each test case you should output the sum of N integers in one line, and with one line of output for each line in input. 
    

    Sample Input
    4 1 2 3 4
    5 1 2 3 4 5
    

    Sample Output
    10
    15

    不确定多少行输入
    每行第一个数字表示该行数据个数
*/

#include<iostream>

using namespace std;

int main()
{
    int n=0,a=0;
    while(cin>>n)
    {
        int sum=0;
        while(n--)
        {
            cin>>a;
            sum+=a;
        }
        cout<<sum<<endl;
    }
    return 0;
}
