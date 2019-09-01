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
    给出一个完全二叉树，求出该树的节点个数。

    说明：

    完全二叉树的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h 层，则该层包含 1~ 2h 个节点。

    示例:

    输入: 
        1
       / \
      2   3
     / \  /
    4  5 6

    输出: 6
*/
/*
    直接遍历所有节点记数太low了
    
    大佬的想法是递归判断一个节点的左右子树高度
    由于是完全二叉树 所以子树高度可以通过找左下角节点的高度来确定
    如果左右子树高度相同，最后一层中缺少的部分一定在右子树那里
    于是就返回左子树节点数+1（根节点）+右子树节点递归结果
*/
class Solution {
public:
    
    int countNodes(TreeNode* root) {
        if(root==NULL)
            return 0;
        int hLeft=0,hRight=0;
        hLeft=height(root->left);
        hRight=height(root->right);
        if(hLeft==hRight)
        {
            return (1<<(hLeft))+countNodes(root->right);
        }
        else
        {
            return (1<<(hRight))+countNodes(root->left);
        }
        
    }
    int height(TreeNode* root)
    {
        TreeNode* temp=root;
        int h=0;
        while(temp!=NULL)
        {
            h++;
            temp=temp->left;
        }
        return h;
    }
    /*
    // 直接记数
    void countCore(TreeNode* root)
    {
        if(root==NULL)
            return ;
        result++;
        countCore(root->left);
        countCore(root->right);
    }
    */
};