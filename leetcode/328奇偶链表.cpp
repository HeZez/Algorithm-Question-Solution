/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*
    给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。

    请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。

    示例 1:
    输入: 1->2->3->4->5->NULL
    输出: 1->3->5->2->4->NULL

    示例 2:
    输入: 2->1->3->5->6->4->7->NULL 
    输出: 2->3->6->7->1->5->4->NULL
    说明:

    应当保持奇数节点和偶数节点的相对顺序。
    链表的第一个节点视为奇数节点，第二个节点视为偶数节点，以此类推。
 */
 /*
    想法比较直接 头插法，先把所有奇数位置插进去 之后记住所有偶数位置的头  再把偶数的节点插进去
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL)
            return NULL;
        ListNode* newHead=new ListNode(0);
        ListNode* newPos=newHead;
        ListNode* evenHead=head->next;
        ListNode* pos=head->next;
        // 先插进去一个
        newPos->next=head;
        newPos=newPos->next;
        // 头插法
        while(pos!=NULL)
        {
            // pos所处的位置都是偶数节点
            if(pos->next!=NULL)
            {
                newPos->next=pos->next;
                newPos=newPos->next;
                // cout<<newPos->val<<endl;
                pos->next=pos->next->next;
                pos=pos->next;
            }
            else
            {
                pos=pos->next;
            }
        }

        // 把偶数节点给插进去  这里的偶数节点已经是连在一起的了 直接挂上去就行
        newPos->next=evenHead;
        /*
        while(evenHead!=NULL)
        {
            newPos->next=evenHead;
            evenHead=evenHead->next;
            newPos=newPos->next;
        }
        */
        return newHead->next;
    }
};