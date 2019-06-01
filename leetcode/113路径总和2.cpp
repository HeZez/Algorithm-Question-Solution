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
    给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。
    说明: 叶子节点是指没有子节点的节点。
    示例:
    给定如下二叉树，以及目标和 sum = 22，

                  5
                 / \
                4   8
               /   / \
              11  13  4
             /  \    / \
            7    2  5   1
    返回:

    [
       [5,4,11,2],
       [5,8,4,5]
    ]
*/

/*
    尝试使用循环的dfs方法来记录路径，但是没想明白
    
    方法还是大佬的 递归实现dfs+回溯 记录路径
*/

class Solution {
private:
    vector<vector<int>> result;
    vector<int> temp;

public:
    void dfs(TreeNode* root, int sum, int sumTemp)
    {
        if(root==NULL)
            return ;
        sumTemp+=root->val;
        temp.push_back(root->val);
        if(root->left==NULL && root->right==NULL)
        {
            if(sumTemp==sum)
                result.push_back(temp);
        }
        dfs(root->left, sum, sumTemp);
        dfs(root->right, sum, sumTemp);
        temp.pop_back();
        sumTemp-=root->val;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        int sumTemp=0;
        if(root==NULL)
            return result; 
        dfs(root, sum, sumTemp);

        return result;
    }
};