/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
/*
    题目描述
    输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），
    返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
*/
class Solution {
public:
    /*
    // 第一种方法，用一个哈希表来存随机指针，用O(n)的空间复杂度换O(n)的时间复杂度
    // 如果是最暴力的方法就是先顺序复制链表，之后再遍历原链表的随机指针，在复制的链表上查找，这样时间复杂度是O(n^2)
    // 为了缩减查找时间，可以在顺序复制链表的时候创建一个哈希表，建立原结点和复制的结点之间的映射
    // 例如结点B的映射B' 那么假如在设置随机指针的时候 假如A->random=B 直接用哈希表mao[A->random]=B' 就可以O（1）时间找到B'
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead==NULL)
            return pHead;
        RandomListNode* result=new RandomListNode(pHead->label);
        RandomListNode* nodeNow=result;
        RandomListNode* pNode=pHead;
        map<RandomListNode*, RandomListNode*> pointerMap;
        while(pNode!=NULL)
        {
            RandomListNode* temp=new RandomListNode(pNode->label);
            temp->next=pNode->next;
            nodeNow->next=temp;
            nodeNow=nodeNow->next;
            pointerMap[pNode]=temp;
            pNode=pNode->next;
        }
        nodeNow=result->next;
        pNode=pHead;
        while(nodeNow!=NULL)
        {
            nodeNow->random=pointerMap[pNode->random];
            nodeNow=nodeNow->next;
            pNode=pNode->next;
        }
        return result->next;
    }
    */
    /* 第二种方法
        还是想办法减少查询random指针的代价
        共分为三步：
        第一步：复制原链表结点并把它插入到原结点的后面，如原为A-B-C-D 第一步完成后为A-A'-B-B'-C-C'-D-D'
        第二步：设置random指针，原链表的结点的random指针指向的结点的下一个结点，就是复制链表中我们要找的的那个结点，将random指针指向它
        第三步：把这个链表拆成两部分，得到一个原链表，一个复制链表，可以交替着将其取出并重新连接
    */
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead==NULL)
            return NULL;
        copyListNext(pHead);
        copyListRandom(pHead);
        return splitList(pHead);
    }
private:
    void copyListNext(RandomListNode* pHead)
    {
        RandomListNode* pNode=pHead;
        while(pNode!=NULL)
        {
            RandomListNode* temp=new RandomListNode(pNode->label);
            temp->next=pNode->next;
            pNode->next=temp;
            pNode=temp->next;
        }
    }
    void copyListRandom(RandomListNode* pHead)
    {
        RandomListNode* pNode=pHead;
        while(pNode!=NULL)
        {
            if(pNode->random!=NULL)      // 要注意pNode->random有可能是NULL
                pNode->next->random=pNode->random->next;
            pNode=pNode->next->next;
        }
    }
    RandomListNode* splitList(RandomListNode* pHead)
    {
        RandomListNode* result=pHead->next;
        RandomListNode* copyNode=result;
        RandomListNode* pNode=pHead;
        pNode->next=copyNode->next;
        pNode=pNode->next;
        while(pNode!=NULL)
        {
            copyNode->next=pNode->next;
            copyNode=copyNode->next;
            pNode->next=copyNode->next;
            pNode=pNode->next;
        }
        return result;
    }
};