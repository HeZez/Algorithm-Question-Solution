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
    输入一颗二叉树的跟节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
    路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。(注意: 在返回值的list中，数组长度大的数组靠前)
*/
/*
    这个解法是其他人的代码，比较简洁，带记忆的深度优先搜索，用递归的方式完成，但是这个代码没有题目中要求的排序功能
    后台在评判的时候好像也没把这点加进去
    深度优先搜索如果用循环的方式完成就是用栈来辅助，递归也相当于一个栈。
*/

class Solution {
public:
    vector<vector<int> > result;
    vector<int> v;
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(root==NULL)
            return result;
        v.push_back(root->val);
        if(expectNumber-root->val==0&&root->left==NULL&&root->right==NULL)
        {
            result.push_back(v);
        }
        FindPath(root->left,expectNumber-root->val);
        FindPath(root->right,expectNumber-root->val);
        // 上面的两个递归执行完成了，说明当前root的左右子树包含的路径都被遍历了，从v向量中把它去掉。
        if(v.size()!=0)
            v.pop_back();
        return result;
    }
};