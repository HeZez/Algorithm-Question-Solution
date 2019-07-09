/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
    对链表进行插入排序。
    插入排序的动画演示如上。从第一个元素开始，该链表可以被认为已经部分排序（用黑色表示）。
    每次迭代时，从输入数据中移除一个元素（用红色表示），并原地将其插入到已排好序的链表中。



    插入排序算法：
    插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
    每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
    重复直到所有输入数据插入完为止。


    示例 1：

    输入: 4->2->1->3
    输出: 1->2->3->4
    示例 2：

    输入: -1->5->3->4->0
    输出: -1->0->3->4->5
*/
/*
    没要求在原地进行修改，可以新建一个链表向其中插入值
    步骤就可以是，从原链表中拿出一个值，之后在新链表中找到其对应位置
    找对应位置时应使用双指针，在每次插入新值完毕之后，注意重新找新链表头
    新链表头发生改变当且仅当插入的值对应节点就是新链表头
    或者采用和头插法类似的方式，链表头是固定的即可
    这种做法能过，但是看了一下大家似乎都是在原链表上修改的，所以我这种直抒胸臆的方法时间和空间复杂度都太高
    
    有空想一想写一个原地修改的
*/
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* pre;
        ListNode* now;
        if(head==NULL||head->next==NULL)
            return head;
        ListNode* temp=head;
        ListNode* newHead=new ListNode(0);
        while(temp!=NULL)
        {
            now=newHead->next;
            pre=NULL;
            while(now!=NULL)
            {
                if(temp->val<now->val)
                {
                    ListNode* newTemp=new ListNode(temp->val);
                    if(pre==NULL)
                    {
                        newHead->next=newTemp;
                        newTemp->next=now;
                    }
                    else
                    {
                        pre->next=newTemp;
                        newTemp->next=now;
                    }
                    break;
                }
                pre=now;
                now=now->next;
            }
            if(now==NULL)   // 说明新元素被插入到最后
            {
                ListNode* newTemp=new ListNode(temp->val);
                if(pre==NULL)
                    newHead->next=newTemp;
                else
                    pre->next=newTemp;
            }
            temp=temp->next;
        }
        return newHead->next;
    }
};