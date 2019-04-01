/*
    题目描述
    输入一个链表，输出该链表中倒数第k个结点。
*/

/*
    双指针法
*/

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead==NULL||k==0)
            return NULL;
        ListNode* nodeLeft=pListHead;
        ListNode* nodeRight=pListHead;
        for(unsigned int i=0;i<k;i++)
        {
            //这个k的大小可能不符合要求 比链表的长度长
            if(nodeRight!=NULL)
                nodeRight=nodeRight->next;
            else
                return NULL;
        }
        while(nodeRight!=NULL)
        {
            nodeLeft=nodeLeft->next;
            nodeRight=nodeRight->next;
        }
        return nodeLeft;
    }
};