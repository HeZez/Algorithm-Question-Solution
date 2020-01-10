/*
    莫里斯遍历这种做法在多线程异步操作的时候似乎并不完全
    这个O(1)的空间复杂度在实际中似乎也体现不出来比较大的优势
    可以当做一种技巧来学习吧
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

class Solution
{
public:
    // 根据前序遍历和中序遍历结果来重建二叉树
    TreeNode* constructBinaryTree(vector<int> DLR, vector<int> LDR)
    {
        if(DLR.empty()||LDR.empty()||DLR.size()!=LDR.size())
            return NULL;
        return constructBinaryTreeCore(DLR, 0, DLR.size()-1, LDR, 0, LDR.size()-1);
    }
    TreeNode* constructBinaryTreeCore(vector<int>& DLR, int dl, int dr, vector<int>& LDR, int ll, int lr)
    {
        // 递归边界
        if(dl>dr||ll>lr)
            return NULL;
        int flag=0;
        TreeNode* root=new TreeNode(DLR[dl]);
        for(flag=ll;flag<=lr;flag++)
        {
            if(LDR[flag]==DLR[dl])
                break;
        }
        root->left=constructBinaryTreeCore(DLR, dl+1, dl+(flag-ll), LDR, ll, flag-1);
        root->right=constructBinaryTreeCore(DLR, dl+(flag-ll)+1, dr, LDR, flag+1, lr);
        return root;
    }

    vector<int> morrisDLR(TreeNode* root)
    {
        // 莫里斯前序遍历
        TreeNode* cur=root;
        TreeNode* mostRight=NULL;
        vector<int> result;
        if(root==NULL)
            return result;
        while(cur!=NULL)
        {
            // 莫里斯先序遍历的思路 要判断cur节点的mostRight的right指针是不是指向cur的
            // 如果该指针指向cur 说明这是第二次遍历到该节点 根据不同的遍历方法进行判断
            mostRight=cur->left;
            if(cur->left==NULL)
            {
                // 第一种情况 如果cur没有左子树 直接移动到右子树
                result.push_back(cur->val);
                cur=cur->right;
            }
            else
            {
                // cur存在左子树，找左子树的mostRight
                while(mostRight->right!=NULL&&mostRight->right!=cur)
                {
                    mostRight=mostRight->right;
                }
                if(mostRight->right==NULL)
                {
                    mostRight->right=cur;
                    result.push_back(cur->val);
                    cur=cur->left;
                }
                else if(mostRight->right==cur)
                {
                    mostRight->right=NULL;
                    cur=cur->right;
                }
            }
            
        }
        return result;
    }

    vector<int> morrisLDR(TreeNode* root)
    {
        // 莫里斯中序遍历
        vector<int> result;
        if(root==NULL)
            return result;
        TreeNode* cur=root;
        TreeNode* mostRight=NULL;
        while(cur!=NULL)
        {
            // 莫里斯中序遍历的思路 要判断cur节点的mostRight的right指针是不是指向cur的
            // 如果该指针指向cur 说明这是第二次遍历到该节点 根据不同的遍历方法进行判断
            mostRight=cur->left;
            if(cur->left==NULL)
            {
                // 第一种情况 如果cur没有左子树 直接移动到右子树
                result.push_back(cur->val);
                cur=cur->right;
            }
            else
            {
                // cur存在左子树，找左子树的mostRight
                while(mostRight->right!=NULL&&mostRight->right!=cur)
                {
                    mostRight=mostRight->right;
                }
                if(mostRight->right==NULL)
                {
                    // 一个有左子树的节点第一次被遍历到 由于是中序遍历 先跳过
                    mostRight->right=cur;
                    cur=cur->left;
                }
                else if(mostRight->right==cur)
                {
                    // 一个有左子树的节点第二次被遍历到 记录结果
                    result.push_back(cur->val);
                    mostRight->right=NULL;
                    cur=cur->right;
                }
            }
        }
        return result;
    }
    // 后序遍历有点复杂 不写了
    void preOrderTraversalByCyclic(TreeNode* root)
    {
        stack<TreeNode*> s;
        TreeNode* r=root;
        while(!s.empty()||r)
        {
            while(r)
            {
                cout<<r->val<<' ';
                s.push(r);
                r=r->left;
            }
            if(!s.empty())
            {
                r=s.top();
                s.pop();
                r=r->right;
            }
        }
    }

};

int main()
{
    vector<int> DLR={1,2,4,5,3,6,7};
    vector<int> LDR={4,2,5,1,6,3,7};
    Solution s;
    TreeNode* root=s.constructBinaryTree(DLR, LDR);
    //s.preOrderTraversalByCyclic(root);
    vector<int> pre=s.morrisDLR(root);
    vector<int> in=s.morrisLDR(root);
    for(auto item: in)
       cout<<item<<",";
    cout<<endl;
    return 0;
}