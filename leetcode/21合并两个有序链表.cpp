/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
    将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

    示例：
    输入：1->2->4, 1->3->4
    输出：1->1->2->3->4->4
*/
/*
    正常合并，可以通过全都新创建节点来完成，但是题目似乎希望可以操作原链表链接的方式来完成
    
    可以写个递归的版本，
*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        /*
        // 递归
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        if(l1->val < l2->val)
        {
            l1->next=mergeTwoLists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next=mergeTwoLists(l1, l2->next);
            return l2;
        }
        */
        ListNode* result=new ListNode(0);
        ListNode* resultHead=result;
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        while(temp1!=NULL&&temp2!=NULL)
        {
            if(temp1->val<temp2->val)
            {
                result->next=new ListNode(temp1->val);
                temp1=temp1->next;
                result=result->next;
            }
            else
            {
                result->next=new ListNode(temp2->val);
                temp2=temp2->next;
                result=result->next;
            }
        }
        if(temp1!=NULL)
            result->next=temp1;
        if(temp2!=NULL)
            result->next=temp2;
        
        return resultHead->next;
        
            
    }
};