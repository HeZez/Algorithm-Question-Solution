/*
    给定一个没有重复数字的序列，返回其所有可能的全排列。

    示例:
    输入: [1,2,3]
    输出:
    [
      [1,2,3],
      [1,3,2],
      [2,1,3],
      [2,3,1],
      [3,1,2],
      [3,2,1]
    ]
*/
/*
    回溯算法及其实现
	还是不是很懂，需要多加练习
*/
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.empty())
            return result;
        permuteCore(nums, result, 0);
        return result;
    }
private:
    void permuteCore(vector<int>& nums, vector<vector<int>>& result, int index)
    {
        if(index==nums.size()-1)
            result.push_back(nums);
        for(int i=index;i<nums.size();i++)
        {
            swap(nums[index],nums[i]);
            permuteCore(nums, result, index+1);
            swap(nums[index],nums[i]);
        }
    }
};