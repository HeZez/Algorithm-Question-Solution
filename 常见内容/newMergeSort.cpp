
#include<iostream>
using namespace std;
const int maxn=500,INF=0x3f3f3f3f;
//int L[maxn/2+2],R[maxn/2+2];
/*
void merge(int a[],int left,int mid,int right)
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
}
*/
void merge(int data[],int left,int mid,int right, int temp[])
{
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
}
void mergesort(int a[],int left,int right, int temp[])
{
    if(left+1<right)
    {
        int mid=(left+right)/2;
        mergesort(a,left,mid,temp);
        mergesort(a,mid,right,temp);
        merge(a,left,mid,right,temp);
    }
}
int main()
{
    int a[maxn],n;
    int temp[maxn]={0};
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    mergesort(a,0,n,temp);
    for(int i=0;i<n;i++)
    {
        if(i)
            cout<<" ";
        cout<<a[i];
    }
    cout<<endl;
    return 0;
}
