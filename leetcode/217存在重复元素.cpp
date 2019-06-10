/*
    给定一个整数数组，判断是否存在重复元素。
    如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。

    示例 1:

    输入: [1,2,3,1]
    输出: true
    示例 2:

    输入: [1,2,3,4]
    输出: false
    示例 3:

    输入: [1,1,1,3,3,4,3,2,4,2]
    输出: true
*/

/*
    方法可以用map或set，但是从结果来看 对数组排序之后比较相邻的元素是否相等耗时更低？
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        /*
        if(nums.empty())
            return false;
        int len=nums.size();
        set<int> sFlag;
        bool result=false;
        for(int i=0;i<len;i++)
        {
            sFlag.insert(nums[i]);
        }
        if(sFlag.size()==len)
            result=false;
        else
            result=true;
        return result;
        */
        
        if(nums.empty())
            return false;
        int len=nums.size();
        map<int,int> flag;
        for(int i=0;i<len;i++)
        {
            flag[nums[i]]++;
            if(flag[nums[i]]>1)
                return true;
        }
        /*
        map<int,int>::iterator im;
        for(im=flag.begin();im!=flag.end();im++)
        {
            if(im->second>1)
                return true;
        }
        */
        return false;
        
    }
};