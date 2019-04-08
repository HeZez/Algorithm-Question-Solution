#include<stdio.h>
#include<iostream>
#include<string.h>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
    // 首先构建二叉树  一颗二叉树的结构是可以根据前序、中序、后序其中的两种来确定的
    // 这里使用前序遍历和中序遍历  这里可能还需要二叉树中没有重复元素
    TreeNode* constructBinaryTree(vector<int> pre, vector<int> vin)
    {
        if(pre.size()==0||vin.size()==0)
            return NULL;
        return constructBinaryTreeCore(pre, 0, pre.size(), vin, 0, vin.size());
    }
    TreeNode* constructBinaryTreeCore(vector<int> pre, int preBegin, int preEnd, vector<int> vin, int vinBegin, int vinEnd)
    {
        if(preBegin>=preEnd||vinBegin>=vinEnd)
            return NULL;
        TreeNode* rootNow=new TreeNode(pre[preBegin]);
        int flag=-1;
        for(flag=vinBegin;flag<vinEnd;flag++)
        {
            if(vin[flag]==pre[preBegin])
            {
                break;
            }
        }
        rootNow->left=constructBinaryTreeCore(pre, preBegin+1, preBegin+1+(flag-vinBegin), vin, vinBegin, flag);
        rootNow->right=constructBinaryTreeCore(pre, preBegin+(flag-vinBegin)+1, preEnd, vin, flag+1, vinEnd);
        return rootNow;
    }
    // 前序遍历 递归实现  比较简单
    void preOrderTraversalByRecursion(TreeNode* root)
    {
        if(root==NULL)
            return ;
        cout<<root->val<<' ';
        preOrderTraversalByRecursion(root->left);
        preOrderTraversalByRecursion(root->right);
    }
    // 前序遍历 循环实现 用一个栈来辅助实现
    void preOrderTraversalByCyclic(TreeNode* root)
    {
        stack<TreeNode*> s;
        TreeNode* r=root;
        while(!s.empty()||r)
        {
            while(r)
            {
                // 输出前序遍历 顺序是根左右 先输出当前节点的值，当前节点入栈，向下遍历左子树，直到到达整棵二叉树最左面的节点
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

    // 中序遍历 递归实现
    void inOrderTraversalByRecursion(TreeNode* root)
    {
        if(root->left)
            inOrderTraversalByRecursion(root->left);
        if(root)
            cout<<root->val<<' ';
        if(root->right)
            inOrderTraversalByRecursion(root->right);
    }
    // 中序遍历 循环实现 还是使用一个栈来辅助完成
    void inOrderTraversalByCyclic(TreeNode* root)
    {
        if(root==NULL)
            return ;
        TreeNode* r=root;
        stack<TreeNode*> s;
        while(r!=NULL||!s.empty())
        {
            while(r!=NULL)
            {
                // 中序遍历 左根右 先遍历左子树，到达二叉树最左下的节点
                s.push(r);
                r=r->left;
            }
            if(!s.empty())
            {
                // 当r时null的时候，说明左子树遍历完毕了，获得当前栈顶元素，输出值，继续遍历右子树
                r=s.top();
                cout<<r->val<<" ";
                s.pop();
                r=r->right;
            }
        }
    }

    // 后序遍历的递归实现
    void posOrderTraversalByRecursion(TreeNode* root)
    {
        if(root->left)
            posOrderTraversalByRecursion(root->left);
        if(root->right)
            posOrderTraversalByRecursion(root->right);
        if(root)
            cout<<root->val<<' ';
    }
    // 后序遍历二叉树 循环实现
    // 循环实现后序遍历时，需要一些处理
    // 获取数据顺序应为左右根，一个字数根节点有两种情况，
    // 1. 它的左右子树都是空的，那可以直接输出这个节点
    // 2.或者这个根节点有左子树或者右子树，那么在第一次访问它的时候是不能输出的，需要将它的左右子树都遍历完了才能轮到它
    //   所以就是在第二次访问该根节点的时候输出它的值
    // 实现方式通常有两种
    void posOrderTraversalByCyclic(TreeNode* root)
    {
        if(root==NULL)
            return ;
        TreeNode* cur=root;
        TreeNode* pre=NULL;
        stack<TreeNode*> s;
        s.push(cur);
        while(!s.empty())
        {
            cur=s.top();
            if((cur->left==NULL&&cur->right==NULL)||
               ((cur->left==pre||cur->right==pre)&&pre!=NULL))
            {
                cout<<cur->val<<' ';
                pre=cur;
                s.pop();
            }
            else
            {
                if(cur->right)
                    s.push(cur->right);
                if(cur->left)
                    s.push(cur->left);
            }
        }
    }
    // 按照层次 广度优先遍历  使用队列辅助完成
    void TraversalByLevel(TreeNode* root)
    {
        if(root==NULL)
            return ;
        queue<TreeNode*> q;
        TreeNode* cur;
        q.push(root);
        while(!q.empty())
        {
            if(!q.empty())
            {
                cur=q.front();
                cout<<cur->val<<' ';
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
                q.pop();
            }
        }
    }

    void deepFirstTraversal(TreeNode* root)
    {
        TreeNode* cur;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty())
        {
            cur=s.top();
            s.pop();
            cout<<cur->val<<' ';
            if(cur->right)
                s.push(cur->right);
            if(cur->left)
                s.push(cur->left);
        }
    }
};

int main()
{
    Solution s;
	vector<int> pre = { 1, 2, 4, 7, 3, 5, 6, 8 };
	vector<int> vin = { 4, 7, 2, 1, 5, 3, 8, 6 };
	/*
                    示例二叉树结构
                        1
                2               3
             4              5        6
                7                 8
	*/
	TreeNode *t;
	t = s.constructBinaryTree(pre, vin);
	cout << "前序遍历递归实现二叉树序列为：" << endl;
	s.preOrderTraversalByRecursion(t);
	cout << endl<<"前序遍历循环实现二叉树序列为："<< endl;
	s.preOrderTraversalByCyclic(t);
	cout << endl<<"中序遍历递归实现二叉树序列为："<< endl;
	s.inOrderTraversalByRecursion(t);
	cout << endl<<"中序遍历循环实现二叉树序列为："<< endl;
	s.inOrderTraversalByCyclic(t);
	cout << endl<<"后序遍历递归实现二叉树序列为：" << endl;
	s.posOrderTraversalByRecursion(t);
	cout << endl << "后序遍历循环实现二叉树序列为：" << endl;
	s.posOrderTraversalByCyclic(t);
	cout << endl << "层次遍历二叉树序列为：" << endl;
	s.TraversalByLevel(t);
	cout << endl << "深度优先遍历二叉树序列为：" << endl;
	s.deepFirstTraversal(t);
	cout << endl;
	return 0;
}


