[-2147483648]/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
    给定一个二叉树，判断其是否是一个有效的二叉搜索树。

    假设一个二叉搜索树具有如下特征：

    节点的左子树只包含小于当前节点的数。
    节点的右子树只包含大于当前节点的数。
    所有左子树和右子树自身必须也是二叉搜索树。
    
    示例 1:
    输入:
        2
       / \
      1   3
    输出: true
    
    示例 2:
    输入:
        5
       / \
      1   4
         / \
        3   6
    输出: false
    解释: 输入为: [5,1,4,null,null,3,6]。
         根节点的值为 5 ，但是其右子节点值为 4 。

*/
/*
    自己的想法就是递归的判断左右子树,根据二叉搜索树的定义进行判断, 但是这样的方法有bug
    无法判断[10,5,15,null,null,6,20]
    
    更为简单的方法是，中序遍历二叉树，判断是否是升序
*/
    
class Solution {
public:
    /*
    // 有bug的方法
    bool isValidBSTCore(TreeNode* root) {
        // 递归边界  到达子节点
        if(root==NULL)
            return true;
        // 定义的话 当前树要求是二叉搜索树，要求当前节点、左子树、右子树全都符合要求
        bool temp=false;
        if(root->left!=NULL || root->right!=NULL)
        {
            if(root->left!=NULL&&root->right!=NULL)
            {
                if(root->left->val<root->val && root->right->val>root->val)
                    temp=true;
            }
            else if(root->left!=NULL&&root->right==NULL)
            {
                if(root->left->val<root->val)
                    temp=true;
            }
            else if(root->left==NULL&&root->right!=NULL)
            {
                if(root->right->val>root->val)
                    temp=true;
            }
        }
        else
        {
            //这时是叶子节点 返回true
            temp=true;
        }
        return temp&&isValidBSTCore(root->left) && isValidBSTCore(root->right);
    }
        
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
            return true;
        return isValidBSTCore(root);
    }
    */
    // 基于中序遍历升序的方法
    
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
            return true;
        // 循环中序遍历
        stack<TreeNode*> s;
        TreeNode* curr=root;
        long last=LONG_MIN;   // 这个地方测试用力会卡int_min的边界.......
        int now=0;
        while(!s.empty()||curr!=NULL)
        {
            if(curr!=NULL)
            {
                s.push(curr);
                curr=curr->left;
            }
            else
            {
                curr=s.top();
                s.pop();
                now=curr->val;
                curr=curr->right;
                if(now<=last)
                    return false;
                else
                    last=now;
            }
        }
        return true;
    }
};