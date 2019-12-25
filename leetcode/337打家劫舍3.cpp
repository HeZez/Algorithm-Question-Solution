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
    在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为“根”。 除了“根”之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。

    计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。

    示例 1:
    输入: [3,2,3,null,3,null,1]

         3
        / \
       2   3
        \   \ 
        3   1

    输出: 7 
    解释: 小偷一晚能够盗取的最高金额 = 3 + 3 + 1 = 7.

    示例 2:
    输入: [3,4,5,1,3,null,1]

         3
        / \
       4   5
      / \   \ 
     1   3   1

    输出: 9
    解释: 小偷一晚能够盗取的最高金额 = 4 + 5 = 9.
 */
 /*
    既然是一个二叉树的形式，可以用类似于dp的方式来进行计算
    对于某一个根来说 其结果应该是计算 包含当前根的值与不包含当前根的值二者之间的大者。
    细说 我觉得可以分成四种情况
    假如一个节点有左右孩子 可以分成
    1.当前节点选 两个孩子都不被选
    2.当前节点不选 左孩子选 右孩子不选
    3.当前节点不选 左孩子不选 右孩子不选
    4.当前节点不选 左右孩子都选
    (这里的“选”指的是这个节点的值被不被算到结果里，结合题目要求两个直接相连的节点不能同时被选择的限制理解)
    这样的话递归的计算要返回两个值 一个表示当前节点被选择是的最大结果 一个是当前节点未被选择
 */
class Solution {
public:
    int rob(TreeNode* root) {
        vector<int> result=robCore(root);
        /*
        for(auto item: result)
            cout<<item<<",";
            */
        return max(result[0], result[1]);
    }
    vector<int> robCore(TreeNode* root)
    {
        // 递归边界
        vector<int> tempR(2,0);    // 这个vector的两个值 第一个表示包含当前节点结果 第二个表示不包含
        if(root==NULL)
            return tempR;
        vector<int> leftSonR,rightSonR;
        
        leftSonR=robCore(root->left);
        rightSonR=robCore(root->right);
        vector<int> ().swap(tempR);
        tempR.push_back(leftSonR[1]+rightSonR[1]+root->val);   // 选择root的值的时候
        /*
        int a=max(leftSonR[0]+rightSonR[1], leftSonR[1]+rightSonR[0]);
        tempR.push_back(max(a, leftSonR[0]+rightSonR[0])); // 不选择root的时候
        //tempR.push_back(leftSonR[0]+rightSonR[0]);   // 不选择root的时候
        */
        // 第二个数为什么要这么算？  像我那样算为什么会出错？
        tempR.push_back(max(leftSonR[0], leftSonR[1])+max(rightSonR[0], rightSonR[1])); // 不选择root的时候
        vector<int> ().swap(leftSonR);
        vector<int> ().swap(rightSonR);
        return tempR;
    }
};