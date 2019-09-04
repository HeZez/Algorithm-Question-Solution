/*
    Problem Description
Given a sequence a[1],a[2],a[3]......a[n], your job is to calculate the max sum of a sub-sequence. For example, given (6,-1,5,4,-7), the max sum in this sequence is 6 + (-1) + 5 + 4 = 14.
 

Input
The first line of the input contains an integer T(1<=T<=20) which means the number of test cases. Then T lines follow, each line starts with a number N(1<=N<=100000), then N integers followed(all the integers are between -1000 and 1000).
 

Output
For each test case, you should output two lines. The first line is "Case #:", # means the number of the test case. The second line contains three integers, the Max Sum in the sequence, the start position of the sub-sequence, the end position of the sub-sequence. If there are more than one result, output the first one. Output a blank line between two cases.
 

Sample Input
2
5 6 -1 5 4 -7
7 0 6 -1 1 -6 7 -5
 

Sample Output
Case 1:
14 1 4

Case 2:
7 1 6
*/
/*
    题干里说的是sub-sequence子序列，但是看他要求输出的结果，似乎又是连续的子串
    既然是连续的子串 可以用dp 滑动窗口呢？
    这道题如果只要求输出最大加和的值，用dp合适 这里还要求子序列位置 尝试一下滑动窗口 
    或者说 这里dp和滑动窗口思路基本一样
*/
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main()
{
    int n1=0,n2=0,a=0;
    cin>>n1;
    int count=0;
    while(n1--)
    {
        cin>>n2;
        count++;
        int templ=0,l=0,r=0;   // 滑动窗口边界
        int sum=0;
        int maxSum=INT_MIN;
        //vector<int> nums;  //重新创建vector
        for(int i=0;i<n2;i++)
        {
            cin>>a;
            //nums.push_back(a);
            
            if(sum>=0)
            {
                sum+=a;
            }
            else
            {
                sum=a;
                templ=i;
            }
            
            if(sum>maxSum)
            {
                maxSum=sum;
                r=i;
                l=templ;
            }
        }
        
        cout<<"case "<<count<<":"<<endl;
        cout<<maxSum<<" "<<l+1<<" "<<r+1<<endl<<endl;
        // nums.clear();
        // 回收vector内存  用这个swap交换函数，好像是把现在的容器和一个空容器交换，现在容器的内存就被销毁了
        // nums.swap(vector<int>());
    }
    return 0;
}
