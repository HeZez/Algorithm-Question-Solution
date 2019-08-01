/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
    给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

    你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

    示例:
    给定 1->2->3->4, 你应该返回 2->1->4->3.
*/
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode* pre=NULL;
        ListNode* temp1=head;
        ListNode* temp2=head->next;
        while(true)
        {
            if(pre!=NULL)
            {
                temp1->next=temp2->next;
                temp2->next=temp1;
                pre->next=temp2;
                
                pre=temp1;
                // 指针移动
                if(temp1->next==NULL||temp1->next->next==NULL)
                    break;
                else
                {
                    temp2=temp1->next->next;
                    temp1=temp1->next;
                }
            }
            else
            {
                temp1->next=temp2->next;
                temp2->next=temp1;
                head=temp2;
                pre=temp1;
                // 指针移动
                if(temp1->next==NULL||temp1->next->next==NULL)
                    break;
                else
                {
                    temp2=temp1->next->next;
                    temp1=temp1->next;
                }
            }
        }
        return head;
    }
};