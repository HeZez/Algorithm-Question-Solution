/*
    给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。

    函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。
    
    说明:
    返回的下标值（index1 和 index2）不是从零开始的。
    你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
    示例:

    输入: numbers = [2, 7, 11, 15], target = 9
    输出: [1,2]
    解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。
    
*/
/*
    可以直接暴力找，因为数组升序排序，只要找数组中那些小于target/2的部分
    可以用hash表存一下，之后找
    不过这道题中没说可不可以存在重复元素，如果可以存在重复，还要求返回index
    value应该是个数组
    
    因为是有序的题解中也提到了可以用双指针
    如果两数加和小于target 左指针前进，小于target 右指针后退
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int > res;
        if(numbers.size()<2)
            return res;
        int left=0, right=numbers.size()-1;
        while(left<right)
        {
            if(numbers[left]+numbers[right]>target)
                right--;
            else if(numbers[left]+numbers[right]<target)
                left++;
            else
            {
                res.push_back(left+1);
                res.push_back(right+1);
                break;
            }
        }
        return res;
    }
};