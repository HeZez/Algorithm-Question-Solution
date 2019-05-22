class Solution {
    /*
    题目描述：
    假设按照升序排序的数组在预先未知的某个点上进行了旋转。
    ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
    搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
    你可以假设数组中不存在重复的元素。
    你的算法时间复杂度必须是 O(log n) 级别。
    示例 1:
    输入: nums = [4,5,6,7,0,1,2], target = 0
    输出: 4
    示例 2:
    输入: nums = [4,5,6,7,0,1,2], target = 3
    输出: -1
    */
    /*
    要求O（logn） 二分查找 
    旋转的排序数组不能直接二分，可以先分成两半  一把有序 一半无序，如果在有序那一半里直接开始二分查找，不然的话递归另一半
    注意递归的下标界限
    */
public:
    int result=0;
    int search(vector<int>& nums, int target) {
        if(nums.size()<=0)
            return -1;
        return searchCore(nums, target, 0, nums.size()-1);
    }
    
    int  searchCore(vector<int>& nums, int target, int left, int right)
    {
        
        // 递归边界
        
        if(left>right)
        {
            return -1;
            /*
                if(left<nums.size()&&left>=0)
                {
                    if(target==nums[left])
                        return left;
                }
                else if(right>=0&&right<nums.size())
                {
                    if(target==nums[right])
                        return right;
                }
                else
                    return -1;
                */
        }
        
        int mid=(left+right)/2;
        if(nums[mid]==target)
            return mid;
        if(nums[right]>nums[left])   //完全升序  开始二分查找
        {
            if(target>nums[mid])
                return searchCore(nums, target,  mid+1,  right);
            else
                return searchCore(nums,  target,  left,  mid);
        }
        else   //中间存在旋转
        {
            if(nums[mid]>=nums[left])   // 旋转点在后半段
            {
                if(nums[left]<=target&&target<nums[mid])
                    return searchCore(nums,  target,  left,  mid-1);
                else
                    return searchCore(nums,  target,  mid+1,  right);
            }
            else     // 旋转点在前半段
            {
                if(target>nums[mid]&&target<=nums[right])
                    return searchCore(nums,  target,  mid+1,  right);
                else
                    return searchCore(nums,  target,  left,  mid-1);
            }
        }
        return -1;
    }
};