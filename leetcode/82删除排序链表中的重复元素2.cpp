/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
    给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。

    示例 1:
    输入: 1->2->3->3->4->4->5
    输出: 1->2->5
    
    示例 2:
    输入: 1->1->1->2->3
    输出: 2->3
*/
/*
    用两个指针，一个指向重复部分的前一个元素，一个进行遍历
    pre指针最开始置为空，temp开始遍历，如果下一个不是重复的pre=temp之后temp向前移动
    注意： 这里的处理方式是将重复的元素全部去掉，而不是保留一个重复的元素。所以可以不用保留重复部分其中的一个
*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // 这个写法很别扭，我现在思路不太清楚，特别是在循环的条线上，写的太繁琐，想办法简化一下。
        ListNode* pre=NULL;    // 前一个
        ListNode* temp=head;   // 遍历用的
        while(temp!=NULL && temp->next!=NULL)
        {
            if(temp->val!=temp->next->val)
            {
                pre=temp;
                temp=temp->next;
            }
            else
            {
                while(temp->next!=NULL&&temp->val==temp->next->val)
                {
                        temp=temp->next;
                }
                if(pre==NULL)
                    head=temp->next;
                else
                    pre->next=temp->next;
                temp=temp->next;
            }
        }
        return head;
    }
};