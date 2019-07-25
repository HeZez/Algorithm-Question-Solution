/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
    反转一个单链表。

    示例:
    输入: 1->2->3->4->5->NULL
    输出: 5->4->3->2->1->NULL

    进阶:
    你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
*/
/*
    实现方法很多，可以移动链表节点
    或者不移动链表节点而是改变其中的值
    
    不移动链表节点可以用一个数组存储链表中的值，之后再倒着赋值回去就行，时间和空间复杂度都是O(n)
    
    移动链表节点基于迭代的方法：
    其实也不算移动 翻转链表，只要把当前节点的next指针指向前一个节点就行了，最后记得返回新的链表头
    要用到三个指针，pre cur next
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        /*
        // 不移动链表节点方法
        vector<int> nums;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            nums.push_back(temp->val);
            temp=temp->next;
        }
        temp=head;
        for(int i=nums.size()-1;i>=0;i--)
        {
            temp->val=nums[i];
            temp=temp->next;
        }
        return head;
        */
        
        /*
        // 迭代解法
        if(head==NULL||head->next==NULL)
            return head;
        ListNode* pre=NULL;
        ListNode* cur=head;
        ListNode* next=head->next;
        while(cur!=NULL)
        {
            // cout<<cur->val<<endl;
            next=cur->next;
            cur->next=pre;
            pre=cur;
            cur=next;
        }
        return pre;  // 这时pre指向的是未翻转前链表的最后一个节点
        */
        
        // 递归解法  参考了官方题解的递归解法，非常巧妙
        // 整个方法是从后向前的
        // 递归边界
        if(head==NULL||head->next==NULL)
            return head;
        ListNode* p=reverseList(head->next);
        head->next->next=head;    //head下一个节点的next指针指向自己
        head->next=NULL;   // headnext指针置为空
        return p;    // 这个p是用来记录新的链表头的
    }
};