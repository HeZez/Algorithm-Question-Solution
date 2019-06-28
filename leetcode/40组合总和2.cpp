/*
    给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

    candidates 中的每个数字在每个组合中只能使用一次。

    说明：
    所有数字（包括目标数）都是正整数。
    解集不能包含重复的组合。 
    
    示例 1:
    输入: candidates = [10,1,2,7,6,1,5], target = 8,
    所求解集为:
    [
      [1, 7],
      [1, 2, 5],
      [2, 6],
      [1, 1, 6]
    ]
    
    示例 2:
    输入: candidates = [2,5,2,1,2], target = 5,
    所求解集为:
    [
      [1,2,2],
      [5]
    ]
*/

/*
    这个问题回溯就可以得到带重复的结果，关键的一步是如何去重
    还是看了大佬的思路，去重的时候这样操作，在开始回溯之前首先对原数组进行排序
    之后至少保证回溯的当前值可以进入解集，下来如果存在重复值就跳过，这样可以在构造解的时候去掉重复的解
*/
class Solution {
public:
    vector<vector<int>> res;
    void combinationSum2Core(vector<int>& candidates, vector<int>& tempRes, int& target, 
                             int tempSum, int index) {
        // 递归边界
        if(tempSum==target)
        {
            res.push_back(tempRes);
            return ;
        }
        if(index>=candidates.size())
            return ;
        int flag=0;
        for(int i=index;i<candidates.size();i++)
        {
            if(i>index && candidates[i-1]==candidates[i]) continue; 
            if(tempSum+candidates[i]<=target)
            {
                tempRes.push_back(candidates[i]);
                combinationSum2Core(candidates, tempRes, target, tempSum+candidates[i], i+1);
                tempRes.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> tempRes;
        if(candidates.empty())
            return res;
        sort(candidates.begin(), candidates.end());
        combinationSum2Core(candidates, tempRes, target, 0, 0);
        return res;
    }
};