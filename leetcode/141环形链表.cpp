/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
    给定一个链表，判断链表中是否有环。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。

 

示例 1：

输入：head = [3,2,0,-4], pos = 1
输出：true
解释：链表中有一个环，其尾部连接到第二个节点。


示例 2：

输入：head = [1,2], pos = 0
输出：true
解释：链表中有一个环，其尾部连接到第一个节点。


示例 3：

输入：head = [1], pos = -1
输出：false
解释：链表中没有环。
 

进阶：
你能用 O(1)（即，常量）内存解决此问题吗？
*/
/*
    如果只是判断链表中是否有环，使用快慢指针看两个指针是否相遇即可，
    
    但是这道题还要求返回环的入口索引，需要一些变化
    这个问题可以先用快慢指针确定链表中是否有环，
    如果有环，再确定环中节点个数，之后再将一个指针向前移动环中节点个数那么多步
    之后另一个指针从链表头开始，两个指针同时步进，直到相遇，相遇的那个位置就是环的入口
    
    尴尬....没仔细看题，题目要求其实就是判断有没有环。。。。上面的说法可以记住，是找环入口的方法
*/
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL)
            return false;
        ListNode* one=head;
        ListNode* two=head;
        while(true)
        {
            if(one->next!=NULL&&one->next->next!=NULL)
                one=one->next->next;
            else
                break;
            if(two->next!=NULL)
                two=two->next;
            else
                break;
            if(one==two)
                return true;
        }
        return false;
    }
};