// 实际上是第三题
#include<cstdio>
//#include<cstring>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<iostream>

using namespace std;

int main()
{
    //char str[10000];
    //gets(str);
    string ss;
    cin>>ss;
    unordered_map<string, int> um;
    string target="";
    int flag=2;
    int firstPos=0;
    int secondPos=0;
    for(int i=0;i<ss.size();i++)
    {
        if(ss[i]==';')
        {
            firstPos=i;
            break;
        }
    }

    for(int i=firstPos+1;i<ss.size();i++)
    {
        if(ss[i]==';')
        {
            secondPos=i;
            break;
        }
    }

    string onePart=ss.substr(0, firstPos);
    string twoPart=ss.substr(firstPos+1, secondPos-firstPos-1);
    target=ss.substr(secondPos+1, ss.size());
    cout<<onePart<<endl;
    cout<<twoPart<<endl;
    cout<<target<<endl;
    int left=0,right=0;
    string temp="";
    for(int i=0;i<twoPart.size();)
    {
        if(twoPart[i]=='[')
        {
            left=i;
            while(twoPart[i]!=']')
                i++;
            right=i;
            temp=twoPart.substr(left, right-left+1);
            while(twoPart[i]<'0'||twoPart[i]>'9')
                i++;
            int tempNum=0;
            while(twoPart[i]>='0'&&twoPart[i]<='9')
            {
                tempNum=tempNum*10+(twoPart[i]-'0');
                i++;
            }
            um[temp]=tempNum;
        }
        else
        {
            i++;
        }
    }
    for(auto item:um)
    {
        cout<<item.first<<item.second<<endl;
    }



    return 0;

}