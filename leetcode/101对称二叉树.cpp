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
    给定一个二叉树，检查它是否是镜像对称的。

    例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

        1
       / \
      2   2
     / \ / \
    3  4 4  3
    但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

        1
       / \
      2   2
       \   \
       3    3
    说明:

    如果你可以运用递归和迭代两种方法解决这个问题，会很加分。
*/
/*
    这题怎么思考呢？  对称的二叉树，正向中序遍历和反向中序遍历结果应该是一样的
    
    或者层次遍历，两次层次遍历的方向相反，如果结果相同，就是对称的
    
*/
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        //return inOrder(root, root);    递归
        
        // 循环  用两个队列层次遍历
        if(!root)
            return true;
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        TreeNode* temp1=root;
        TreeNode* temp2=root;
        q1.push(root->left);
        q2.push(root->right);
        while(!q1.empty()&&!q2.empty())
        {
            temp1=q1.front();
            q1.pop();
            temp2=q2.front();
            q2.pop();
            if((temp1&&!temp2)||(!temp1&&temp2))
                return false; // 两个节点不同时为空
            if(temp1)
            {
                if(temp1->val!=temp2->val)
                    return false;
                q1.push(temp1->right);
                q1.push(temp1->left);
                q2.push(temp2->left);
                q2.push(temp2->right);
                /*
                q1.push(temp1->left);
                q1.push(temp1->right);
                q2.push(temp2->right);
                q2.push(temp2->left);
                */
            }
        }
        return true;
    }
    
    bool inOrder(TreeNode* root1, TreeNode* root2)
    {
        // 递归写法
        if(root1==NULL&&root2==NULL)
            return true;
        if(root1==NULL||root2==NULL)
            return false;
        
        return (root1->val==root2->val)&&inOrder(root1->left, root2->right)&&inOrder(root1->right, root2->left);
    }
    
};