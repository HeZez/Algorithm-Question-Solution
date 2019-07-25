/*
    给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的连续子数组。如果不存在符合条件的连续子数组，返回 0。

    示例: 
    输入: s = 7, nums = [2,3,1,2,4,3]
    输出: 2
    解释: 子数组 [4,3] 是该条件下的长度最小的连续子数组。

    进阶:
    如果你已经完成了O(n) 时间复杂度的解法, 请尝试 O(n log n) 时间复杂度的解法。
*/
/*
    双指针滑动窗口
    两个指针一开始指向头部 如果左右指针内的数小于target 右指针右移，如果左指针向左移动后仍然满足条件，直到不满足条件
    记录满足条件的窗口的最小大小
*/
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int left=0,right=0;
        int sumTemp=0;
        int minWin=INT_MAX;
        //if(nums.empty())
         //   return minWin==INT_MAX?0:minWin;;
        while((right<nums.size()&&left<=right)||(sumTemp>=s&&left<=right))
        {
            if(sumTemp<s)
            {
                sumTemp+=nums[right];
                right++;
            }
            else
            {
                minWin=min(minWin, (right-left));
                sumTemp=sumTemp-nums[left];
                left++;
            }
        }
        return minWin==INT_MAX?0:minWin;
    }
};