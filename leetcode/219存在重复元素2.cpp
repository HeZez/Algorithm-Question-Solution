/*
    给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使得 nums [i] = nums [j]，并且 i 和 j 的差的绝对值最大为 k。

    示例 1:

    输入: nums = [1,2,3,1], k = 3
    输出: true
    示例 2:

    输入: nums = [1,0,1,1], k = 1
    输出: true
    示例 3:

    输入: nums = [1,2,3,1,2,3], k = 2
    输出: false
*/

/*
    这道题的表述可能有一些问题，明明说的是绝对值最大为k 但是第二个例子中，元素1之间的符合条件的差值最大明明是3
    可能是只要存在k的情况就可以吧
    看了下评论 英文原版的题目翻译过来的意思应该是存在这样不超过k的数字  所以样例才这样给的
    
    最简单的思路 用hash表来记录索引
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> um;
        for(int i=0;i<nums.size();i++)
        {
            if(um.find(nums[i])!=um.end())
            {
                for(int j=0; j<um[nums[i]].size();j++)
                {
                    /*
                        在这一步可以进一步优化，因为题目要求是不超过k的
                        所以当这个索引差值大于k的时候，可以把保存的当前元素出现过的最左侧的索引去掉
                        因为这个值如果继续存在，新发现的索引差值计算出来肯定还是大于k的 没有计算的意义
                    */
                    if(i-um[nums[i]][j]<=k)
                        return true;
                }
                um[nums[i]].push_back(i);
            }
            else
                um[nums[i]].push_back(i);
        }
        return false;
    }
};