class Solution {
    /*
    实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
    如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
    必须原地修改，只允许使用额外常数空间。
    以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
    1,2,3 → 1,3,2
    3,2,1 → 1,2,3
    1,1,5 → 1,5,1
    */
    
    /*
        没看懂这题啥意思，根据评论区大佬的思路 解题步骤是这样的
        1. 从右向左找  找到第一个数对 num[i-1]<num[i]
        2. 记住i-1的位置与数字  从i到数组结束找那个比num[i-1]大的数中最小的那个  这部分应该是逆序的 从末尾向前找即可
        3. 找到后交换两个数
        4. 对i到数组末尾重新排序 ，由于这部分是逆序的， 直接首尾交换即可  O（n/2）
        5. 如果找不到1中的数对 直接翻转整个数组
    */
    
public:
    void nextPermutation(vector<int>& nums) {
        int temp=0;
        if(nums.size()<=1)
            return ;
        for(int i=nums.size()-1;i>=1;i--)
        {
            if(nums[i-1]<nums[i])
            {
                temp=nums.size()-1;
                while(temp>=i)
                {
                    if(nums[temp]>nums[i-1])
                    {
                        swapByMyself(nums, i-1, temp);
                        break;
                    }
                    temp--;
                }
                // 对i到数据结束重新排序  这部分是降序的  不断首尾交换即可
                temp=0;
                while(i+temp<=nums.size()-1-temp)
                {
                    swapByMyself(nums, i+temp, nums.size()-1-temp);
                    temp++;
                }
                break;
            }
            if(i==1)
            {
                //翻转整个数组
                reverse(nums.begin(), nums.end());
            }
        }
    }
    
    void swapByMyself(vector<int>& nums, int i, int j)
    {
        int temp=0;
        temp=nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
    }
};