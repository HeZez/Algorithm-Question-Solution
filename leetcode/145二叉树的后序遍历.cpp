/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    /*
    // 递归解法
    vector<int> res;
    void postorderTraversalCore(TreeNode* root)
    {
        // 递归边界
        if(root==NULL)
            return ;
        postorderTraversalCore(root->left);
        postorderTraversalCore(root->right);
        res.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        postorderTraversalCore(root);
        return res;
    }
    */
    
    // 迭代解法
    // 后序遍历的迭代解法有一点复杂的地方，主要是一个根节点如果有子树，那么这个根节点在第一次被访问的时候应该跳过
    // 等到子树遍历完毕之后再遍历该根节点，关键是如何实现这一判断
    // 用一个pre指针来记录上一个遍历的节点，如果上一个遍历的节点是自己的子树就遍历该值，否则入栈
    // 用stack辅助实现
    vector<int> postorderTraversal(TreeNode* root) {
        
        TreeNode* pre=NULL;
        vector<int> res;
        if(root==NULL)
            return res;
        TreeNode* cur=root;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty())
        {
            cur=s.top();
            
            if( 
                (cur->left==NULL&&cur->right==NULL) 
               || ( pre!=NULL&&(cur->left==pre||cur->right==pre) ) 
              )
            {
                res.push_back(cur->val);
                pre=cur;
                s.pop();
            }
            else
            {
                if(cur->right)
                    s.push(cur->right);
                if(cur->left)
                    s.push(cur->left);
            }
        }
        return res;  
    }
};