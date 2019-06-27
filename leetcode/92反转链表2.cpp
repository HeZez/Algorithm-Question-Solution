/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
    反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。

    说明:
    1 ≤ m ≤ n ≤ 链表长度。

    示例:

    输入: 1->2->3->4->5->NULL, m = 2, n = 4
    输出: 1->4->3->2->5->NULL
*/
/*
    不考虑额外存储空间的话，可以用栈来实现
    不过题中的要求是一趟扫描完成翻转
    那就记录m的前一个指针，之后用头插法向后面插入节点，直到第n个，之后的顺序插入
*/
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head==NULL)
            return head;
        int count=1;
        ListNode* newHead=new ListNode(0);
        ListNode* temp1=head;
        ListNode* temp2=newHead;
        while(temp1!=NULL)
        {
            if(count==m)
                break;
            temp2->next=new ListNode(temp1->val);
            temp1=temp1->next;
            temp2=temp2->next;
            count++;
        }
        
        for(int i=m;i<=n;i++)
        {
            //头插法
            ListNode* tempNode=new ListNode(temp1->val);
            tempNode->next=temp2->next;
            temp2->next=tempNode;
            temp1=temp1->next;
        }
        
        for(int i=m;i<=n;i++)
            temp2=temp2->next;
        while(temp1!=NULL)
        {
            temp2->next=new ListNode(temp1->val);
            temp1=temp1->next;
            temp2=temp2->next;
        }
        
        return newHead->next;
    }
};