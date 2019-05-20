class Solution {
    /*
        题目描述：
            给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
        示例:
        输入: [-2,1,-3,4,-1,2,1,-5,4],
        输出: 6
        解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
    */
    /*
    
      动态规划： m[i]表示长度为i的数组的最大子数组和
                m[1]=num[1]
                if(m[i-1]>0)
                    temp=m[i-1]+num[i]
                else
                    temp=nums[i]
                m[i]=max(temp, m[i-1])
                
      分治法：  最大和子数组可能出现在三处，将一个数组一分为2，目标可能出现在左半部分，右半部分 或者横跨中间的那部分中。
      边界条件：当一部分小于等于一个元素的时候，直接返回；  
    */
    
public:
    // 动态规划方法
    int maxSubArray(vector<int>& nums) {
        int maxSum=nums[0];
        int temp=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(temp>0)
                temp+=nums[i];
            else
                temp=nums[i];
            if(temp>maxSum)
                maxSum=temp;
        }
        
        return maxSum;
    }
/*
public:
    // 分治
    int maxSubArray(vector<int>& nums) {
        int left=0;
        int right=nums.size()-1;
        int result;
        result=findMaxSubArraySum(nums, left, right);
        return result;
    }

private:
    int findMaxSubArraySum(vector<int>& nums, int left, int right)
    {
        int result=0;
        if(left>right)
            return INT_MIN;
        if(right==left)
            return nums[left];
        int middle=(left+right)/2;
        int leftSum,rightSum,middleSum;
        // 递归运算左右两部分的最大加和
        leftSum=findMaxSubArraySum(nums, left, middle);
        rightSum=findMaxSubArraySum(nums, middle+1, right);
        // 选左右中较大的那个
        leftSum>rightSum?result=leftSum:result=rightSum;
        //获得横跨分界点的最大加和
        middleSum=findMaxSumMiddle(nums, left, middle, right);
        if(middleSum>result)
            result=middleSum;
        return result;
    }
    
    int findMaxSumMiddle(vector<int>& nums, int left, int middle, int right)
    {
        int leftSum=0;
        int maxL=INT_MIN;
        int rightSum=0;
        int maxR=INT_MIN;
        for(int i=middle;i>=left;i--)
        {
            
            leftSum+=nums[i];
            if(leftSum>maxL)
            {
                maxL=leftSum;
            }
        }
        for(int i=middle+1;i<=right;i++)
        {
            rightSum+=nums[i];
            if(rightSum>maxR)
            {
                maxR=rightSum;
            }
        }
        return maxL+maxR;
    }
*/
};