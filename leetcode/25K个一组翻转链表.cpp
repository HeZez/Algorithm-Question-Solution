/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
    题目描述
    给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
    k 是一个正整数，它的值小于或等于链表的长度。
    如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
    示例 :
    给定这个链表：1->2->3->4->5
    当 k = 2 时，应当返回: 2->1->4->3->5
    当 k = 3 时，应当返回: 3->2->1->4->5
    说明 :

    你的算法只能使用常数的额外空间。
    你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
*/

/*
    大佬使用头插法结合递归实现的
    头插法：平时用的比较少，有点忘了 头插法的流程是这样的
    要有一个链表头
    头->2->1   插入元素3  插入后结果是 头->3->2->1
*/

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head)
            return head;
        ListNode* p=head;
        ListNode* q=NULL;
        int len=0;
        while(p&&len<k)
        {
            p=p->next;
            len++;
        }
        // 如果剩余的部分不够k个  不进行翻转直接返回
        if(len<k)
            return head;
        
        // 创建一个头结点
        ListNode h(0);
        p=head;
        // 注意这个循环的次数  len在一开始等于k，循环进行k次
        while(len>0)
        {
            cout<<1<<endl;
            q=p;
            p=p->next;
            // 头插法 把q插入到头结点后面
            q->next=h.next;
            h.next=q;
            len--;
        }
        // 递归处理k个  head这个指针在经过翻转之后一个在每组k个元素的最后了
        head->next=reverseKGroup(p,k);
        return h.next;
    }
};