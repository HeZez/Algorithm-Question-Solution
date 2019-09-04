/*
    Input
Input contains an integer N in the first line, and then N lines follow. Each line starts with a integer M, and then M integers follow in the same line. 
 

Output
For each group of input integers you should output their sum in one line, and you must note that there is a blank line between outputs.
 

Sample Input
3
4 1 2 3 4
5 1 2 3 4 5
3 1 2 3
 

Sample Output
10

15

6

要求最后一项输出不多进行换行
*/

#include<iostream>

using namespace std;

int main()
{
    int n1=0,n2=0;
    int a=0;
    cin>>n1;
    while(n1--)
    {
        int sum=0;
        cin>>n2;
        while(n2--)
        {
            cin>>a;
            sum+=a;
        }
        if(n1!=0)
            cout<<sum<<endl<<endl;
        else
            cout<<sum<<endl;
    }
    return 0;
}
