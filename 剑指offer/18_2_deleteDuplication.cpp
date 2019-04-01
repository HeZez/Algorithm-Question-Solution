/*
    题目描述
    在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 
    例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
*/

/*
    需要三个记录位置的指针，记录重复元素的前一个位置，记录重复元素的第一个位置，记录重复元素的最后一个位置
    在删除时，将第一个重复元素前面的位置链接到最后一个重复元素后面的元素即可，
    如果开头的元素是重复的，那么记录前一个元素的指针是空指针，注意这个情况，
    再就是需要注意整个数组都被删除的情况。
*/

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        ListNode* preNode=NULL;
        ListNode* p=pHead;
        ListNode* q=NULL;
        if(pHead==NULL)
            return NULL;
        if(pHead->next==NULL)
            return pHead;
        while(p!=NULL)
        {
            if(p->next!=NULL&&p->next->val==p->val)
            {
                q=p->next;
                while(q!=NULL&&q->next!=NULL&&q->next->val==q->val)
                    q=q->next;
                if(p==pHead)
                {
                    pHead=q->next;
                }
                else
                {
                    preNode->next=q->next;
                }
                p=q->next;
            }
            else
            {
                preNode=p;
                p=p->next;
            }
        }
        return pHead;
    }
};