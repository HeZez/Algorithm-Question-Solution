/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
/*
题目描述  对阵的二叉树
请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
*/
/*
    思路来自剑指offer 判断一颗二叉树是否是对称的 如果镜像后的结果与之前的树相同 就是对称的
    根据树的遍历方法，例如前序遍历，遍历顺序为根左右，可以将其修改为根右左的顺序，来看两种遍历的结果是否相同
    因为存在一个结点只有一个子节点的情况，所以在遍历时要将空指针考虑进去

*/
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        bool result=false;
        result=isSymmetricalCore(pRoot, pRoot);
        return result;
    }
private:
    bool isSymmetricalCore(TreeNode* pRoot, TreeNode* pRootMirror)
    {
        if(pRoot==NULL&&pRootMirror==NULL)    //如果二者皆空，为真
            return true;
        //如果结点的值不同，或者结构不同，即一个为空指针另一个不是，则非镜像
        if(pRoot->val!=pRootMirror->val||(pRoot==NULL&&pRootMirror!=NULL)||(pRoot!=NULL&&pRootMirror==NULL))
            return false;
        return isSymmetricalCore(pRoot->left, pRootMirror->right)&&isSymmetricalCore(pRoot->right, pRootMirror->left);
    }
};