/*
    给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

    说明：解集不能包含重复的子集。

    示例:

    输入: [1,2,2]
    输出:
    [
      [2],
      [1],
      [1,2,2],
      [2,2],
      [1,2],
      []
    ]
*/
/*
    问题还是如何去重 
    问题子集1中通常存在两种解法， 第一种是位运算的方式，第二种逐步向之前的解集中添加新的结果
    我觉得第二种方式可以想办法进行去重，老办法，先对数据进行排序，之后进行下一步的操作
    去重的方法是经过分析得来的，出现重复的原因是数组中有重复元素（废话...），但是并不是单纯的将重复元素滤掉就能解决问题
    看一个出现重复的例子
    以[1,2,2]为例
    在遍历完1 2之后，结果是这样的
    [], [1], [2], [1,2]
    如果不进行处理再遍历下一个2，那么结果就会变成
    [], [1], [2], [1,2], [2], [1,2], [2,2], [1,2,2]
    这里面出现了重复的子集，根本原因在于
    当遍历第一个2的时候，[], [1]这部分已经被处理过了
    当第二个2进来的时候，如果还处理[], [1]这部分，就造成了重复
    为了避免这种问题，可以在重复元素出现的时候，设置一个变量来控制处理先前子集的起始位置
    可以观察一下，如果出现重复元素，那么需要处理的子集个数和上一次加入的子集数相同
    
*/
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> subset;
        vector<vector<int>> res;
        res.push_back(subset);
        int index=0;
        int len=0;
        for(int i=0;i<nums.size();i++)
        {
            if(i>0&&nums[i]==nums[i-1]) index=res.size()-len;
            else index=0;
            int length=res.size();
            len=length-index;
            for(int j=index;j<length;j++)
            {
                subset=res[j];
                subset.push_back(nums[i]);
                res.push_back(subset);
            }
        }
        return res;
    }
};