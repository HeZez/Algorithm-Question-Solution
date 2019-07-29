/*
    给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

    你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

    示例:

    给定 nums = [2, 7, 11, 15], target = 9

    因为 nums[0] + nums[1] = 2 + 7 = 9
    所以返回 [0, 1]
*/
/*
    用一个hash表存储数组中的数据，key为元素值， value为对应元素下标
    这样可以O(1)的确定某一个数字是否存在与数组中并找到索引，
    接下来遍历原数组寻找当前数字num的互补数字target-num是否存在即可
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // map底层实现是红黑树，unordered_map底层实现是哈希表
        // 在这里我们想要得到在查找时为O（1）复杂度，选择哈希表
        unordered_map<int,int> m;
        int size=nums.size();
        int temp;
        vector<int> result(2,0);
        // 创建哈希表
        for(int i=0;i<size;i++)
        {
            m[nums[i]]=i;
        }
        for(int i=0;i<size-1;i++)
        {
            temp=nums[i];
            if(m[target-temp]!=NULL)
                if(m[target-temp]!=i)
                {
                    result[0]=i;
                    result[1]=m[target-temp];
                }
        }
        return result;
    }
};