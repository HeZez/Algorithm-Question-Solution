/*
    Input
The input will consist of a series of pairs of integers a and b, separated by a space, one pair of integers per line. 
 

Output
For each pair of input integers a and b you should output the sum of a and b, and followed by a blank line. 
 

Sample Input
1 5
10 20
 

Sample Output
6

30
 
 输出结果的时候 多换一次行
*/

#include<iostream>

using namespace std;

int main()
{
    int a=0,b=0;
    while(cin>>a>>b)
    {
        cout<<a+b<<endl<<endl;
    }
    return 0;
}