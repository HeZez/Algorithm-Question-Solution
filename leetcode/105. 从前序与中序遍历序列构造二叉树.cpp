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
    根据一棵树的前序遍历与中序遍历构造二叉树。
    注意:
    你可以假设树中没有重复的元素。

    例如，给出

    前序遍历 preorder = [3,9,20,15,7]
    中序遍历 inorder = [9,3,15,20,7]
    返回如下的二叉树：

        3
       / \
      9  20
        /  \
       15   7
*/

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int pre_left, int pre_right, int in_left, int in_right)
    {
        if(pre_left>pre_right||in_left>in_right)
            return NULL;
        int rootval=preorder[pre_left];
        TreeNode* root=new TreeNode(rootval);
        int index=distance(inorder.begin(), find(inorder.begin(),inorder.end(),rootval));
        int left_nums=index-in_left;
        int right_nums=in_right-index;
        root->left=buildTree(preorder,inorder,pre_left+1,pre_left+left_nums,in_left,index-1);
        root->right=buildTree(preorder,inorder,pre_left+left_nums+1,pre_right,index+1,in_right);
        return root;
    }
};