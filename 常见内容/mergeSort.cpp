#include<stdio.h>
#include<iostream>
#include<string.h>
#include<vector>
using namespace std;


// �鲢���򣬷�֧˼��ĵ���Ӧ��
//class Solution
//{
//public:
    void mergeOperation(int data[], int left, int right, int temp[])
    {
        int left_length=(right-left+1)/2+1;  // ��벿�ֳ���
        int left_index=left;
        int right_index=left+left_length;    // �Ұ벿�ֵ���ʼ����
        int temp_index=left;
        while(left_index<(left+left_length)&&right_index<right+1);
        {
            if(data[left_index]<data[right_index])
                temp[temp_index++]=data[left_index++];
            else
                temp[temp_index++]=data[right_index++];
        }
        // �˳������ѭ�� ˵����������������һ���������㣬���������������㣬��ʱֻҪ��ʣ�����һ����ֱ�Ӹ�ֵ��temp�������
        while(left_index<(left+left_length))
            temp[temp_index++]=data[left_index++];
        while(right_index<right+1)
            temp[temp_index++]=data[right_index++];
    }

    void merge_sort(int data[], int left,int right, int temp[])
    {
        /*
            �������
                 ������left��rightС1����ʱ�ֳ�������ֻ������ֵ��ֱ������
                 �ڶ�����left���ڵ���right����˵������ֻ��һ��Ԫ�ػ���Խ���ˣ�ֱ�ӷ���
                 �������ǳ�����������������
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
            // ��������
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
