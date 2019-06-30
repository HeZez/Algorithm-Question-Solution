/*
    给定一个整数数组 nums ，找出一个序列中乘积最大的连续子序列（该序列至少包含一个数）。

    示例 1:

    输入: [2,3,-2,4]
    输出: 6
    解释: 子数组 [2,3] 有最大乘积 6。
    示例 2:

    输入: [-2,0,-1]
    输出: 0
    解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
*/
/*
    整个数组中如果没有0存在，那么是把所有数都乘起来的结果绝对值最大，但是由于负负得正，符号无法准确确定
    如果奇数个负数就是从左到右和从右到左进行两次遍历，去掉对应顺序最后一个负数和之后的元素，比较两个结果大小
    
    或者可以一次遍历完成，在遇到一个负数之后，之前的最大正数乘以这个负数，结果就变成了最小了，可以设置两个
    变量记录最大值和最小值，在遇到负数时互换这两个值
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int res=INT_MIN;
        int tempMax=1;
        int tempMin=1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<0)
            {
                int temp=tempMax;
                tempMax=tempMin;
                tempMin=temp;
            }
            tempMax=max(tempMax*nums[i], nums[i]);
            tempMin=min(tempMin*nums[i], nums[i]);
            res=max(res, tempMax);
        }
        return res;
    }
};