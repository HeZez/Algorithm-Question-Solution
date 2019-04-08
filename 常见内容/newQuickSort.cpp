#include<stdio.h>
#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

class Solution
{
public:
    int partitiion(int arr[], int left, int right)
    {
        int i=left+1;
        int j=right;
        int temp=arr[left];
        while(i<=j)
        {
            while(arr[i]<temp)
                i++;
            while(arr[j]>temp)
                j--;
            if(i<j)
                swap(arr[i++], arr[j--]);
            else
                i++;
        }
        swap(arr[left],arr[j]);
        return j;
    }
    void quickSort(int arr[], int left, int right)
    {
        if(left>right)
            return ;
        int j=partitiion(arr, left, right);
        quickSort(arr, left, j-1);
        quickSort(arr, j+1, right);
    }
};
int main()
{
    Solution s;
    int arr[9]={5,4,2,9,8,6,7,3,1};
    s.quickSort(arr, 0, 8);
    for(int i=0;i<9;i++)
        cout<<arr[i]<<' ';
    return 0;
}
