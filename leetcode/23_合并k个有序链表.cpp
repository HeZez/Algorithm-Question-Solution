/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
    题目描述：
    合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
        示例:
        输入:
        [
          1->4->5,
          1->3->4,
          2->6
        ]
        输出: 1->1->2->3->4->4->5->6
    1.笨方法：按位比较  归并排序
    2.最小堆直接合并k个
    3.分治
*/

class minHeapBymyself
{
public:
    vector<int> minHeap(vector<ListNode*>& lists)
    {
        vector<int> heap;
        heap.push_back(0); // 不使用0这个位置
        int numOfList=lists.size();
        for(int i=0;i<numOfList;i++)
        {
            while(lists[i]!=NULL)
            {
                minHeapPush(heap, lists[i]->val);
                lists[i]=lists[i]->next;
            }
        }
        return heap;
    }

    void minHeapPush(vector<int>& heap, int num)
    {
        int loc1=-1;
        int loc2=-1;  //loc1是上层的  loc2是下层的
        heap.push_back(num);
        loc2=heap.size()-1;
        bool flag=true;
        while(flag)
        {
            loc1=loc2/2;
            if(loc1>=1)
            {
                if(heap[loc1]>heap[loc2])
                {
                    //上滤
                    swap(heap, loc1, loc2);
                    loc2=loc1;
                }
                else
                    flag=false;
            }
            else
                flag=false;
        }
    }
    int minHeapPop(vector<int>& heap)
    {
        int result=heap[1];
        swap(heap,1,heap.size()-1);
        heap.pop_back();
        int loc1=1;
        int loc2=1;
        int loc3=1;   //分别是当前节点坐标， 左孩子坐标，右孩子坐标
        int bound=0; //保存两个孩子中较小的那个
        bool flag=true;
        if(!isEmpty(heap))
        {
            while(flag)
            {
                // 下滤
                if(loc1*2<heap.size())
                {
                    loc2=loc1*2;
                    if(loc1*2+1<heap.size())
                    {
                        //两个孩子都存在  与小的那个交换
                        loc3=loc1*2+1;
                        if(heap[loc2]<=heap[loc3])
                            bound=heap[loc2];
                        else
                            bound=heap[loc3];
                        //bound=heap[loc2]<heap[loc3]?heap[loc2]:heap[loc3];
                        if(heap[loc1]>=bound)
                        {
                            //swap(heap, loc1, heap[loc2]<heap[loc3]?loc2:loc3);
                            if(heap[loc2]<heap[loc3])
                            {
                                swap(heap, loc1, loc2);
                                loc1=loc2;
                            }
                            else
                            {
                                swap(heap, loc1, loc3);
                                loc1=loc3;
                            }

                            //loc1=heap[loc2]<heap[loc3]?loc2:loc3;
                            //cout<<loc1<<loc2<<loc3<<endl;
                            //cout<<"23:"<<heap[loc2]<<heap[loc3]<<endl;
                            /*
                            if(heap[loc2]<=heap[loc3])
                                loc1=loc2;
                            else
                                loc1=loc3;
                                */
                            //cout<<loc1<<loc2<<loc3<<endl;
                        }
                        else
                            flag=false;
                    }
                    else
                    {
                        // 只有一个孩子  看左孩子是否满足交换条件
                        if(heap[loc1]>=heap[loc2])
                        {
                            swap(heap, loc1, loc2);
                            //cout<<loc1<<loc2<<endl;
                            loc1=loc2;
                            
                        }
                        else
                            flag=false;
                    }
                }
                else
                    flag=false;   // 没有孩子了 下滤结束
            }
        }
        return result;
    }
    void swap(vector<int>& heap, int i,int j)
    {
        int temp=heap[i];
        heap[i]=heap[j];
        heap[j]=temp;
    }
    bool isEmpty(vector<int>& heap)
    {
        bool result=false;
        if(heap.size()>1)
            result=false;
        else
            result=true;
        return result;
    }
};


class Solution {
    
public:
    //最小堆方法
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* result=new ListNode(0);
        ListNode* temp=result;
        vector<int> heap;
        int num=-1;
        minHeapBymyself minHeap;
        // 建堆
        heap=minHeap.minHeap(lists);
        /*
        cout<<"建堆结果"<<endl;
        for(int i=0;i<heap.size();i++)
            cout<<heap[i]<<endl;
        cout<<"建堆结果结束"<<endl;
        cout<<heap.size()<<endl;
        */
        while(!minHeap.isEmpty(heap))
        {
            num=minHeap.minHeapPop(heap);   
            ListNode* temp2=new ListNode(num);
            temp->next=temp2;
            temp=temp->next;
        }
        return result->next;
    }
};
    

/*
public:
    //最笨的方法
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* result=new ListNode(0);
        ListNode* temp=result;
        int numOfList=0;
        numOfList=lists.size();
        while(true)
        {
            int loc=-1;
            int min=INT_MAX;
            int numOfNull=0;
            for(int i=0;i<numOfList;i++)
            {
                if(lists[i]==NULL)
                    numOfNull++;
                if(lists[i]!=NULL)
                {
                    if(lists[i]->val<min)
                    {
                        min=lists[i]->val;
                        loc=i;
                    }
                }
            }
            if(numOfNull==numOfList)
                break;
            ListNode* temp2=new ListNode(min);
            temp->next=temp2;
            temp=temp->next;
            lists[loc]=lists[loc]->next;
        }
        return result->next;
    }
*/