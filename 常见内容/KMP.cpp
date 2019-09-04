#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>

using namespace std;

class Solution
{
public:
    vector<int> getNext(string s)
    {
        int size=s.size();
        vector<int> next(size, 0);
        next[0]=-1;
        int i=0,j=-1;
        while(i<s.size())
        {
            if(j==-1||s[i]==s[j])
            {
                next[i++]=j++;

            }
            else
            {
                j=next[j];
            }
        }
        return next;
    }
};

int main()
{
    using namespace std;
    string s="abababca";
    Solution kmp;
    vector<int> next=kmp.getNext(s);
    for(auto item: next)
        cout<<item<<",";
    cout<<endl;
}
