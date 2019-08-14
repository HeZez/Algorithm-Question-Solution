/*
    峰值元素是指其值大于左右相邻值的元素。

    给定一个输入数组 nums，其中 nums[i] ≠ nums[i+1]，找到峰值元素并返回其索引。

    数组可能包含多个峰值，在这种情况下，返回任何一个峰值所在位置即可。

    你可以假设 nums[-1] = nums[n] = -∞。

    示例 1:
    输入: nums = [1,2,3,1]
    输出: 2
    解释: 3 是峰值元素，你的函数应该返回其索引 2。
    
    示例 2:
    输入: nums = [1,2,1,3,5,6,4]
    输出: 1 或 5 
    解释: 你的函数可以返回索引 1，其峰值元素为 2；
         或者返回索引 5， 其峰值元素为 6。
         
    说明:
    你的解法应该是 O(logN) 时间复杂度的。
*/
/*
    顺次判断很容易，但是时间复杂度为O(N)
    要求O(logN)
    那么就是二分查找，关键是这个问题如果确定二分的条件
    用nums[mid]和nums[mid+1]比较
    需要注意的是，这里的峰值还可以是单调递减序列的最高值，即 5 4 3 2 1 这个5也可以是峰值
    这样的话上面的比较方式就可以解释的通了
    也就是看nums[mid]和nums[mid+1]是在一个上坡过程中还是在下坡过程中
*/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        int left=0,right=nums.size()-1;
        return findPeakElementCore(nums, left, right);
    }
    int findPeakElementCore(vector<int>& nums, int left, int right)
    {
        // 递归边界
        if(left>=right)
            return left;
        int mid=(left+right)/2;
        if(nums[mid+1]>nums[mid])
            return findPeakElementCore(nums, mid+1, right);
        else 
            return findPeakElementCore(nums, left, mid);
    }
};