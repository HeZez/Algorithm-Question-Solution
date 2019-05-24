/*
    给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
    candidates 中的数字可以无限制重复被选取。
    说明：
    所有数字（包括 target）都是正整数。
    解集不能包含重复的组合。 
    示例 1:
    输入: candidates = [2,3,6,7], target = 7,
    所求解集为:
    [
      [7],
      [2,2,3]
    ]

    示例 2:
    输入: candidates = [2,3,5], target = 8,
    所求解集为:
    [
      [2,2,2,2],
      [2,3,3],
      [3,5]
    ]
*/

/*
    自己想的土方法  先对数组排序 由于每个数组可以被重复选取，那就顺次遍历所有数字的所有可能性 比如target=9 第一个数字是2
    那么9/2=4,从4个2,3个2  一直到1个2  2结束后再看下一个数字，  但是想一想就觉得时间复杂度很高。
    大佬说是回溯法 究竟什么是回溯呢？  回溯好像就是dfs的一种优化 加入了剪枝策略
    
*/
class Solution {
public:
    // 公共变量保存结果

    void find(vector<vector<int>>& result, vector<int>& candidates, vector<int>& temp, int target, int num)
    {
        /*
            参数说明：
            result：保存结果的数组
            candidates：可用加法元素 可以重复选取
            temp: 临时保存当前的可能解
            target：目标数字
            num：当前candidates中搜索到的数字位置，只找这个位置之后数字中的可能解
        */
        //递归边界
        if(target==0)
        {
            result.push_back(temp);
            return ;
        }
        if(target<candidates[0])   //相当于一次剪枝，最小的数已经比当前target大了，不需要再向下搜索
            return ;
        for(int i=num; i<candidates.size()&&candidates[0]<=target;i++)
        {
            //vector<int> list=temp;
            temp.push_back(candidates[i]);
            find(result, candidates, temp, target-candidates[i], i);
            temp.pop_back();           //这里不新建一个list来防止重复 而是在递归结束后把刚才加进去那个值从temp中弹出来 ，这样的话内存占用应该会小一些
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        find(result, candidates, temp, target, 0);
        return result;
    }
};