/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        /*
        bool result;
        // 空子树返回false
        if(pRoot1==NULL||pRoot2==NULL)
            return false;
        //用递归的方式遍历第一颗二叉树
        if(pRoot1->val==pRoot2->val)
            result=HasSubtreeCore(pRoot1,pRoot2);
        if(!result)
            result=HasSubtree(pRoot1->left, pRoot2);
        if(!result)
            result=HasSubtree(pRoot1->right, pRoot2);
        return result;
        */
        //用循环的方式遍历第一颗二叉树
        if(pRoot1==NULL||pRoot2==NULL)
            return false;
        TreeNode* nodeNow=pRoot1;
        bool result;
        bool flag=false;
        stack<TreeNode*> sT;
        // 前序遍历
        while(!sT.empty()||nodeNow!=NULL)
        {
            while(nodeNow!=NULL)
            {
                if(nodeNow->val==pRoot2->val)
                    result=HasSubtreeCore(nodeNow, pRoot2);
                sT.push(nodeNow);
                nodeNow=nodeNow->left;
                if(result)
                {
                    flag=true;
                    break;
                }
            }
            nodeNow=sT.top();
            sT.pop();
            nodeNow=nodeNow->right;
            if(flag)
                break;
        }
        return result;
    }
private:
    bool HasSubtreeCore(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        bool flag1,flag2;
        if(pRoot2==NULL)   // 能到达NULL说明之前的结构相同
            return true;
        if(pRoot1==NULL)   // 这种情况并不是两个结点值不相同，而是结构不同，pRoot2不为空 pRoot1却为空 结构不同
            return false;
        if(pRoot1!=NULL&&pRoot1!=NULL&&(pRoot1->val!=pRoot2->val))  // 两个同位置结点值不相同
            return false;
        flag1=HasSubtreeCore(pRoot1->left, pRoot2->left);
        flag2=HasSubtreeCore(pRoot1->right, pRoot2->right);
        return flag1&&flag2;
    }
};