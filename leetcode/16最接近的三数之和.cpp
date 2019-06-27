/*
    给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

    例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.

    与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
*/
/*
    自己的思路：bfs限制深度，遍历所有可能结果，找到最小的,这种方法就是遍历所有的结果，在数据量大的时候，会超时
    
    一般的思路，先对数组排序，之后双指针控制范围，三个数，遍历整个数组，遍历时的位置确定第一个数
    剩下的两个数用双指针来确定范围，如果sum比target小，扩大左指针，如果比target小，减小右指针
*/
class Solution {
public:
    /*
    // 自己的想法 超时
    vector<int> sumList;
    void threeSumClosestCore(vector<int>& nums, int& target, int index, int left, int right, int tempSum) {
        // 递归边界
        if(index==3)
        {
            sumList.push_back(tempSum);
            return ;
        }
        for(int i=left ; i<=(nums.size()+index-3) ; i++ )
        {
            threeSumClosestCore(nums, target,index+1,i+1, nums.size()-1, tempSum+nums[i]);
            //resTemp=threeSumClosestCore(nums, target,index+1,i+1, nums.size()-1, tempSum+nums[i]);
            //res=res-target<resTemp-target? res : resTemp;
        }
    }
    
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.empty()||nums.size()<=2)
            return 0;
        int gap=INT_MAX;
        int index=0;
        int tempSum=0;
        int res=0;
        // 第一个值最多只能取到倒数第三个值，也就是
        for(int i=0 ; i<=(nums.size()+index-3) ; i++ )
        {
            threeSumClosestCore(nums, target,index+1,i+1, nums.size()-1, tempSum+nums[i]);
            //resTemp=threeSumClosestCore(nums, target,index+1,i+1, nums.size()-1, tempSum+nums[i]);
            //res=res-target<resTemp-target? res : resTemp;
        }
        for(int i=0;i<sumList.size();i++)
        {
            if(abs(sumList[i]-target)<gap)
            {
                gap=abs(sumList[i]-target);
                res=sumList[i];
            }
        }
        return res;
    }
    */
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.empty()||nums.size()<=2)
            return 0;
        int gap=INT_MAX;
        int index=0;
        int tempSum=0;
        int res=0;
        // 先排序
        sort(nums.begin(), nums.end());
        // 第一个值最多只能取到倒数第三个值，也就是
        for(int i=0 ; i<=nums.size()-3 ; i++ )
        {
            int l=i+1,r=nums.size()-1;
            while(l<r)
            {
                tempSum=nums[i]+nums[l]+nums[r];
                if(abs(tempSum-target)<gap)
                {
                    gap=abs(tempSum-target);
                    res=tempSum;
                }
                if(tempSum<target)
                    l++;
                else if(tempSum>target)
                    r--;
                else
                    return tempSum;
            }
        }
        
        return res;
    }
};