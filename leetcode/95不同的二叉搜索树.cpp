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
    给定一个整数 n，生成所有由 1 ... n 为节点所组成的二叉搜索树。

    示例:

    输入: 3
    输出:
    [
      [1,null,3,2],
      [3,2,null,1],
      [3,1,null,null,2],
      [2,1,3],
      [1,null,2,null,3]
    ]
    解释:
    以上的输出对应以下 5 种不同结构的二叉搜索树：

       1         3     3      2      1
        \       /     /      / \      \
         3     2     1      1   3      2
        /     /       \                 \
       2     1         2                 3
*/  
/*
    要求生成的是二叉搜索树，有一定的结构限制，还是递归建树，问题是如何返回结果呢？
    这道题关键的步骤在于想清楚递归的形式，返回一个可能的子节点列表，之后遍历列表创建根节点
*/

class Solution {
public:
    vector<TreeNode*> generateTreesCore(int left, int right)
    {
        // 递归边界
        vector<TreeNode*> res;
        if(left>right)
        {
            res.push_back(NULL);
            return res;
        }
        for(int i=left;i<=right;i++)
        {
            // 先获得左右子节点的所有可能结果
            vector<TreeNode*> leftSubTree=generateTreesCore(left, i-1);
            vector<TreeNode*> rightSubTree=generateTreesCore(i+1, right);
            for(auto leftChild: leftSubTree)
            {
                for(auto rightChild: rightSubTree)
                {
                    TreeNode* root=new TreeNode(i);
                    root->left=leftChild;
                    root->right=rightChild;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {  
        vector<TreeNode*> res;
        if(n<1)
            return res;
        return generateTreesCore(1, n);
    }
};