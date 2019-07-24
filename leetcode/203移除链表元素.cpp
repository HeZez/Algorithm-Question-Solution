/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
    删除链表中等于给定值 val 的所有节点。
    
    示例:
    输入: 1->2->6->3->4->5->6, val = 6
    输出: 1->2->3->4->5
*/
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        /*
        ListNode* pre=NULL;
        ListNode* cur=head;
        ListNode* res=head;
        
        while(cur!=NULL)
        {
            if(cur->val==val)
            {
                if(pre==NULL)
                {
                    res=cur->next;
                    cur=cur->next;
                }
                else
                {
                    pre->next=cur->next;
                    cur=cur->next;
                }
            }
            else
            {
                pre=cur;
                cur=cur->next;
            }
        }
        */
        // 设立虚拟头结点
        ListNode* cur=new ListNode(0);
        cur->next=head;
        ListNode* res=cur;
        while(cur->next!=NULL)
        {
            if(cur->next->val==val)
            {
                cur->next=cur->next->next;
            }
            else
                cur=cur->next;
        }
        return res->next;
    }
};