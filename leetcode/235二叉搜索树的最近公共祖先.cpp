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
    给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。

    百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

    例如，给定如下二叉搜索树:  root = [6,2,8,0,4,7,9,null,null,3,5]

    示例 1:

    输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
    输出: 6 
    解释: 节点 2 和节点 8 的最近公共祖先是 6。
    示例 2:

    输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
    输出: 2
    解释: 节点 2 和节点 4 的最近公共祖先是 2, 因为根据定义最近公共祖先节点可以为节点本身。


    说明:

    所有节点的值都是唯一的。
    p、q 为不同节点且均存在于给定的二叉搜索树中。
*/
/*
    二叉搜索树特性，给出的两个节点，和根节点比较大小，根据二叉搜索树的特性 从上向下找
    如果当前根节点比左大右小，当前就是最近公共祖先
    比两个都大 找左子树
    比两个都小 找右子树
*/
class Solution {

private:
    TreeNode* res;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val<q->val)
            lowestCommonAncestorCore(root, p, q);
        else
            lowestCommonAncestorCore(root, q, p);
        return res;
    }
    
    void lowestCommonAncestorCore(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 递归边界
        if(root->val>=p->val&&root->val<=q->val)
            res=root;
        else if(root->val<p->val)
            lowestCommonAncestorCore(root->right, p, q);
        else if(root->val>q->val)
            lowestCommonAncestorCore(root->left, p, q);      
    }
};