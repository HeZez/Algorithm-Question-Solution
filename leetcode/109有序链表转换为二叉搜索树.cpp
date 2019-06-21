/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。

    本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

    示例:

    给定的有序链表： [-10, -3, 0, 5, 9],

    一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：

          0
         / \
       -3   9
       /   /
     -10  5

*/
/*
    要求转换为高度平衡的二叉搜索树，已经是排过序的链表了，那基本思路就应该是二分，中点为根，之后递归建树
    找中点，可以用快慢指针的方式找到链表中点.
    还可以将整个链表的值存到数组中，可以O（1）的找到中点，但是需要额外的存储空间
*/
class Solution {
public:
    TreeNode* sortedListToBSTCore(vector<int>& nums, int l, int r)
    {
        TreeNode* root=NULL;
        // 递归边界
        if(l<=r)
        {
            int mid=(l+r)/2;
            root=new TreeNode(nums[mid]);
            root->left=sortedListToBSTCore(nums, l, mid-1);
            root->right=sortedListToBSTCore(nums, mid+1, r);
            
        }
        else
            root=NULL;
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL)
            return NULL;
        vector<int> nums;
        ListNode* temp=head;
        while(temp)
        {
            nums.push_back(temp->val);
            temp=temp->next;
        }
        TreeNode* result=sortedListToBSTCore(nums, 0, nums.size()-1);
        return result; 
    }
};