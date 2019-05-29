/*
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
    给定一个二叉树，原地将它展开为链表。
    例如，给定二叉树

        1
       / \
      2   5
     / \   \
    3   4   6
    将其展开为：

    1
     \
      2
       \
        3
         \
          4
           \
            5
             \
              6
*/

/*
    经过观察其结果就是先序遍历的结果，只不过要求原地修改需要动动脑筋
    倒着中序遍历，即从右向左，先找到最右下的点，之后逐步向上构造  需要记录当前遍历节点的上一个节点
    但是我的想法我没能实现
    
    大佬的想法是，先序遍历，先把当前节点的孩子节点入栈，这样就相当于记录了左右子树位置
    之后把当前节点cur赋给root的右子树， root=root->right  这时root就等于cur了 因为cur的左右子树都入栈了相当于处理完了
    所以不会出现错误   记得把左子树置空
*/
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root==NULL)
            return ;
        if(root->left==NULL&&root->right==NULL)
            return ;
        stack<TreeNode* > s;
        TreeNode* cur=root;
        s.push(root);
        //TreeNode* lastOne=NULL;
        while(!s.empty())
        {
            cur=s.top();
            s.pop();
            if(cur->right)
                s.push(cur->right);
            if(cur->left)
                s.push(cur->left);
            root->right=cur;
            
            root=root->right;
            root->left=NULL;
            
            
        }     
    }
};