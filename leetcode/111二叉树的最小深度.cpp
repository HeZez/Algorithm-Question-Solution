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
    给定一个二叉树，找出其最小深度。

    最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

    说明: 叶子节点是指没有子节点的节点。

    示例:

    给定二叉树 [3,9,20,null,null,15,7],

        3
       / \
      9  20
        /  \
       15   7
    返回它的最小深度  2.
*/
/*
    方法借鉴了 110.平衡二叉树
    
    注意一个情况就是[1, 2] 这棵树的深度是1而不是2，因为根节点只有一个叶子，而题目中的定义是根节点到最近叶子的最短路径
*/
class Solution {
private:
    int minDepthCore(TreeNode* root) 
    {
        if(root==NULL)
            return 0;
        int leftHeight=minDepthCore(root->left);
        int rightHeight=minDepthCore(root->right);
        // 返回的时候看一下，如果有一个结果是0，就不去考虑他
        // 这个三目运算来自评论区大佬  很巧妙
        return (leftHeight&&rightHeight)?min(leftHeight, rightHeight)+1 : 1+rightHeight+leftHeight;
    }
    
public:
    int minDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        return minDepthCore(root);
    }
};