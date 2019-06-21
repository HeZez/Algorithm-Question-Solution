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
    将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。

    本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

    示例:

    给定有序数组: [-10,-3,0,5,9],

    一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：

          0
         / \
       -3   9
       /   /
     -10  5
*/
    
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int r=nums.size();
        if(r==0)
            return NULL;
        else
            return getTree(nums,0,r-1);
        }
    TreeNode* getTree(vector<int>& nums, int l, int r)
    {
        if(l<=r)
        {
            int mid=(l+r)/2;
            TreeNode* result=new TreeNode(nums[mid]);
            result->left=getTree(nums,l,mid-1);
            result->right=getTree(nums,mid+1,r);
            return result;
        }
        else
            return NULL;
    }  
};