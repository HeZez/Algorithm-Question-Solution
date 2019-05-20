#include<stdio.h>
#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
const int maxn=500,INF=0x3f3f3f3f;
int L[maxn/2+2],R[maxn/2+2];

class SortFunction
{
public:
    void merge_opration(int a[],int left, int right, int mid)
    {
        int n1=mid-left,n2=right-mid;
    for(int i=0;i<n1;i++)
        L[i]=a[left+i];
    for(int i=0;i<n2;i++)
        R[i]=a[mid+i];
    L[n1]=R[n2]=INF;
    int i=0,j=0;
    for(int k=left;k<right;k++)
    {
        if(L[i]<=R[j])
            a[k]=L[i++];
        else
            a[k]=R[j++];
    }
    /*
    int left_index=left;
        int right_index=mid;
        int temp_index=left;
        while((left_index<mid)&&(right_index<right))
        {
            if(data[left_index]<data[right_index])
                temp[temp_index++]=data[left_index++];
            else
                temp[temp_index++]=data[right_index++];
        }

        while(left_index<mid)
            temp[temp_index++]=data[left_index++];
        while(right_index<right)
            temp[temp_index++]=data[right_index++];
    */
    }

    void merge_sort(int data[],int left, int right)
    {
        int mid;
        // left是左侧起始下标，right是右侧终止下标+1
        if(left+1<right)
        {
            mid=(left+right)/2;
            merge_sort(data,left,mid);
            merge_sort(data, mid, right);
            merge_opration(data, left, right, mid);
        }
    }
};

int main()
{
    SortFunction s;
    int data[maxn],n;
    int temp[maxn]={0};
    int num;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>num;
        data[i]=num;
    }
    s.merge_sort(data, 0, n);
    //cout<<"sort over"<<endl;
    for(int i=0;i<n;i++)
        cout<<data[i]<<' ';
    cout<<endl;
    return 0;
}
