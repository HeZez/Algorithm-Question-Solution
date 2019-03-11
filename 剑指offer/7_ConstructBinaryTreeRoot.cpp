/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
    题目描述
    输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
    假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
    例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
*/
/*
    可以用递归实现，前序遍历的第一个元素是当前树结构的根，
    在中序遍历中找到这个元素，这个元素之前的是当前树结构的左子树，后面的是右子树
    递归边界是当两个遍历结果的左右指针交汇，
*/
class Solution {
public:
    TreeNode* ConstructBinaryTreeRoot(vector<int> pre,int preSta,int preEnd,vector<int> vin,int inSta,int inEnd)
    {
        if(preSta>=preEnd||inSta>=inEnd)
            return NULL;
        TreeNode* root=new TreeNode(pre[preSta]);
        //TreeNode* root;
        //root->val=pre[preSta];
        int num=-1;
        for(num=inSta;num<inEnd;num++)
            if(vin[num]==pre[preSta])
                break;
        root->left=ConstructBinaryTreeRoot(pre,preSta+1,preSta+num-inSta+1,vin,inSta,num);
        root->right=ConstructBinaryTreeRoot(pre,preSta+num-inSta+1,preEnd,vin,num+1,inEnd);
        return root;
    }
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.size()==0||vin.size()==0){
            return NULL;
        }
        return ConstructBinaryTreeRoot(pre,0,pre.size(),vin,0,vin.size());
    }
};