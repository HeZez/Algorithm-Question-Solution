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
    给定一个二叉树，返回所有从根节点到叶子节点的路径。

    说明: 叶子节点是指没有子节点的节点。

    示例:

    输入:

       1
     /   \
    2     3
     \
      5

    输出: ["1->2->5", "1->3"]

    解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3
*/
/*
    
*/
class Solution {
private:
    vector<string> res;
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root==NULL)
            return res;
        string str="";
        binaryTreePathsCore(root, str);
        return res;
    }
    
    void binaryTreePathsCore(TreeNode* root, string str)
    {
        // 递归边界
        if(root->left==NULL&&root->right==NULL)
        {
            if(!str.empty())
                str+="->";
            str+=to_string(root->val);
            res.push_back(str);
        }
        else
        {
            if(!str.empty())
                str+="->";
            if(root->left)
                binaryTreePathsCore(root->left, str+to_string(root->val));
            if(root->right)
                binaryTreePathsCore(root->right, str+to_string(root->val));
        }
    }
};