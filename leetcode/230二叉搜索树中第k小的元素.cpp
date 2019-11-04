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
    给定一个二叉搜索树，编写一个函数 kthSmallest 来查找其中第 k 个最小的元素。

    说明：
    你可以假设 k 总是有效的，1 ≤ k ≤ 二叉搜索树元素个数。

    示例 1:

    输入: root = [3,1,4,null,2], k = 1
       3
      / \
     1   4
      \
       2
    输出: 1
    示例 2:

    输入: root = [5,3,6,2,4,null,null,1], k = 3
           5
          / \
         3   6
        / \
       2   4
      /
     1
    输出: 3
    进阶：
    如果二叉搜索树经常被修改（插入/删除操作）并且你需要频繁地查找第 k 小的值，你将如何优化 kthSmallest 函数？
*/
/*
    最直接的想法 二叉搜索树的中序遍历就是升序的
*/
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> res=middle_order(root, k);
        /*
        for(auto item: res)
            cout<<item<<",";
        */
        return res[k-1];
    }
    
    vector<int> middle_order(TreeNode* root, int k)
    {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* temp=root;
        //s.push(root);
        while(!s.empty()||temp!=NULL)
        {
            if(temp!=NULL)
            {
                s.push(temp);
                temp=temp->left;
            }
            else
            {
                temp=s.top();
                res.push_back(temp->val);
                if(res.size()==k)
                    return res;
                temp=temp->right;
                s.pop();
            }
        }
        return res;
    }
    
};