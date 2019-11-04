/*
    给定一个大小为 n 的数组，找出其中所有出现超过 ⌊ n/3 ⌋ 次的元素。

    说明: 要求算法的时间复杂度为 O(n)，空间复杂度为 O(1)。

    示例 1:
    输入: [3,2,3]
    输出: [3]
    
    示例 2:
    输入: [1,1,1,3,3,2,2,2]
    输出: [1,2]
*/

/*
    最简单的思路 用Hash表来记录所有元素出现的次数，这样时间复杂度可以是on 但是空间复杂度不是o1
    
    根据提示 其实出现次数超过n/3次的数字 最多有两个，
    上一题求众数1中要求的是求出出现次数大于n/2的数字，用的是摩尔投票法
    这里也可以对这一方法进行改进
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int major1=0, major2=0, count1=0, count2=0;
        vector<int> result;
        for(int i=0;i<nums.size();i++)
        {
			//  这里的判断条件不是很容易解释清楚
            if((count1==0||nums[i]==major1)&&nums[i]!=major2 )
            {
                major1=nums[i];
                count1++;   
            }
            else if(count2==0||nums[i]==major2)
            {
                major2=nums[i];
                count2++;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        count1=0;
        count2=0;
        // 判断major中存的数字是否在原数组中出现次数超过n/3
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==major1)
                count1++;
            if(nums[i]==major2)
                count2++;
        }
        //cout<<major1<<","<<major2<<endl;
        
        if(count1>nums.size()/3)
            result.push_back(major1);
        if(major1!=major2&&count2>nums.size()/3)
            result.push_back(major2);
        
        return result;
    }
};