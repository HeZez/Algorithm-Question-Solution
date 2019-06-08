/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
    给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。
    你应当保留两个分区中每个节点的初始相对位置。
    
    示例:
    输入: head = 1->4->3->2->5->2, x = 3
    输出: 1->2->2->4->3->5
*/

/*
    想到的比较直接的方法是，统计个数，小于和大于目标值的个数，之后再创建一个数组，扫描多遍，
    把值填进去， 时间和空间的效率都比较低(其实不用计数就行，直接扫描两遍O(2N) 不过因为不是原地修改 空间复杂度较高) 
    
    大佬的做法：
    大佬的做法是用两个链表，一个是小于x的 一个是大于等于x的，之后把这两个链表连起来  这样扫描一遍就行
*/

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
            
        ListNode* temp1=head;
        ListNode* result=new ListNode(0);
        if(head==NULL)
            return result->next;
        ListNode* temp2=result;
        ListNode* temp;
        while(temp1)
        {
            if(temp1->val<x)
            {
                temp=new ListNode(temp1->val);
                temp2->next=temp;
                temp2=temp2->next;
            }
            temp1=temp1->next;
        }
        temp1=head;
        while(temp1)
        {
            if(temp1->val>=x)
            {
                temp=new ListNode(temp1->val);
                temp2->next=temp;
                temp2=temp2->next;
            }
            temp1=temp1->next;
        }
        return result->next;
    }
};