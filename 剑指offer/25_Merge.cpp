/*
    题目描述
    输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        /*
        // 迭代解法
        ListNode* result=new ListNode(0);
        ListNode* temp=result;
        if(pHead1==NULL)
            return pHead2;
        if(pHead2==NULL)
            return pHead1;
        // 这个循环的终止条件是1或2不为空时进行循环，当二者都为空时终止循环，这时合并就结束了
        // 也可以当其中一个为空时就终止循环 ，之后判断哪个不为空，将它挂在现有的合并结果后面
        while(pHead1!=NULL||pHead2!=NULL)
        {
            if(pHead1!=NULL&&pHead2==NULL)
            {
                ListNode* newNode=new ListNode(0);
                temp->next=newNode;
                temp=temp->next;
                temp->val=pHead1->val;
                pHead1=pHead1->next;
            }
            else if(pHead1==NULL&&pHead2!=NULL)
            {
                ListNode* newNode=new ListNode(0);
                temp->next=newNode;
                temp=temp->next;
                temp->val=pHead2->val;
                pHead2=pHead2->next;
            }
            else
            {
                if(pHead1->val<=pHead2->val)
                {
                    ListNode* newNode=new ListNode(0);
                    temp->next=newNode;
                    temp=temp->next;
                    temp->val=pHead1->val;
                    pHead1=pHead1->next;
                }
                else
                {
                    ListNode* newNode=new ListNode(0);
                    temp->next=newNode;
                    temp=temp->next;
                    temp->val=pHead2->val;
                    pHead2=pHead2->next;
                }
            }
        }
        // 这两个链表有一个是null的 或者两个都是null的情况在最开始已经判断过了
        // 所以result->next一定不是Null的
        return result->next;
        */
        // 递归解法 简洁许多
        // 思路就是比较两个链表头节点哪个小，把他插入到合并的链表中
        if(pHead1==NULL)
            return pHead2;
        if(pHead2==NULL)
            return pHead1;
        ListNode* result;
        if(pHead1->val<=pHead2->val)
        {
            result=pHead1;
            result->next=Merge(pHead1->next, pHead2);
        }
        else
        {
            result=pHead2;
            result->next=Merge(pHead1, pHead2->next);
        }
        return result;
    }
};