/*
    题目描述
    输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。
    假设输入的数组的任意两个数字都互不相同。
    二叉搜索树： 左子树<根<右子树
*/
/*
    思路：后序遍历的顺序是左右根，数组的最后一位是当前子树的根
        注意边界条件，同时有可能当前根只有左子树没有右子树或者完全相反
        遍历当前子树的子节点，与根结点比较，找到右子树的第一个节点，
        同时继续从右子树第一个节点开始遍历子结点，查看是否有不满足要求的情况
        不满足要求即右子树中有小于根的结点
*/

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        int length=sequence.size();
        if(length==0)
            return false;
        if(length==2||length==1)
            return true;
        return VerifySquenceOfBSTCore(sequence, 0, length-1);
    }
private:
    bool VerifySquenceOfBSTCore(vector<int> sequence, int start, int end)
    {
        if(start==end)
            return true;
        int flag=start;
        int temp;
        for(;flag<end;flag++)
        {
            if(sequence[flag]>sequence[end])
                break;
        }
        temp=flag;
        for(;temp<end;temp++)
        {
            if(sequence[temp]<sequence[end])
                return false;
        }
        bool left=true;
        //存在左子树，继续递归 否则left等于true
        if(flag>start)
            left=VerifySquenceOfBSTCore(sequence, start, flag-1);
        bool right=true;
        //存在右子树，继续递归 否则right等于true
        if(flag<end)
            right=VerifySquenceOfBSTCore(sequence, flag, end-1);
        return left&&right;
    }
};