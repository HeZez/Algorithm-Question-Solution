/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
    给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。

    示例 1:

    输入: 1->2->3->4->5->NULL, k = 2
    输出: 4->5->1->2->3->NULL
    解释:
    向右旋转 1 步: 5->1->2->3->4->NULL
    向右旋转 2 步: 4->5->1->2->3->NULL
    示例 2:

    输入: 0->1->2->NULL, k = 4
    输出: 2->0->1->NULL
    解释:
    向右旋转 1 步: 2->0->1->NULL
    向右旋转 2 步: 1->2->0->NULL
    向右旋转 3 步: 0->1->2->NULL
    向右旋转 4 步: 2->0->1->NULL
*/

/*
    最笨的方法，三个指针分别指向第一个元素，倒数第二个和倒数第一个数，调换一次，之后重新找，重复k次 O（kn）
    看了评论区，其实这个问题不用循环k次，观察一下，其实就是将倒数第k个数开始的后半部分挪到前半部分去
*/

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)
            return head;
        int len=0;
        ListNode* temp=head;
        while(temp)
        {
            len++;
            temp=temp->next;
        }
        // 找到分离的位置
        int pos=len-k%len+1;   // 后半部分的第一个元素是第几个数
        if(pos==len+1)
            return head;  // 这个时候结果没变化
        
        ListNode* behindHead;
        ListNode* behindEnd;
        ListNode* preEnd=NULL;
        temp=head;
        for(int i=1;i<=len;i++)
        {
            if(i==pos-1)
                preEnd=temp;
            if(i==pos)
                behindHead=temp;
            if(i==len)
                behindEnd=temp;
            temp=temp->next;
        }
        if(preEnd!=NULL)
            preEnd->next=NULL;
        behindEnd->next=head;
        
        return behindHead;
    }
};