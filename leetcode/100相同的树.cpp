/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
    给定两个二叉树，编写一个函数来检验它们是否相同。

    如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。

    示例 1:

    输入:       1         1
              / \       / \
             2   3     2   3

            [1,2,3],   [1,2,3]

    输出: true
    示例 2:

    输入:      1          1
              /           \
             2             2

            [1,2],     [1,null,2]

    输出: false
    示例 3:

    输入:       1         1
              / \       / \
             2   1     1   2

            [1,2,1],   [1,1,2]

    输出: false

*/
/*
    根据定义来看，两种遍历方式才能确定一棵树的具体结构，
    也就是说从前序 中序 后序中选择两种，看两棵树的遍历顺序是否相同
    或者直接采用相同的遍历方式 一块遍历两棵树
*/

class Solution {
public:
    bool isSame(TreeNode* p, TreeNode* q)
    {
        if(p==NULL && q==NULL)
            return true;
        if((p!=NULL && q==NULL) || (p==NULL && q!=NULL))
            return false;
        bool root=false;
        if(p->val==q->val)
            root=true;
        return isSame(p->left, q->left)&&root&&isSame(p->right, q->right);
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // 前序和中序遍历结果相同才是相同的树
        return isSame(p, q);
    }
};