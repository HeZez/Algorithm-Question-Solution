/*
    题目描述
    给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。
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
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        //应用双指针，先找到一个环中的结点，之后统计环中一共有多少个结点
        //接下来再使用双指针，先将一个指针向前移动，移动的步数等于环中结点的个数
        //之后相同速度同时移动两个指针，相遇时就是环的入口
        ListNode* left=pHead;
        ListNode* right=pHead;
        int count=1;
        if(pHead==NULL)
            return NULL;
        while(true)
        {
            left=left->next;
            if(right->next!=NULL&&right->next->next!=NULL)
                right=right->next->next;
            else
                return NULL;
            if(left==right)
                break;
        }
        while(true)
        {
            right=right->next;
            if(right!=left)
                count++;
            else
                break;
        }
        left=pHead;
        right=pHead;
        for(int i=0;i<count;i++)
            right=right->next;
        while(left!=right)
        {
            left=left->next;
            right=right->next;
        }
        return left;
    }
};