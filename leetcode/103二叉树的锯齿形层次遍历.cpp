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
        给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

    例如：
    给定二叉树 [3,9,20,null,null,15,7],

        3
       / \
      9  20
        /  \
       15   7
    返回锯齿形层次遍历如下：

    [
      [3],
      [20,9],
      [15,7]
    ]
*/
/*
    用两个栈来实现
*/
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        vector<vector<int>> result;
        if(root==NULL)
            return result;
        TreeNode* tn;
        s1.push(root);
        while(!s1.empty()||!s2.empty())
        {
            vector<int> temp1;
            while(!s1.empty())
            {
                tn=s1.top();
                s1.pop();
                temp1.push_back(tn->val);
                if(tn->left)
                    s2.push(tn->left);
                if(tn->right)
                    s2.push(tn->right);
            }
            if(!temp1.empty())
                result.push_back(temp1);
            
            vector<int> temp2;
            while(!s2.empty())
            {
                tn=s2.top();
                s2.pop();
                temp2.push_back(tn->val);
                if(tn->right)
                    s1.push(tn->right);
                if(tn->left)
                    s1.push(tn->left);
            }
            if(!temp2.empty())
                result.push_back(temp2);
        }
        return result;
    }
};