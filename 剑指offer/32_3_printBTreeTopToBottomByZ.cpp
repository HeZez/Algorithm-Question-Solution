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
    题目描述
    请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，
    第三行按照从左到右的顺序打印，其他行以此类推。
*/
/*
    思路为，使用两个栈来辅助完成
    两个栈交替存储当前层和下一层的结点
    手动的模拟一下整个过程
    我们发现在当前奇数层时，存下一层也就是偶数层的结点时，应该先左后右，
    在当前是偶数层，存下一层也就是下一个奇数层结点时，应该先右后左
    这样才满足Z字形打印的要求
*/
static const auto __ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int> > result;
        if(pRoot==NULL)
            return result;
        vector<int> v;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        TreeNode* currentNode=pRoot;
        s1.push(pRoot);
        while(!s1.empty()||!s2.empty())
        {
            while(!s1.empty())
            {
                currentNode=s1.top();
                v.push_back(currentNode->val);
                // 先左后右
                if(currentNode->left!=NULL)
                    s2.push(currentNode->left);
                if(currentNode->right!=NULL)
                    s2.push(currentNode->right);
                s1.pop();
                if(s1.empty())
                {
                    result.push_back(v);
                    v.clear();
                }
            }
            while(!s2.empty())
            {
                currentNode=s2.top();
                v.push_back(currentNode->val);
                // 先右后左
                if(currentNode->right!=NULL)
                    s1.push(currentNode->right);
                if(currentNode->left!=NULL)
                    s1.push(currentNode->left);
                s2.pop();
                if(s2.empty())
                {
                    result.push_back(v);
                    v.clear();
                }
            }
        }
        return result;
    }
    
};