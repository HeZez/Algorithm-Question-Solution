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
    从上往下打印出二叉树的每个节点，同层节点从左至右打印。
*/
/*
    思路 广度优先遍历 ，可以先在纸上手动模拟一下广度优先遍历的流程 不难发现其过程可以用一个队列辅助完成
    遍历到的结点，将其子节点加入队列中，之后该节点出栈，直到栈为空即可
*/

class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> q;
        if(root==NULL)
            return result;
        TreeNode* currentNode=root;
        q.push(root);
        while(!q.empty())
        {
            currentNode=q.front();
            result.push_back(currentNode->val);
            if(currentNode->left!=NULL)
                q.push(currentNode->left);
            if(currentNode->right!=NULL)
                q.push(currentNode->right);
            q.pop();
        }
        return result;
    }
};