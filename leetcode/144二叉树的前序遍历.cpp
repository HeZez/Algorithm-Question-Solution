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
    给定一个二叉树，返回它的 前序 遍历。

     示例:

    输入: [1,null,2,3]  
       1
        \
         2
        /
       3 

    输出: [1,2,3]

*/
class Solution {
public:
    vector<int> res;
    void preorderTraversalCore(TreeNode* root)
    {
        res.push_back(root->val);
        if(root->left)
            preorderTraversalCore(root->left);
        if(root->right)
            preorderTraversalCore(root->right);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==NULL)
            return res;
        preorderTraversalCore(root);
        return res;
    }
};