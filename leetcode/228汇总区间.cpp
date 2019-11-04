/*
    给定一个无重复元素的有序整数数组，返回数组区间范围的汇总。

        示例 1:
        输入: [0,1,2,4,5,7]
        输出: ["0->2","4->5","7"]
        解释: 0,1,2 可组成一个连续的区间; 4,5 可组成一个连续的区间。
        
        示例 2:
        输入: [0,2,3,4,6,8,9]
        输出: ["0","2->4","6","8->9"]
        解释: 2,3,4 可组成一个连续的区间; 8,9 可组成一个连续的区间。
*/

/*
    用两个变量来记录左右区间 之后顺次遍历，分情况讨论
    
    双指针滑动窗口
*/
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        int left=0, right=0;
        vector<string> res;
        if(nums.size()<1)
            return res;
        string s="";
        for(int i=1; i<nums.size();i++)
        {
            if(nums[i]-1==nums[i-1])
            {
                right=i;
            }
            else
            {
                s="";
                if(left==right)
                {
                    s+=to_string(nums[left]);
                }
                else
                {
                    s=to_string(nums[left])+"->"+to_string(nums[right]);;
                }
                left=right=i;
                res.push_back(s);
            }
        }
        // 这种方式最后一个区间是没被处理的，额外处理一下
        s="";
        if(left==right)
        {
            s+=to_string(nums[left]);
        }
        else
        {
            s=to_string(nums[left])+"->"+to_string(nums[right]);;
        }
        res.push_back(s);
        return res;
        
    }
};