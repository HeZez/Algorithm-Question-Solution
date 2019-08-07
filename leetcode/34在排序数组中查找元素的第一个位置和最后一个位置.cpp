/*
    给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

    你的算法时间复杂度必须是 O(log n) 级别。

    如果数组中不存在目标值，返回 [-1, -1]。

    示例 1:

    输入: nums = [5,7,7,8,8,10], target = 8
    输出: [3,4]
    示例 2:

    输入: nums = [5,7,7,8,8,10], target = 6
    输出: [-1,-1]
*/
/*
    我的最开始思路：先二分找到一个目标值，之后向两端扩展，但是这么做最差情况会退化为O（N）
    
*/
class Solution {
public:
    /*
    vector<int> searchRange(vector<int>& nums, int target) {
        int len=nums.size();
        vector<int > result;
        if(len<=0)
        {
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
        int pos=searchCore(nums, target, 0, len-1);
        if(pos==-1)
        {
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
        int left=pos;
        int right=pos;
        while(nums[left]==target&&left>=0)
        {
            left--;
            if(left<0)
            {
                left=0;
                break;
            }
            if(nums[left]!=target)
            {
                left++;
                break;
            }
        }
        while(nums[right]==target&&right<len)
        {
            right++;
            if(right>len-1)
            {
                right=len-1;
                break;
            }
            if(nums[right]!=target)
            {
                right--;
                break;
            }
        }
        result.push_back(left);
        result.push_back(right);
        return result;
    }
    
    int searchCore(vector<int>& nums, int target,int left, int right)
    {
        if(left==right)
        {
            if(nums[left]==target)
                return left;
            else
                return -1;   // 没找到目标值
        }
        int mid=(left+right)/2;
        if(nums[mid]==target) return mid;
        if(nums[mid]<target)
            return searchCore(nums, target, mid+1, right);
        else
            return searchCore(nums, target, left, mid);
    }
    */
    
    /*
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty())
        {
            vector r(2, -1);
            return r;
        }
        int len=nums.size();
        int left=searchCoreLeft(nums, target, 0, nums.size()-1);
        int right=searchCoreRight(nums, target, 0, nums.size()-1);
        vector<int> result;
        result.push_back(left);
        result.push_back(right);
        return result;
    }
    
    int searchCoreLeft(vector<int>& nums, int target, int left, int right)
    {
        if(left>=right)
        {
            if(nums[left]==target)
                return left;
            else
                return -1;
        }
        int mid=(left+right)/2;
        if(nums[mid]>target)
        {
            return searchCoreLeft(nums, target, left, mid-1);
        }
        else if(nums[mid]<target)
        {
            return searchCoreLeft(nums, target, mid+1, right);
        }
        else
        {
            return searchCoreLeft(nums, target, left, mid);
        }
    }
    
    int searchCoreRight(vector<int>& nums, int target, int left, int right)
    {
        if(left>=right)
        {
            if(nums[left]==target)
                return left;
            else
                return -1;
        }
        int mid=(left+right)/2;
        
        if(nums[mid]>target)
        {
            return searchCoreRight(nums, target, left, mid-1);
        }
        else if(nums[mid]<target)
        {
            return searchCoreRight(nums, target, mid+1, right);
        }
        else
        {
            if(mid==left)
            {
                if(nums[right]==target)
                    return right;
                else
                    return left;
            }
            else
            {
                return searchCoreRight(nums, target, mid, right);
            }
        }
    }
    */
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2, -1);
        if(nums.empty())
            return result;
        
        int len=nums.size();
        int left=searchCore(nums, target, true);
        if(left==nums.size()||nums[left]!=target)
            return result;
        result[0]=left;
        result[1]=searchCore(nums, target, false)-1;
        
        return result;
    }
    
    int searchCore(vector<int>& nums, int target, bool left)
    {
        int lo=0;
        int hi=nums.size();
        while(lo<hi)
        {
            int mid=(lo+hi)/2;
            if(nums[mid]>target||(left&&nums[mid]==target ))
            {
                hi=mid;
            }
            else
                lo=mid+1;
        }
        return lo;
    }
};