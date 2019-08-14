/*
    假设按照升序排序的数组在预先未知的某个点上进行了旋转。
    ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
    请找出其中最小的元素。
    你可以假设数组中不存在重复元素。

    示例 1:
    输入: [3,4,5,1,2]
    输出: 1
    
    示例 2:
    输入: [4,5,6,7,0,1,2]
    输出: 0
*/
/*
    二分查找，因为存在旋转点，就要比较mid和两端的值来确定旋转位置在前半部分或者是后半部分中
    
    比较的时候注意比较mid和right，因为如果使用数组下标来作为left和right值 mid=(left+right)/2
    当left和right仅相差一的时候，left=mid 比较起来要考虑的特殊情况比较多
    所以直接比较mid和right的数组元素值
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        //int min=findMinCore(nums, 0, nums.size()-1);
        if(nums.size()==1)
            return nums[0];
        return findMinCore(nums, 0, nums.size()-1);
    }
    int findMinCore(vector<int>& nums, int left, int right)
    {
        // 递归边界 
        if(left>=right)
            return nums[left];
        int mid=(left+right)/2;
        // 注意这里比较的时候要比较mid和right
        if(nums[mid]<nums[right])
            return findMinCore(nums, left, mid);
        else
            return findMinCore(nums, mid+1, right);
    }
};
