/*
    给定一个无序的数组，找出数组在排序之后，相邻元素之间最大的差值。

    如果数组元素个数小于 2，则返回 0。

    示例 1:

    输入: [3,6,9,1]
    输出: 3
    解释: 排序后的数组是 [1,3,6,9], 其中相邻元素 (3,6) 和 (6,9) 之间都存在最大差值 3。
    示例 2:

    输入: [10]
    输出: 0
    解释: 数组元素个数小于 2，因此返回 0。
    说明:

    你可以假设数组中所有元素都是非负整数，且数值在 32 位有符号整数范围内。
    请尝试在线性时间复杂度和空间复杂度的条件下解决此问题。
*/
/*
    直接排序再找，并不难，但是怎样在线性时间和空间复杂度的条件下解决这一问题？
    一开始看到线性时间和空间复杂度，往dp这个方向考虑了，但是想了一下没想出办法来
    但是评论区的说法一般是桶排序或者计数排序这样O(N)时间复杂度的排序算法
    
    正好来学习一下这两种排序的具体步骤吧
    基于交换的排序时间复杂度最低是O(NlogN)
    但是桶排序，计数排序，基数排序用空间换时间 把排序时间复杂度降低到了O(n)
    计数排序和桶排序都会使用辅助数组来对排序进行辅助
    
    计数排序：假如待排序的数组中数字都是大于等于0，最大值为k的数，那么可以用三个数组来完成整个排序过程
    一个原始数组A，一个计数数组B，一个结果数组C
    计数数组的下标是0到k，遍历A A[i]=x,于是B[x]++， 最后遍历计数数组B来统计结果C，B中那些非0的位置是我们所关心的
    B[x]=y 表示A中有y个x，只要顺次遍历填上结果即可（这是桶排序的做法）
    或者计算结果B[i]=B[i]+B[i-1]，来确定B中每个元素在C中的具体位置
    
    桶排序：就像上面说的，直接根据B来填写C是桶排序的做法，不过有一个问题是，如果最大值k比较大，那么数组B也会很大
    
    同时排序建立辅助数组的时候，可以根据待排序数组的最小值和最大值来分桶
    如果桶的大小是1 那么就是计数排序，
    桶的大小可以将N等分，之后再分别对桶内进行排序，接下来归并得到最终结果
*/
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2||nums.empty())
            return 0;
        /*
        // 普通排序
        sort(nums.begin(),nums.end());
        int res=-1;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i+1]-nums[i]>res)
                res=nums[i+1]-nums[i];
        }
        return res;
        */
        
        // 桶排序
        // 先找极大极小
        int maxN=INT_MIN,minN=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>maxN)
                maxN=nums[i];
            if(nums[i]<minN)
                minN=nums[i];
        }
        // 这道题还有一个隐藏信息，就是最大的间距，下界是(max-min)/(numSize-1)
        // 这样分桶，最大间隔一定出现在桶之间而不是桶之内
        // 也就是当前桶内的最小值和上一个桶内的最大值的差值
        // 这才是最关键的部分
        int length=nums.size();
        int bucket_size=max(1,(maxN-minN)/(length-1));  // 每个桶中有多少个位置
        int bucket_num=(maxN-minN)/bucket_size+1;  //多少个桶
        if(bucket_num<=1)
            return maxN-minN;
        vector<int> bucket_max(bucket_num, INT_MIN);
        vector<int> bucket_min(bucket_num, INT_MAX);
        vector<int> bucket_count(bucket_num, 0);
        int bucket_id=0;
        for(auto item: nums)
        {
            bucket_id=(item-minN)/bucket_size;
            bucket_count[bucket_id]++;
            bucket_max[bucket_id]=bucket_max[bucket_id]<item ? item:bucket_max[bucket_id];
            bucket_min[bucket_id]=bucket_min[bucket_id]>item ? item:bucket_min[bucket_id];
        }
        int maxGap=-1;
        int lastMax=minN;
        for(int i=0;i<bucket_num;i++)
        {
            if(bucket_count[i]>0)
            {
                maxGap=max(maxGap, bucket_min[i]-lastMax);
                lastMax=bucket_max[i];
            }
        }
        return maxGap;
    }
};