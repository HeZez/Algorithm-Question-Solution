#include<stdio.h>
#include<iostream>
#include<string.h>
#include<vector>
using namespace std;


// 归并排序，分支思想的典型应用
//class Solution
//{
//public:
    void mergeOperation(int data[], int left, int right, int temp[])
    {
        int left_length=(right-left+1)/2+1;  // 左半部分长度
        int left_index=left;
        int right_index=left+left_length;    // 右半部分的起始坐标
        int temp_index=left;
        while(left_index<(left+left_length)&&right_index<right+1);
        {
            if(data[left_index]<data[right_index])
                temp[temp_index++]=data[left_index++];
            else
                temp[temp_index++]=data[right_index++];
        }
        // 退出上面的循环 说明两个条件有其中一个不被满足，或者两个都不满足，这时只要将剩余的另一部分直接赋值给temp数组就行
        while(left_index<(left+left_length))
            temp[temp_index++]=data[left_index++];
        while(right_index<right+1)
            temp[temp_index++]=data[right_index++];
    }

    void merge_sort(int data[], int left,int right, int temp[])
    {
        /*
            三种情况
                 首先是left比right小1，这时分出来区间只有两个值，直接排序
                 第二种是left大于等于right，这说明区间只有一个元素或者越界了，直接返回
                 第三种是常规的情况，继续划分
        */

        int tempNum;
        if(right-left==1)
        {
            if(data[right]<data[left])
            {
                tempNum=data[left];
                data[left]=data[right];
                data[right]=tempNum;
            }
        }
        else if(left>=right)
            return ;

        else
        {
            // 继续划分
            merge_sort(data, left, (right-left+1)/2+left, temp);
            merge_sort(data, (right-left+1)/2+left+1, right, temp);
            mergeOperation(data, left, right, temp);
            for(int i=left;i<=right;i++)
            {
                data[i]=temp[i];
            }
        }
    }
//};

int main()
{
    int left=0;
    int right=9;
    int data[10]={2,4,8,1,10,6,5,7,3,9};
    int temp[10];
    //Solution s;
    for(int i=0;i<=right;i++)
        cout<<data[i]<<' ';
    cout<<endl;
    merge_sort(data, left, right, temp);
    for(int i=0;i<=right;i++)
        cout<<data[i]<<' ';
    cout<<endl;
    return 0;
}
