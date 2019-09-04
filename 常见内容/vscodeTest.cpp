#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;

class Test
{
    public:
    vector<int> plus(int a, int b)
    {
        vector<int> v(2, 0);
        v.push_back(a);
        v.push_back(b);
        return v;
    }
};

int main()
{
    int a=1, b=2;
    Test t;

    vector<int>testV=t.plus(a, b);
    /*
    for(auto item: testV)
    {
        cout<<item<<endl;
    }
    */
    for(int i=0;i<testV.size();i++)
    {
        cout<<testV[i]<<endl;
    }
    return 0;
}