#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int n=0,k=0;
    cin>>n>>k;
    int sum=0,a=0;
    vector<int> v;
    int flag=1;
    if(n*8<k)
    {
        while(n--)
            cin>>a;
        cout<<-1<<endl;
    }
    else
    {
        while(n--)
        {
            cin>>a;
            v.push_back(a);
        }
        for(int i=0;i<v.size();i++)
        {
            if(v[i]>8)
            {
                sum+=8;
                if(i<v.size()-1)
                    v[i+1]+=(v[i]-8);
            }
            else
            {
                sum+=v[i];
            }
            if(sum>=k)
            {
                cout<<i+1<<endl;
                flag--;
                break;
            }
        }
        if(flag)
            cout<<-1<<endl;
    }
    return 0;
}