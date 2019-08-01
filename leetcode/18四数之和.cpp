/*
    给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

    注意：

    答案中不可以包含重复的四元组。

    示例：

    给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。

    满足要求的四元组集合为：
    [
      [-1,  0, 0, 1],
      [-2, -1, 1, 2],
      [-2,  0, 0, 2]
    ]
*/

/*
    用和三数之和差不多的思路， 这回固定两个数  双指针求另外剩下的两个
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> results;
        if(nums.size()<4)
            return results;
        vector<int> temp(4, 0);
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size()-3; )
        {
            for(int j=i+1;j<nums.size()-2; )
            {
                for(int k=j+1, l=nums.size()-1;k<l; )
                {
                    if(target-nums[i]-nums[j]>nums[k]+nums[l])
                    {
                        k++;
                    }
                    else if(target-nums[i]-nums[j]<nums[k]+nums[l])
                    {
                        l--;
                    }
                    else
                    {
                        temp[0]=nums[i] ;
                        temp[1]=nums[j] ;
                        temp[2]=nums[k] ;
                        temp[3]=nums[l] ;
                        results.push_back(temp);
                        // 过滤重复值
                        do{
                            k++;
                        }while(k<l&&nums[k]==nums[k-1]);
                        do{
                            l--;
                        }while(k<l&&nums[l]==nums[l+1]);
                    }
                }
                // 过滤j的重复值
                do{
                    j++;
                }while(j<nums.size()-2&&nums[j]==nums[j-1]);
            }
            // 过滤i的重复值
            do{
                i++;
            }while(i<nums.size()-3&&nums[i]==nums[i-1]);
        }
        return results;
    }
};