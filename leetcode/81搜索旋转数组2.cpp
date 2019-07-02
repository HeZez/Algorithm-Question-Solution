/*
    假设按照升序排序的数组在预先未知的某个点上进行了旋转。

    ( 例如，数组 [0,0,1,2,2,5,6] 可能变为 [2,5,6,0,0,1,2] )。

    编写一个函数来判断给定的目标值是否存在于数组中。若存在返回 true，否则返回 false。

    示例 1:

    输入: nums = [2,5,6,0,0,1,2], target = 0
    输出: true
    示例 2:

    输入: nums = [2,5,6,0,0,1,2], target = 3
    输出: false
    进阶:

    这是 搜索旋转排序数组 的延伸题目，本题中的 nums  可能包含重复元素。
    这会影响到程序的时间复杂度吗？会有怎样的影响，为什么？
*/
/*
    这道题中出现了重复值，如果不对重复值进行处理，直接套用没有重复值的方法，会出现一些问题
    比如[1,3,1,1,1] 3  这一测试用例，由于重复值的存在会导致分组时出现错误
    处理重复值，那就跳过那些重复的元素

*/
class Solution {
public:
    bool searchCore(vector<int>& nums, int& target, int left, int right)
    {
        //递归边界
        if(left>right)
            return false;
        // 跳过重复值
        while(left<right && nums[left]==nums[left+1]) left++;
        while(left<right && nums[right]==nums[right-1]) right--;
        int mid=(left+right)/2;
        if(nums[mid]==target)
            return true;
        /*
        if(nums[left]<=nums[mid])
        {
            if(target>=nums[left]&&target<nums[mid])
                return searchCore(nums, target, left, mid-1);
            else
                return searchCore(nums, target, mid+1, right);
        }
        else
        {
            if(target>nums[mid]&&target<=nums[right])
            {
                return searchCore(nums, target, mid+1, right);
            }
            else
            {
                return searchCore(nums, target, left, mid-1);
            }
        }
        */
        if(nums[mid]<nums[right])
        {
            if(target>nums[mid]&&target<=nums[right])
                return searchCore(nums, target, mid+1, right);
            else
                return searchCore(nums, target, left, mid-1);
        }
        else
        {
            if(target>=nums[left]&&target<nums[mid])
                return searchCore(nums, target, left, mid-1);
            else
                return searchCore(nums, target, mid+1, right);
        }
        return false;
    }
    
    bool search(vector<int>& nums, int target) {
        if(nums.size()<=0)
            return false;
        bool res=false;
        res=searchCore(nums, target, 0, nums.size()-1);
        return res;
    }
};