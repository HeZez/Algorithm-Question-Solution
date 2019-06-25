/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
    给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

    示例 1:

    输入: 1->1->2
    输出: 1->2
    示例 2:

    输入: 1->1->2->3->3
    输出: 1->2->3
*/
/*
    直抒胸臆，用一个指针从头开始遍历，看下一个节点的值和当前节点的值是否相同，
    如果相同就把下一个节点删去，否则移动指针
*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL)
            return head;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            if(temp->next==NULL)
                break;
            else
            {
                if(temp->val==temp->next->val)
                    temp->next=temp->next->next;
                else
                    temp=temp->next;
            }
        }
        return head;
    }
};