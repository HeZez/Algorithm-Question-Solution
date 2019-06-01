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
    给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

    例如：
    给定二叉树 [3,9,20,null,null,15,7],

        3
       / \
      9  20
        /  \
       15   7
    返回其自底向上的层次遍历为：

    [
      [15,7],
      [9,20],
      [3]
    ]
*/

/*
  和102题类似，在得到结果后将结果反转  
*/

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> results;
        if(root==NULL)
            return results;
        queue<TreeNode*> q;
        TreeNode* temp;
        int len=0;
        q.push(root);
        while(!q.empty())
        {
            len=q.size();
            vector<int> result;
            while(len--)
            {
                temp=q.front();
                result.push_back(temp->val);
                q.pop();
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            results.push_back(result);
        }
        reverse(results.begin(), results.end());
        return results;
    }
};