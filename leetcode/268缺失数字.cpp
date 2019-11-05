/*

    给定一个包含 0, 1, 2, ..., n 中 n 个数的序列，找出 0 .. n 中没有出现在序列中的那个数。

    示例 1:

    输入: [3,0,1]
    输出: 2
    示例 2:

    输入: [9,6,4,2,3,5,7,0,1]
    输出: 8
    说明:
    你的算法应具有线性时间复杂度。你能否仅使用额外常数空间来实现?
*/

/*
    可以用bitmap来记录
    
    线性复杂度和常数空间其实可以用累加和的差值来算
    正常的0到n累加和与给定数组累加和的差值
    
    异或操作位运算也可以
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        /*
        int sumNorm=0;
        int sumNow=0;
        for(int i=1;i<=nums.size();i++)
            sumNorm+=i;
        for(int i=0;i<nums.size();i++)
            sumNow+=nums[i];
        return sumNorm-sumNow;
        */
        
    }
};