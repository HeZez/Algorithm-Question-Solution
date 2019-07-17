/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
    在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。

    示例 1:

    输入: 4->2->1->3
    输出: 1->2->3->4
    示例 2:

    输入: -1->5->3->4->0
    输出: -1->0->3->4->5
*/
/*
    比较适合这道题的排序方式应该是归并排序
    思路就是快慢指针找中点，分为两部分，排序后merge
    
    merge的时候怎么进行呢？ 按照数组的归并排序形式merge的时候比较值大小，就是二路归并
    在链表形式应该怎么做呢？怎样在原地进行操作达到merge的目的
    merge也可以用递归的形式达成
    
    解法来自大佬 自己还是太菜。。。。。
*/
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        
        //递归边界
        if(head==NULL||head->next==NULL)
            return head;
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL&&fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        fast=slow->next;
        // 这一步很巧妙 因为merge的时候还会连接起来，这样置为NULL不会影响最后结果
        // 同时为NULL可以很方便的确定递归边界
        slow->next=NULL;   
        return merge(sortList(head), sortList(fast));
        
    }
    
    ListNode* merge(ListNode* left, ListNode* right)
    {
        ListNode d(0);
        ListNode* dummy = &d;
        
        while(left&&right)
        {
            if(left->val<right->val)
            {
                dummy->next=left;
                left=left->next;
            }
            else
            {
                dummy->next=right;
                right=right->next;
            }
            dummy=dummy->next;
        }
        
        if(left!=NULL)
        {
            dummy->next=left;
        }
            
        if(right!=NULL)
        {
            dummy->next=right;
        }
        return d.next;
    }
    
    /*
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode d(0);
        ListNode* dummy = &d;
        while(l1||l2){
            if(!l2 || (l1&&l1->val<l2->val))    {
                dummy->next=l1;
                l1=l1->next;
            }else {
                dummy->next = l2;
                l2=l2->next;
            }
            dummy=dummy->next;
        }
        return d.next;
    }
    */
};