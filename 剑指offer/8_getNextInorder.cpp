/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
/*
    题目描述
    给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
    注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
*/
/*
    两大种情况：
    一、当前节点有右子树：这时下一个结点是右子树的最左子节点
    二、当前节点没有右子树：这时分为两种情况讨论
        1.如果当前节点是父结点的左孩子，下一个结点就是父结点
        2.如果当前节点是父结点的右孩子，则向上搜索父结点，直到有一个结点是父结点的左孩子，下一个节点就是这个结点的父结点
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode==NULL)
            return NULL;
        if(pNode->right!=NULL)  // 右子树不为空
        {
            pNode=pNode->right;
            while(pNode->left!=NULL)
                pNode=pNode->left;
            return pNode;
        }
        else
        {
            if(pNode->next==NULL) // 当前节点是根节点并且没有右子树 没有下一个结点 返回空
                return NULL;
            else                  // 当前节点没右子树
            {
                while(pNode->next!=NULL)
                {
                    if(pNode->next->left==pNode)
                        break;
                    pNode=pNode->next;
                }
                return pNode->next;
            }
        }
    }
};