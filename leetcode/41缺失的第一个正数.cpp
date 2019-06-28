/*
    给定一个未排序的整数数组，找出其中没有出现的最小的正整数。

    示例 1:
    输入: [1,2,0]
    输出: 3
    
    示例 2:
    输入: [3,4,-1,1]
    输出: 2
    
    示例 3:
    输入: [7,8,9,11,12]
    输出: 1
    说明:

    你的算法的时间复杂度应为O(n)，并且只能使用常数级别的空间。
*/
/*
    给出的数组全是整数，并且要求O（N）时间复杂度，常数级别额外空间
    
    最直观的方法是用一个hashmap来记录出现的情况，之后从1开始找，找第一个没出现的，但是这样做不是常数额外空间
    或者可以用一个数组，只考虑那些小于数组长度的值，把这些值放到特定位置，特定位置是下标和当前数值相同的位置，相当于用数组实现hash
    用数组就可以考虑在原数组上操作，遍历逐位操作，之后找第一个数值和下标不相同位置，这个位置的下标+1就是结果
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.empty())
            return 1;
        int res=nums.size()+1;
        for(int i=0;i<nums.size();i++)
        {
             // 注意判断条件 要求值大于零，小于数组长度
            while(nums[i]>0 && nums[i]<=nums.size() && nums[i]!=nums[nums[i]-1]) 
            {
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=i+1)
            {
                res=i+1;
                break;
            }
        }
        return res;
    }
};