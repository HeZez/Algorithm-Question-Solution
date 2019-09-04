#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n=0,a=0;
    while(cin>>n)
    {
        if(n==0)
        break;
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
