#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> num1;
    vector<int> num2;
    num1.push_back(7);
    num1.push_back(0);
    num2.push_back(8);
    num2.push_back(0);
    vector<int> result(num1.size()+num2.size(), 0);
    cout<<num1.size()<<" "<<num2.size()<<" "<<result.size()<<endl;
    for(int i=0;i<num1.size();i++)
    {
        for(int j=0;j<num2.size();j++)
        {
            result[i+j+1]+=(num1[i]*num2[j]);
        }
    }
    cout<<"dasdsad"<<endl;
    for(int k=result.size()-1;k>0;k--)
    {
        if(result[k]>10)
        {
            result[k-1]+=(result[k]/10);
            result[k]=result[k]%10;
        }
    }
    for(auto item: result)
        cout<<item<<" ";
    cout<<endl;
    return 0;
}