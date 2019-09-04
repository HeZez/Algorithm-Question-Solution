#include<iostream>

using namespace std;

int main()
{
    int n=0,a=0,b=0;
    while(cin>>n)
    {
        while(n--)
        {
            cin>>a>>b;
            cout<<a+b<<endl;
        }
    }
    return 0;
}