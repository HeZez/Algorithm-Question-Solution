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
    // ���ȹ���������  һ�Ŷ������Ľṹ�ǿ��Ը���ǰ�����򡢺������е�������ȷ����
    // ����ʹ��ǰ��������������  ������ܻ���Ҫ��������û���ظ�Ԫ��
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
    // ǰ����� �ݹ�ʵ��  �Ƚϼ�
    void preOrderTraversalByRecursion(TreeNode* root)
    {
        if(root==NULL)
            return ;
        cout<<root->val<<' ';
        preOrderTraversalByRecursion(root->left);
        preOrderTraversalByRecursion(root->right);
    }
    // ǰ����� ѭ��ʵ�� ��һ��ջ������ʵ��
    void preOrderTraversalByCyclic(TreeNode* root)
    {
        stack<TreeNode*> s;
        TreeNode* r=root;
        while(!s.empty()||r)
        {
            while(r)
            {
                // ���ǰ����� ˳���Ǹ����� �������ǰ�ڵ��ֵ����ǰ�ڵ���ջ�����±�����������ֱ���������ö�����������Ľڵ�
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

    // ������� �ݹ�ʵ��
    void inOrderTraversalByRecursion(TreeNode* root)
    {
        if(root->left)
            inOrderTraversalByRecursion(root->left);
        if(root)
            cout<<root->val<<' ';
        if(root->right)
            inOrderTraversalByRecursion(root->right);
    }
    // ������� ѭ��ʵ�� ����ʹ��һ��ջ���������
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
                // ������� ����� �ȱ�������������������������µĽڵ�
                s.push(r);
                r=r->left;
            }
            if(!s.empty())
            {
                // ��rʱnull��ʱ��˵����������������ˣ���õ�ǰջ��Ԫ�أ����ֵ����������������
                r=s.top();
                cout<<r->val<<" ";
                s.pop();
                r=r->right;
            }
        }
    }

    // ��������ĵݹ�ʵ��
    void posOrderTraversalByRecursion(TreeNode* root)
    {
        if(root->left)
            posOrderTraversalByRecursion(root->left);
        if(root->right)
            posOrderTraversalByRecursion(root->right);
        if(root)
            cout<<root->val<<' ';
    }
    // ������������� ѭ��ʵ��
    // ѭ��ʵ�ֺ������ʱ����ҪһЩ����
    // ��ȡ����˳��ӦΪ���Ҹ���һ���������ڵ������������
    // 1. ���������������ǿյģ��ǿ���ֱ���������ڵ�
    // 2.����������ڵ�����������������������ô�ڵ�һ�η�������ʱ���ǲ�������ģ���Ҫ�����������������������˲����ֵ���
    //   ���Ծ����ڵڶ��η��ʸø��ڵ��ʱ���������ֵ
    // ʵ�ַ�ʽͨ��������
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
    // ���ղ�� ������ȱ���  ʹ�ö��и������
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
                    ʾ���������ṹ
                        1
                2               3
             4              5        6
                7                 8
	*/
	TreeNode *t;
	t = s.constructBinaryTree(pre, vin);
	cout << "ǰ������ݹ�ʵ�ֶ���������Ϊ��" << endl;
	s.preOrderTraversalByRecursion(t);
	cout << endl<<"ǰ�����ѭ��ʵ�ֶ���������Ϊ��"<< endl;
	s.preOrderTraversalByCyclic(t);
	cout << endl<<"��������ݹ�ʵ�ֶ���������Ϊ��"<< endl;
	s.inOrderTraversalByRecursion(t);
	cout << endl<<"�������ѭ��ʵ�ֶ���������Ϊ��"<< endl;
	s.inOrderTraversalByCyclic(t);
	cout << endl<<"��������ݹ�ʵ�ֶ���������Ϊ��" << endl;
	s.posOrderTraversalByRecursion(t);
	cout << endl << "�������ѭ��ʵ�ֶ���������Ϊ��" << endl;
	s.posOrderTraversalByCyclic(t);
	cout << endl << "��α�������������Ϊ��" << endl;
	s.TraversalByLevel(t);
	cout << endl << "������ȱ�������������Ϊ��" << endl;
	s.deepFirstTraversal(t);
	cout << endl;
	return 0;
}


