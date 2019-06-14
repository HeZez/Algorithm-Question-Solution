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
    给定一个二叉树，判断它是否是高度平衡的二叉树。

    本题中，一棵高度平衡二叉树定义为：

    一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。

    示例 1:

    给定二叉树 [3,9,20,null,null,15,7]

        3
       / \
      9  20
        /  \
       15   7
    返回 true 。

    示例 2:

    给定二叉树 [1,2,2,3,3,null,null,4,4]

           1
          / \
         2   2
        / \
       3   3
      / \
     4   4
    返回 false 。
*/
/*
    两种思路
    第一种比较直接 根据平衡二叉树的定义，要求当前节点的左右子树深度差值的绝对值不超过1，两个子树也有同样的要求
    那么就可以定义一个求高度的函数，来进行判断 时间复杂度为O（n^2）
    
    第二种思路
*/
/*
  // 第一种思路  
class Solution {
public:
    int deepth(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        return max(deepth(root->left), deepth(root->right))+1;
    }
    
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
            return true;
        int left=deepth(root->left);
        int right=deepth(root->right);
        return abs(left-right)<=1 &&isBalanced(root->left)&&isBalanced(root->right);
    }
};
*/
// 第二种思路  
class Solution {
public:
    int dfs(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int left=dfs(root->left);
        if(left==-1)
            return -1;
        int right=dfs(root->right);
        if(right==-1)
            return -1;
        if(abs(left-right)>1)
            return -1;
        
            
        return max(left, right)+1;
    }
    
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
            return true;
        return dfs(root)!=-1;
    }
};