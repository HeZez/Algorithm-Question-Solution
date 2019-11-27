/*
    给定一个无序的整数数组，找到其中最长上升子序列的长度。

    示例:

    输入: [10,9,2,5,3,7,101,18]
    输出: 4 
    解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。

    说明:
    可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
    你算法的时间复杂度应该为 O(n2) 。
    进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?
*/
/*
    最笨最直接的方法是什么？
    N^2的方法是动态规划
    一个是dp数组，用来存储dp[i]表示从0到i的字符的最长上升序列的长度
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty())
            return 0;
        vector<int> dp(nums.size(), 1);
        //vector<int> tail(nums.size(), 0);
        int res=1;
        dp[0]=1;
        //tail[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                    dp[i]=max(dp[i], dp[j]+1);
                res=max(dp[i], res);
            }
        }
        /*
        for(auto item:dp)
            cout<<item<<",";
        cout<<endl;
        */
        return res;
    }
};