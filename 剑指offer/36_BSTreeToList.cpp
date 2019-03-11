/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
/*
    题目描述
    输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
*/

/*
    涉及到二叉树的中序遍历方法，无论是递归实现还是循环实现都需要一个指针来记录上一个被遍历的结点。
    循环实现中序遍历需要一个栈来辅助完成
*/
class Solution {
public:
    // 循环实现
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree==nullptr)
            return nullptr;
        stack<TreeNode*> s;
        TreeNode* pre=nullptr;
        TreeNode* current=nullptr;
        TreeNode* result=pRootOfTree;
        bool isFirst=true;
        current=pRootOfTree;
        while(!s.empty()||current!=nullptr)
        {
            while(current!=nullptr)
            {
                s.push(current);
                current=current->left;
            }
            current=s.top();
            s.pop();
            if(isFirst)
            {
                result=current;
                pre=current;
                isFirst=false;
            }
            else
            {
                current->left=pre;
                pre->right=current;
                pre=current;
            }
            current=current->right;
            /*
            current->left=pre;
            if(pre!=nullptr)
                pre->right=current;
            pre=current;
            if(current->right!=nullptr)
            {
                s.push(current->right);
            }
            current=current->right;
            */
        }
        return result;
    }
    /*
    //  递归实现
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree==nullptr)
            return nullptr;
        TreeNode* pre=nullptr;
        ConvertToList(pRootOfTree,pre);
        TreeNode* result=pRootOfTree;
        //找到双向链表头并返回
        while(result->left)
            result=result->left;
        return result;
        
    }*/
private:
    void ConvertToList(TreeNode* root, TreeNode*& pre)
    {
        if(root==nullptr)
            return ;
        if(root->left!=nullptr)
            ConvertToList(root->left, pre);
        root->left=pre;
        if(pre!=nullptr)
            pre->right=root;
        pre=root;           // 这里的pre一直在变化，并不是指向当前结点的父结点，而是指向中序遍历中按照遍历顺序当前结点的上一个结点
        if(root->right!=nullptr)
            ConvertToList(root->right, pre);
    }
};