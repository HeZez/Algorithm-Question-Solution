/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
    给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
    将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…

    你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

    示例 1:

    给定链表 1->2->3->4, 重新排列为 1->4->2->3.
    示例 2:

    给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.
*/

/*
    题目中没要求只使用O(1)的额外空间，为了能够在O(1)时间复杂度访问所有节点，所以存一下整个链表的节点
    观察一下，原链表有奇数个节点，那么从后向前移动的节点有n/2-0.5个  例如5个节点移动了2个
    原链表有偶数个节点，那么移动了n/2-1个节点，例如4移动1 6移动2
    
    评论区的意见是，题目要求交换，就不应该使用额外的存储空间，使用快慢指针来找到链表中点
    之后把后半部分翻转，插入到前半部分中。快慢指针应该是这道题的一种更优的解法
*/
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head==NULL)
            return ;
        vector<ListNode*> nodeList;
        ListNode* temp=head;
        while(temp)
        {
            nodeList.push_back(temp);
            temp=temp->next;
        }
        int len=nodeList.size();
        int nums=0;
        if(len%2)
            nums=len/2;
        else
            nums=len/2-1;
        len-=1;
        // 移动节点
        for(int i=0;i<nums;i++)
        {
            // 把节点插进去
            nodeList[len-i]->next=nodeList[i]->next;
            nodeList[i]->next=nodeList[len-i];
        }
        // 注意 找到重排后链表的尾结点，进行处理
        nodeList[len-nums]->next=NULL;
        return ;
    }
};