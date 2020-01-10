#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
# include <cstdio>
# include <cstring>

using namespace std;

int main()
{
    char str[100005];
    gets(str);
    int num[105];
    int rel =0;
    int cou =0;
    for(int i=0;i<strlen(str);i++)
    {
        if(str[i]>='0'&&str[i]<='9')
        {
            rel = rel * 10 + str[i] - '0';
        }
        else{
            num[cou++] = rel;
            rel = 0;
        }
    }

    num[cou++] = rel;

    // vector<int> dp(0, v.size());
    int firstLen=cou/2;
    int result=1;
    int longest=-1;
    int reachPos=-1;
    for(int i=1;i<firstLen;i++)
    {
        if(num[i]+i>longest)
        {
            longest=num[i]+i;
            cout<<longest<<endl;
            reachPos=i;
        }
    }

    while(longest>=cou)
    {
        for(int i=reachPos;i<num[i]&&i<cou;i++)
        {
            if(num[i]+i>longest)
            {
                longest=num[i]+i;
                reachPos=i;
            }
        }
        result++;
    }
    cout<<result<<endl;
    return 0;

}

