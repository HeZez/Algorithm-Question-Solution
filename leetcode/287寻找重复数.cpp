/*
    给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和 n），可知至少存在一个重复的整数。假设只有一个重复的整数，找出这个重复的数。

    示例 1:

    输入: [1,3,4,2,2]
    输出: 2
    示例 2:

    输入: [3,1,3,4,2]
    输出: 3
    说明：

    不能更改原数组（假设数组是只读的）。
    只能使用额外的 O(1) 的空间。
    时间复杂度小于 O(n2) 。
    数组中只有一个重复的数字，但它可能不止重复出现一次。
*/
/*
    常数空间复杂度 没法用map
    
    原地修改的话 这个印象里可以用bitmap来做
    数字都是1到n的可以在原数组上调换数字顺序用原数组做自己的bitmap
    
    但是这个调换顺序的思路并不太好想到
    等等。。。。。这是只读数组，不能修改原数组。。。。。。
    
    解决这个问题比较好的一个方法是快慢指针的方法
    即快指针一次移动两步，慢指针一次移动一步
    由于数据的范围是1到n 可以把整个数组当成一个链表来循环，
    由于存在一个重复的元素 所以链表一定成环，为什么这么说呢，举一个例子
     
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=0,fast=0;
        while(true)
        {
            fast=nums[nums[fast]];
            slow=nums[slow];
            if(fast==slow)
            {
                fast=0;
                while(nums[fast]!=nums[slow])
                {
                    fast=nums[fast];
                    slow=nums[slow];
                }
                return nums[slow];
            }
        }
    }
};