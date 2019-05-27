/*
    给定一个非负整数数组，你最初位于数组的第一个位置。

    数组中的每个元素代表你在该位置可以跳跃的最大长度。

    判断你是否能够到达最后一个位置。
    示例 1:

    输入: [2,3,1,1,4]
    输出: true
    解释: 从位置 0 到 1 跳 1 步, 然后跳 3 步到达最后一个位置。
    示例 2:

    输入: [3,2,1,0,4]
    输出: false
    解释: 无论怎样，你总会到达索引为 3 的位置。但该位置的最大跳跃长度是 0 ， 所以你永远不可能到达最后一个位置。
*/
/*
    // 猜测的贪心策略：走当前可能到达的目标中，能够到达最远处的那个位置(想错了)
    另一个贪心策略：经过观察发现，这道题不是在问怎样最少步到达终点，而是能否到达终点
    由于是一个非负的数组，到不了终点的情况是这个数组中有0出现，并且无论如何都跳不过这个0，
    这种情况就是0之前的所有位置跳跃步数加上那个位置的坐标结果没有0元素的坐标大
    
    所以我的思路是:首先判断数组中0的位置，如果数组里没有0就true
                    发现发现0之后，看这个0与前一个0之间的元素中能否满足上面提到的条件，能满足则继续判断，否则false
    
    大佬的思路是从后往前找。会更快
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len=nums.size();
        if(len<=0) return false;
        //if(nums[0]==0) return false;
        // 特殊情况 如果输入是[0] 应返回true
        if(len==1&&nums[0]==0) return true;
        bool result=true;
        bool flag=false;
        int temp=0;
        for(int i=0;i<len;i++)
        {
            if(nums[i]==0)
            {
                temp=i;
                // 分析两种情况 根据题中的要求， 如果等于0的位置是最后一个位置，那么只要能到这个位置就可以了
                //  如果不是在最后一个位置的0 就需要超过才可以
                if(i==len-1)
                {
                     while(temp>=1)
                    {
                        temp--;
                        if(temp+nums[temp]>=i)
                        {
                            flag=true;
                            break;
                        }
                    }   
                }
                else
                {
                    while(temp>=1)
                    {
                        temp--;
                        if(temp+nums[temp]>i)
                        {
                            flag=true;
                            break;
                        }
                    }      
                }
                      
                if(flag)
                    flag=false;
                else
                {
                    result=false;
                    break;
                }
                
            }
        }
        return result;
    }
};