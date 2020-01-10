#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    vector<int> v;
    int n=0,a=0;
    cin>>n;
    while(n--)
    {
        cin>>a;
        v.push_back(a);
    }
    sort(v.rbegin(), v.rend());
    int flag=1;
    int sum=0;
    int s=1;
    int count=0;
    for(int i=0;i<v.size()-1;)
    {
        if(v[i]==v[i+1]||(v[i]-v[i+1]==1))
        {
            if(v[i]==v[i+1])
            {
                s*=v[i];
                count++;
                if(count==2)
                {
                    sum+=s;
                    s=1;
                    count=0;
                }
                i+=2;
            }
            if(v[i]-v[i+1]==1)
            {
                if(flag==1)
                {
                        s*=(v[i]-1);
                        count++;
                        if(count==2)
                        {
                            sum+=s;
                            s=1;
                            count=0;
                        }
                        flag--;
                }
                else
                {
                        i++;
                }    
            }
        }
        else
        {
            i++;
        }
     
    }
    cout<<sum<<endl;
    return 0;
}