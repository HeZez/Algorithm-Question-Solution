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
    从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
*/
/*
    思路：和上一题类似，只要加入两个变量来记录当前层和下一层的未处理结点数即可
        初始化为在最开始时，根节点只有一个结点，下一层为0个
*/

class Solution {
public:
        vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector<int> > result;
            if(pRoot==NULL)
                return result;
            vector<int> v;
            queue<TreeNode*> q;
            int toBePrint=1;
            int nextLevel=0;
            TreeNode* currentNode=pRoot;
            q.push(pRoot);
            while(!q.empty())
            {
                currentNode=q.front();
                v.push_back(currentNode->val);
                toBePrint--;
                if(currentNode->left!=NULL)
                {
                    q.push(currentNode->left);
                    nextLevel++;
                }
                if(currentNode->right!=NULL)
                {
                    q.push(currentNode->right);
                    nextLevel++;
                }
                q.pop();
                if(toBePrint==0)
                {
                    result.push_back(v);
                    toBePrint=nextLevel;
                    nextLevel=0;
                    v.clear();
                }
                
            }
            return result;
        }
    
};