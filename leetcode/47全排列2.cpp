/*
    给定一个可包含重复数字的序列，返回所有不重复的全排列。

    示例:

    输入: [1,1,2]
    输出:
    [
      [1,1,2],
      [1,2,1],
      [2,1,1]
    ]
*/
/*
    回溯即可得到所有解，关键是如何去重
    我觉得可以用这样的方式去重，和印象中的某一道题类似，
    可以先将序列排序，如果当前的数值是重复的，就跳过不进行搜索
*/
class Solution {
public:
    vector<vector<int>> results;
    void permuteUniqueCore(vector<int>& nums, vector<int>& temp, int& length)
    {
        // 递归边界
        if(temp.size()==length)
        {
            results.push_back(temp);
            return ;
        }
        for(int i=0 ; i<nums.size() ; i++)
        {
            if(i>0 && nums[i]==nums[i-1]) continue;  // 去重，保证重复值中的第一个可以被加入到解中，剩余的重复值则跳过
            int t=nums[i];
            temp.push_back(nums[i]);
            nums.erase(nums.begin()+i);
            permuteUniqueCore(nums, temp, length);
            temp.pop_back();
            nums.insert(nums.begin()+i, t);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if(nums.empty())
            return results;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        int length=nums.size();
        permuteUniqueCore(nums, temp, length);
        return results;
    }
};