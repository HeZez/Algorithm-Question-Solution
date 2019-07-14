/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
    给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

    为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。

    说明：不允许修改给定的链表。

    示例 1：

    输入：head = [3,2,0,-4], pos = 1
    输出：tail connects to node index 1
    解释：链表中有一个环，其尾部连接到第二个节点。


    示例 2：

    输入：head = [1,2], pos = 0
    输出：tail connects to node index 0
    解释：链表中有一个环，其尾部连接到第一个节点。


    示例 3：

    输入：head = [1], pos = -1
    输出：no cycle
    解释：链表中没有环。

    进阶：
    你是否可以不用额外空间解决此题？
*/

/*
    这道题是找环的入口了，还是用快慢指针
    先用快慢指针确定是否有环，若有环再确定环中节点个数，
    之后再用两个指针，一个向前进n步，n为环中节点个数，另一个从头开始，用相同速度遍历
    二者相遇的时候那个节点就是环的入口
    
    题中还要求不使用额外空间？ 怎么做？
*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL)
            return NULL;
        ListNode* one=head;
        ListNode* two=head;
        bool flag=false;
        ListNode* res=NULL;
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
            {
                flag=true;
                break;
            }
        }
        if(flag)
        {
            int numsOfCyc=1;
            ListNode* temp=one->next;
            while(temp!=one)
            {
                temp=temp->next;
                numsOfCyc++;
            }
            one=head;
            two=head;
            for(int i=1;i<=numsOfCyc;i++)
            {
                one=one->next;
            }
            while(true)
            {
                if(one==two)
                {
                    res=one;
                    break;
                }
                one=one->next;
                two=two->next;
            }
        }
        return res;
    }
};