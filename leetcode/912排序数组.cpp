/*
    给定一个整数数组 nums，将该数组升序排列。

    示例 1：
    输入：[5,2,3,1]
    输出：[1,2,3,5]
    
    示例 2：
    输入：[5,1,1,2,0,0]
    输出：[0,0,1,1,2,5]


    提示：
    1 <= A.length <= 10000
    -50000 <= A[i] <= 50000
*/
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        if(nums.empty())
            return nums;
        quicksort(nums, 0, nums.size()-1);
        return nums;
    }
    void quicksort(vector<int>& nums, int l, int r)
    {
        if(l<r)
        {
            int q=partitionDoublePoint(nums, l, r);
            quicksort(nums, l, q-1);
            quicksort(nums, q+1, r);
        }
    }
    /*
    int partition(vector<int>& nums, int l, int r)
    {
        // 算法导论中快排的伪代码实现
        int flag=nums[r];
        int i=l-1;
        for(int j=l;j<=r-1;j++)
        {
            if(nums[j]<=flag)
            {
                i++;
                swap(nums[i],nums[j]);
            }
        }
        swap(nums[i+1], nums[r]);
        return i+1;
    }
    */
    int partitionDoublePoint(vector<int>& nums, int l, int r)
    {
        // 严蔚敏数据结构中的快速排序实现
        int flag=nums[l];
        int i=l, j=r;
        while(i<j)
        {
            while(i<j&&nums[j]>flag)
                j--;
            //swap(nums[i], nums[j]);
            
            while(i<j&&nums[i]<=flag)
                i++;
            swap(nums[i], nums[j]);
            
        }
        swap(nums[i], nums[l]);
        return i;
    }
};