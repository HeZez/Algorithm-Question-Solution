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
操作给定的二叉树，将其变换为源二叉树的镜像。
输入描述:
二叉树的镜像定义：源二叉树 
    	    8
    	   /  \
    	  6   10
    	 / \  / \
    	5  7 9 11
    	镜像二叉树
    	    8
    	   /  \
    	  10   6
    	 / \  / \
    	11 9 7  5
*/
class Solution {
public:
    // 可以手动的画图将整个镜像实现的过程画出来，可以发现
    // 只要遍历二叉树，将每个非叶节点的左右子树交换即可
    void Mirror(TreeNode *pRoot) {
        if(pRoot!=NULL)
        {
            MirrorCore(pRoot);
            Mirror(pRoot->left);
            Mirror(pRoot->right);
        }
    }
private:
    void MirrorCore(TreeNode* pRoot)
    {
        TreeNode* temp=pRoot->left;
        pRoot->left=pRoot->right;
        pRoot->right=temp;
    }
};