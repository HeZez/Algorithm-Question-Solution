/*
    Input
The input will consist of a series of integers n, one integer per line.
 

Output
For each case, output SUM(n) in one line, followed by a blank line. You may assume the result will be in the range of 32-bit signed integer.
 

Sample Input
1
100
 

Sample Output
1

5050
*/

#include<iostream>

using namespace std;

int main()
{
    int n=0;
    while(cin>>n)
    {
        int sum=0;
        //cout<<((1+n)*n)/2<<endl<<endl;
        for(int i=1;i<=n;i++)
        {
            sum+=i;
        }
        cout<<sum<<endl<<endl;
    }
    return 0;
}