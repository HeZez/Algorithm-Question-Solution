/*
    Problem Description
Contest time again! How excited it is to see balloons floating around. But to tell you a secret, the judges' favorite time is guessing the most popular problem. When the contest is over, they will count the balloons of each color and find the result.

This year, they decide to leave this lovely job to you. 
 

Input
Input contains multiple test cases. Each test case starts with a number N (0 < N <= 1000) -- the total number of balloons distributed. The next N lines contain one color each. The color of a balloon is a string of up to 15 lower-case letters.

A test case with N = 0 terminates the input and this test case is not to be processed.
 

Output
For each case, print the color of balloon for the most popular problem on a single line. It is guaranteed that there is a unique solution for each test case.
 

Sample Input
5
green
red
blue
red
red
3
pink
orange
pink
0
 

Sample Output
red
pink
*/
/*
    统计频率 很标准的哈希表应用
*/
#include<algorithm>
#include<iostream>
#include<unordered_map>
#include<string>
#include<cmath>

using namespace std;

int main()
{
    int n=0;
    string ss;
    unordered_map<string ,int> um;
    while(cin>>n)
    {
        if(n==0)
            break;
        int maxNum=INT_MIN;
        string maxSS="";
        um.clear();
        while(n--)
        {
            cin>>ss;
            if(um.find(ss)!=um.end())
                um[ss]++;
            else
            {
                um[ss]=1;
            }
            if(um[ss]>maxNum)
            {
                maxNum=um[ss];
                maxSS=ss;
            }
        }
        cout<<maxSS<<endl;
    }
    return 0;
}

