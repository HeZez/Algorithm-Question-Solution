/*
    给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

    示例:
    输入: [0,1,0,3,12]
    输出: [1,3,12,0,0]
    说明:
    必须在原数组上操作，不能拷贝额外的数组。
    尽量减少操作次数。
*/
/*
    双指针，快指针移动，把非零元素拷贝到慢指针的位置，同时在快指针遍历完毕后，
    慢指针遍历并将值赋为零
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int fast=0,slow=0;
        while(fast<nums.size())
        {
            if(nums[fast]!=0)
            {
                nums[slow++]=nums[fast++];
            }
            else
                fast++;   
        }
        while(slow<nums.size())
            nums[slow++]=0;
        
    }
};