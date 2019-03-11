/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
/*
    题目描述
    输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。
*/
/*
    方法很多 可以用一个栈辅助，也可以用递归 用递归的话如果链表太长 可能栈溢出
*/
class Solution {
public:
    /*
    // 用栈辅助
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> result;
        stack<int> s1;
        while(head!=NULL)
        {
            s1.push(head->val);
            head=head->next;
        }
        while(!s1.empty())
        {
            result.push_back(s1.top());
            s1.pop();
        }
        return result;
    }
    */
    // 递归写法
    vector<int> result;
    vector<int> printListFromTailToHead(ListNode* head) {
        if(head==nullptr)
            return result;
        printListFromTailToHeadCore(head);
        return result;
    }
private:
    void printListFromTailToHeadCore(ListNode* head) 
    {
        if(head->next!=nullptr)
            printListFromTailToHeadCore(head->next); 
        result.push_back(head->val);
    }
};