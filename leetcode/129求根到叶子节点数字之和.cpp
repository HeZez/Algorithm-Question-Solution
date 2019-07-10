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
    给定一个二叉树，它的每个结点都存放一个 0-9 的数字，每条从根到叶子节点的路径都代表一个数字。
    例如，从根到叶子节点路径 1->2->3 代表数字 123。
    计算从根到叶子节点生成的所有数字之和。
    说明: 叶子节点是指没有子节点的节点。

    示例 1:
    输入: [1,2,3]
        1
       / \
      2   3
    输出: 25
    解释:
    从根到叶子节点路径 1->2 代表数字 12.
    从根到叶子节点路径 1->3 代表数字 13.
    因此，数字总和 = 12 + 13 = 25.
    
    示例 2:
    输入: [4,9,0,5,1]
        4
       / \
      9   0
     / \
    5   1
    输出: 1026
    解释:
    从根到叶子节点路径 4->9->5 代表数字 495.
    从根到叶子节点路径 4->9->1 代表数字 491.
    从根到叶子节点路径 4->0 代表数字 40.
    因此，数字总和 = 495 + 491 + 40 = 1026.
*/
/*
    dfs并记录经过路径中的节点，如何实现？
    还是陷入了误区，其实不用记录路径中节点，只要从上到下求出一条路径和就行了，无需记录具体节点的值
*/
class Solution {
public:
    vector<int> results;
    void dfs(TreeNode* root, int num)
    {
        // 递归边界
        if(root==NULL)
            return;
        else if(root->left==NULL&& root->right==NULL)
        {
            num=num*10+root->val;
            results.push_back(num);
            return ;
        }
        num=num*10+root->val;
        dfs(root->left, num);
        dfs(root->right, num);
    }
    
    int sumNumbers(TreeNode* root) {
        if(root==NULL)
            return 0;
        dfs(root, 0);
        int result=0;
        for(auto res: results)
            result+=res;
        return result;
    }
};