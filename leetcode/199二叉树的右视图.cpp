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
    给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

    示例:

    输入: [1,2,3,null,5,null,4]
    输出: [1, 3, 4]
    解释:

       1            <---
     /   \
    2     3         <---
     \     \
      5     4       <---
*/
/*
    可以借鉴二叉树层次遍历的思路， 找到每一层中最右边的节点
    可以用两个队列来实现层次遍历，用两个vector模拟队列操作
*/
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root==NULL)
            return res;
        vector<TreeNode*> q1;
        vector<TreeNode*> q2;
        q1.push_back(root);
        TreeNode* temp;
        while(!q1.empty()||!q2.empty())
        {
            if(!q1.empty())
            {
                res.push_back(q1[q1.size()-1]->val);
                while(!q1.empty())
                {
                    temp=q1[0];
                    q1.erase(q1.begin());
                    if(temp->left)
                        q2.push_back(temp->left);
                    if(temp->right)
                        q2.push_back(temp->right);
                }
            }
            else if(!q2.empty())
            {
                res.push_back(q2[q2.size()-1]->val);
                while(!q2.empty())
                {
                    temp=q2[0];
                    q2.erase(q2.begin());
                    if(temp->left)
                        q1.push_back(temp->left);
                    if(temp->right)
                        q1.push_back(temp->right);
                }
            }
        }
        return res;
    }
};