/*
    给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。

    你可以假设数组是非空的，并且给定的数组总是存在众数。

    示例 1:

    输入: [3,2,3]
    输出: 3
    示例 2:

    输入: [2,2,1,1,1,2,2]
    输出: 2
*/
/*
    可以用hash表记录结果
    
    也可以用摩尔投票法 
    摩尔投票法的思路是：用两个变量来记录遍历过程中的结果，分别是major和count
    major记录当前最多出现的那个元素，count记录当前最多出现元素出现的次数
    如果count=0，那就计数加一，并且把当前元素记录为最多出现元素major
    如果count!=0，那么就看当前元素和major元素是否相等，相等count++否则count--;
    最后如果数组中存在出现次数大于数组长度一半的众数，major中存储的就是这个众数
    
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major=0;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(count==0)
            {
                major=nums[i];
                count++;
            }
            else 
            {
                if(nums[i]==major)
                    count++;
                else
                    count--;
            }
        }
        return major;
    }
};