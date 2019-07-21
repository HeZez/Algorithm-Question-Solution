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
    实现一个二叉搜索树迭代器。你将使用二叉搜索树的根节点初始化迭代器。

    调用 next() 将返回二叉搜索树中的下一个最小的数。


    示例：
    BSTIterator iterator = new BSTIterator(root);
    iterator.next();    // 返回 3
    iterator.next();    // 返回 7
    iterator.hasNext(); // 返回 true
    iterator.next();    // 返回 9
    iterator.hasNext(); // 返回 true
    iterator.next();    // 返回 15
    iterator.hasNext(); // 返回 true
    iterator.next();    // 返回 20
    iterator.hasNext(); // 返回 false


    提示：
    next() 和 hasNext() 操作的时间复杂度是 O(1)，并使用 O(h) 内存，其中 h 是树的高度。
    你可以假设 next() 调用总是有效的，也就是说，当调用 next() 时，BST 中至少存在一个下一个最小的数。

*/
/*
    二叉搜索树的中序遍历就是升序输出树中元素
    关键是怎样做到一个带暂停的版本，空间O(h) 时间复杂度O(1)
    可以将迭代实现中序遍历的方法分步拆开，封装到函数里即可
    这样做时间复杂度next不是O(1) hasNext是o(1) 最重要的是 空间复杂度不符合要求
    不过依旧比87%快  最重要的是比92%用户内存消耗的少，很神奇
    
    想要空间复杂度第的遍历方法，应该是“二叉树莫里斯遍历”，这里是我第一次在评论区看到有人说这种方法
    记录一下：
    
*/
class BSTIterator {
public:
    /*
    // 迭代版本的中序遍历
    stack<TreeNode*> s;
    BSTIterator(TreeNode* root) {
        //s.push(root);
        inStack(root);
    }
    
    // @return the next smallest number 
    int next() {
        TreeNode* cur=s.top();
        s.pop();
        inStack(cur->right);
        return cur->val;
    }
    
    // @return whether we have a next smallest number 
    bool hasNext() {
        return !s.empty();
    }
    void inStack(TreeNode* root)
    {
        TreeNode* t=root;
        while(t!=NULL)
        {
            s.push(t);
            t=t->left;
        }
    }
    */
    
    // 莫里斯遍历
    /*
        莫里斯遍历用两个指针来进行遍历
        中序遍历分为两大步
        1.当前指针的左指针若为空，则输出当前节点，cur=cur->right
        2.如果cur->left不为空，则找到cur的前驱节点，在中序遍历中就是cur左子树最右下的那个节点 作为pre
            a.如果pre->right为空 则把cur挂到pre->right上，方便在遍历完pre之后回到cur
            b.如果pre->right==cur,说明要遍历pre了 cur=cur->right 输出pre 把树恢复原状pre->right=NULL
    */
    TreeNode* cur;
    TreeNode* pre;
    BSTIterator(TreeNode* root) {
        cur=root; 
    }
    
    // @return the next smallest number 
    int next() {
        int res=0;
        if(cur->left==NULL)
        {
            res=cur->val;
            cur=cur->right;
        }
        else
        {
            pre=cur->left;
            while(pre->right!=NULL&&pre->right!=cur)
            {
                pre=pre->right;
            }
            if(pre->right==NULL)
            {
                pre->right=cur;
                cur=cur->left;
                return next();
            }
            else
            {
                pre->right=NULL;
                res=cur->val;
                cur=cur->right;
            }
        }
        return res;
    }
    
    // @return whether we have a next smallest number 
    bool hasNext() {
        return !(cur==NULL);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */