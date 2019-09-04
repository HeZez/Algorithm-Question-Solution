#include<iostream>
#include<vector>

using namespace std;

/*
    Input contains an integer N in the first line, and then N lines follow. Each line starts with a integer M, and then M integers follow in the same line. 
    

    Output
    For each group of input integers you should output their sum in one line, and with one line of output for each line in input. 
    

    Sample Input
    2
    4 1 2 3 4
    5 1 2 3 4 5
    

    Sample Output
    10
    15

    先给定n行
    之后每行数据第一个数是个数
*/
int main()
{
    int n1=0;
    int n2=0;
    int a=0;
    cin>>n1;
    while(n1--)
    {
        cin>>n2;
        int sum=0;
        while(n2--)
        {
            cin>>a;
            sum+=a;
        }
        cout<<sum<<endl;
    }
    return 0;
}