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
    根据一棵树的中序遍历与后序遍历构造二叉树。

    注意:
    你可以假设树中没有重复的元素。

    例如，给出

    中序遍历 inorder = [9,3,15,20,7]
    后序遍历 postorder = [9,15,7,20,3]
    返回如下的二叉树：

        3
       / \
      9  20
        /  \
       15   7
*/

/*
    过程应该和105题差不多，就是细节有所区别 
*/

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* root=buildTreeCore(inorder, postorder, 0,inorder.size()-1, 0, postorder.size()-1);
        return root;
    }
    
    TreeNode* buildTreeCore(vector<int>& inorder, vector<int>& postorder, int inBegin, int inEnd, int postBegin, int postEnd) {
       
        // 递归边界
        if(inBegin>inEnd||postBegin>postEnd)
            return NULL;
        int rootVal=postorder[postEnd];
         TreeNode* root=new TreeNode(rootVal);
        int index=distance(inorder.begin(), find(inorder.begin(),inorder.end(),rootVal));
        int leftnum=index-inBegin;
        root->left=buildTreeCore(inorder, postorder, inBegin, index-1, postBegin, postBegin+leftnum-1);
        root->right=buildTreeCore(inorder, postorder, index+1, inEnd, postBegin+leftnum, postEnd-1);
        return root;
    }
};