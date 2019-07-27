/*
    找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。

    说明：

    所有数字都是正整数。
    解集不能包含重复的组合。 
    示例 1:

    输入: k = 3, n = 7
    输出: [[1,2,4]]
    示例 2:

    输入: k = 3, n = 9
    输出: [[1,2,6], [1,3,5], [2,3,4]]
*/
/*
    按照题目的要求，组合中只有1到9的数字，并且不能有重复， 
    自己写了个回溯，在不可能有解的情况下剪枝，能过，但是效率不高
*/
class Solution {
public:
    vector<vector<int>> results;
    void combinationSum3Core(vector<int>& nums, int k, int n, int index, vector<int>& temp)
    {
        // 递归边界
        if(temp.size()==k&&n==0)
        {
            results.push_back(temp);
            return ;
        }
        if(nums[index]>n || index>=nums.size())
            return ; //剪枝
        
        for(int i=index;i<nums.size();i++)
        {
            if(nums[i]<=n)
            {
                temp.push_back(nums[i]);
                combinationSum3Core(nums, k,n-nums[i], i+1, temp);
                temp.pop_back();
            }
            else
                break;   //剪枝
        }
        
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums;
        vector<int> temp;
        for(int i=1;i<=9;i++)
            nums.push_back(i);
        combinationSum3Core(nums, k, n, 0, temp);
        return results;
    }
};