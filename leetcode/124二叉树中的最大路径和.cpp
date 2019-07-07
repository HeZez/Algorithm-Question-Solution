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
    给定一个非空二叉树，返回其最大路径和。

    本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。

    示例 1:

    输入: [1,2,3]

           1
          / \
         2   3

    输出: 6
    示例 2:

    输入: [-10,9,20,null,null,15,7]

       -10
       / \
      9  20
        /  \
       15   7

    输出: 42

*/
/*
    一开始真的是，毫无头绪，
    思考了一会儿..... 二叉树中的路径和，一段路径至少包含一个节点，树中的节点可以两两配对
    总共的路径就是这么多种可能
    直觉感觉是dp，如果是树搜索的话，由于是任意两个节点之间的路径，不管哪种遍历方式可能都无法满足这种要求
    用树搜索感觉很难实现
    
    评论区看了看大佬的解答，感觉自己还是笨啊.......
    对于一个节点来说，如果其在最大路径中，则存在这样的几种情况
    1.一个类似倒着的V型，其左右子树中都包含该路径的一部分
    2.该节点是一段类似斜线路径的顶端，也就是只有该节点的左或右子树中有一部分在最大和路径中
    
    可以设置一个变量来记录最大结果，同时采用递归的方式进行遍历，
    在递归返回结果时，返回包含当前root节点的左半侧或者右半侧，看哪侧大返回哪边，
    这是因为路径中不会出现类似“三通”的结构
    例如
       -10
       / \
      9  20
        /  \
       15   7
    在返回20这一点的结果时，结果应该是20+15=35，而不是20+15+7=42，因为一条路径不能同时到达左右子树
    但是该例子的最大结果是42，这是在根节点为20时记录的结果
    如果root的左右两个子树返回结果都小于零，则直接返回root的值
*/
class Solution {
public:
    int res=INT_MIN;
    int maxPathSumCore(TreeNode* root)
    {
        // 递归边界
        if(root==NULL)
            return 0;
        int left=max(0, maxPathSumCore(root->left));   //在返回结果是负值的时候，把结果置为0，因为负值加上去都会使结果变小
        int right=max(0, maxPathSumCore(root->right));
        res=max(res, root->val+left+right);
        return max(left, right)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        maxPathSumCore(root);
        return res;
    }
};