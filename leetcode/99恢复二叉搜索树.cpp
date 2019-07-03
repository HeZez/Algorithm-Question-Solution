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
    二叉搜索树中的两个节点被错误地交换。
    请在不改变其结构的情况下，恢复这棵树。

    示例 1:

    输入: [1,3,null,null,2]

       1
      /
     3
      \
       2

    输出: [3,1,null,null,2]

       3
      /
     1
      \
       2
       
    示例 2:
    输入: [3,1,4,null,null,2]

      3
     / \
    1   4
       /
      2

    输出: [2,1,4,null,null,3]

      2
     / \
    1   4
       /
      3
      
    进阶:
    使用 O(n) 空间复杂度的解法很容易实现。
    你能想出一个只使用常数空间的解决方案吗？
*/
/*
    思路嘛，我想到了上一道题判断二叉搜索树的那道题
    中序遍历完全升序代表是二叉搜索树，
    这道题中有两个节点被错误交换，也就是说将这两个值交换位置之后，又会变成完全升序
    目的就是找到这两个值的位置之后交换
    而完全升序的逆序位置在哪里呢 如果不考虑在边界上的情况
    以[3,1,4,null,null,2]为例
    其中序遍历结果为1 3 2 4
    其中3比左右都大，2比左右都小，就是这两个位置是错误的，
    因为如果是升序的话，一个值应该大于左边，小于右边
    
    不过这样的话有些人有疑问，因为递归的时候空间是O(logN)的，并不是O(1)
*/
class Solution {
public:
    
    TreeNode* errorNode1;
    TreeNode* errorNode2;
    TreeNode* pre;
    void inorder(TreeNode* root)
    {
        if(root==NULL)
            return ;
        inorder(root->left);
        if(pre!=NULL && pre->val>root->val)
        {
            // 这里借鉴了大佬的写法，很巧妙
            if(errorNode1==NULL)
                errorNode1=pre;
            errorNode2=root; 
        }
        pre=root;
        inorder(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        inorder(root);
        int temp=errorNode1->val;
        errorNode1->val=errorNode2->val;
        errorNode2->val=temp;
    }
};