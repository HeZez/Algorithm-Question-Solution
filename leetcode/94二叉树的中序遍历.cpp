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
    给定一个二叉树，返回它的中序 遍历。

    示例:

    输入: [1,null,2,3]
       1
        \
         2
        /
       3

    输出: [1,3,2]
    进阶: 递归算法很简单，你可以通过迭代算法完成吗？
*/
class Solution {
public:
    vector<int> result;
    vector<int> inorderTraversal(TreeNode* root) {
        
        inOrderByCyc(root);
        return result;
    }
    /*
    void inorder(TreeNode* root)
    {
        // 递归中序遍历
        if(root==NULL)
            return ;
        inorder(root->left);
        result.push_back(root->val);
        inorder(root->right);
    }
    */
    
    // 循环中序遍历 栈辅助实现
    void inOrderByCyc(TreeNode* root)
    {
        stack<TreeNode*> s1;
        TreeNode* temp=root;
        while(!s1.empty()||temp!=NULL)
        {
            while(temp!=NULL)
            {
                s1.push(temp);
                temp=temp->left;
            }
            if(!s1.empty())
            {
                temp=s1.top();
                s1.pop();
                result.push_back(temp->val);
                temp=temp->right;
            }   
        }
    }
    
    
};