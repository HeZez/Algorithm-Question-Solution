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
    给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。
    说明: 叶子节点是指没有子节点的节点。

    示例: 
    给定如下二叉树，以及目标和 sum = 22，

                  5
                 / \
                4   8
               /   / \
              11  13  4
             /  \      \
            7    2      1
    返回 true, 因为存在目标和为 22 的根节点到叶子节点的路径 5->4->11->2。
*/

/*
    bfs并在一条路径结束时查看路径和  栈中节点需要一个数字存当前路径和  注意代码中pair<>这一数据结构的用法， 以及访问其中数据的方法 这是我第一次见到并使用这种数据结构。
*/

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==NULL)
            return false;
        stack<pair<TreeNode*, int> > s;
        bool result=false;
        pair<TreeNode*, int> tN;
        s.push({root, root->val});
        while(!s.empty())
        {
            tN=s.top();
            if(tN.first->left==NULL&&tN.first->right==NULL)
            {
                if(tN.second==sum)
                {
                    result=true;
                    break;
                }
            }
            s.pop();
            if(tN.first->right)
                s.push({tN.first->right, tN.second+tN.first->right->val});
            if(tN.first->left)
                s.push({tN.first->left, tN.second+tN.first->left->val});   
        }
        return result;
    }
};