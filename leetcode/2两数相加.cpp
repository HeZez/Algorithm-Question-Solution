/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
    给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

    如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

    您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

    示例：

    输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
    输出：7 -> 0 -> 8
    原因：342 + 465 = 807
*/
/*
    可以转成数字相加，之后再把相加结果拆成链表，但是首先有一个越界问题，如果是大数不好表示
    其次这样效率没有直接按位算快
    
    因为两个链表是倒着存的，所以第一位就是原数字的个位数，可以将两个数从个位数对齐，
    逐位相加计算直到没有共同位，之后将某个数字剩余的部分再加到结果上， 注意出力进位
    
*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int jinwei=0;
        int gewei=0;
        ListNode* result=new ListNode(0);
        ListNode* tempRes=result; //记住根节点
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        // bool flag1=true;  //用来标识该数字是否被遍历完成
        // bool flag2=true;  
        /*
          我的思路就是模拟加法运算各位相加与进位的操作
        */
        while(temp1&&temp2)
        {
            gewei=(temp1->val+temp2->val+jinwei)%10;
            jinwei=(temp1->val+temp2->val+jinwei)/10;
            // cout<<gewei;
            temp1=temp1->next;
            temp2=temp2->next;
            ListNode* temp=new ListNode(gewei); 
            tempRes->next=temp;
            tempRes=tempRes->next;
            // result->val=gewei;
        }
        while(temp1)
        {
            gewei=(temp1->val+jinwei)%10;
            jinwei=(temp1->val+jinwei)/10;
            temp1=temp1->next;
            ListNode* temp=new ListNode(gewei); 
            tempRes->next=temp;
            tempRes=tempRes->next;
        }
        while(temp2)
        {
            gewei=(temp2->val+jinwei)%10;
            jinwei=(temp2->val+jinwei)/10;
            temp2=temp2->next;
            ListNode* temp=new ListNode(gewei); 
            tempRes->next=temp;
            tempRes=tempRes->next;
        }
        if(jinwei!=0)
        {
            ListNode* temp=new ListNode(jinwei); 
            tempRes->next=temp;
            tempRes=tempRes->next;
        }
            
        return result->next;
    }
};