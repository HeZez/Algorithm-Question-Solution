/*
    题目描述
    输入一个链表，反转链表后，输出新链表的表头。
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
    ListNode* ReverseList(ListNode* pHead) {
        /*
        //用一个栈来辅助解决这个问题，不过这似乎并不是这道题本身想要考察的方法
        stack<int> temp;
        ListNode* node=pHead;
        while(node!=NULL)
        {
            temp.push(node->val);
            node=node->next;
        }
        node=pHead;
        while(node!=NULL)
        {
            node->val=temp.top();
            temp.pop();
            node=node->next;
        }
        return pHead;
        */
        /*
        // 用迭代的方式来完成
        ListNode* node=pHead;
        ListNode* preNode=NULL;
        ListNode* result=NULL;
        while(node!=NULL)
        {
            ListNode* next=node->next;
            if(next==NULL)
                result=node;
            node->next=preNode;
            preNode=node;
            node=next;
        }
        return result;
        */
        //递归解法
        if(pHead==NULL||pHead->next==NULL)
            return pHead;
        // 递归先达到链表末尾，再进行翻转
        ListNode* newHead=ReverseList(pHead->next);
        pHead->next->next=pHead;
        pHead->next=NULL;
        return newHead;
    }
};