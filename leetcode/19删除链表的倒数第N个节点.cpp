/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
    给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

    示例：

    给定一个链表: 1->2->3->4->5, 和 n = 2.

    当删除了倒数第二个节点后，链表变为 1->2->3->5.
    说明：

    给定的 n 保证是有效的。

    进阶：

    你能尝试使用一趟扫描实现吗？
*/
/*
    最直接的办法就是先遍历一趟确定链表中节点的个数，之后再删除，这样需要两趟遍历
    
    一趟遍历的话，除了用hash表作索引，更好的办法是用快慢指针，直接找到倒数第N个节点
*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* pre=NULL;
        ListNode* fast=head;
        ListNode* slow=head;
        for(int i=0;i<n;i++)
        {
            fast=fast->next;
        }
        while(fast!=NULL)
        {
            pre=slow;
            slow=slow->next;
            fast=fast->next;
        }
        if(pre==NULL)
            head=slow->next;
        else
            pre->next=slow->next;
        return head;
    }
};