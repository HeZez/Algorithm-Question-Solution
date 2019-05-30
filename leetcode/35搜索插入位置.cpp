/*
    给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

    你可以假设数组中无重复元素。

    示例 1:

    输入: [1,3,5,6], 5
    输出: 2
    示例 2:

    输入: [1,3,5,6], 2
    输出: 1
    示例 3:

    输入: [1,3,5,6], 7
    输出: 4
    示例 4:

    输入: [1,3,5,6], 0
    输出: 0
*/

/*
    顺序查找 二分更快
*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size()==0)
            return 0;
        int result=-1;
        int len=nums.size();
        int left=0;
        int right=len-1;
        //二分查找
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(nums[mid]==target)
                return mid;
            else if(target>nums[mid])
                left=mid+1;
            else
                right=mid-1;
        }
        return left;
        /*
        // 顺序查找
        for(int i=0;i<len;i++)
        {
            if(nums[i]>=target)
            {
                result=i;
                break;
            }
        }
        
        if(result==-1)
            result=len;
        return result;
        */
    }
};