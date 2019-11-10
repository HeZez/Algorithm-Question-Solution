/*
    给定一个数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

返回滑动窗口中的最大值。

 

    示例:

    输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
    输出: [3,3,5,5,6,7] 
    解释: 

      滑动窗口的位置                最大值
    ---------------               -----
    [1  3  -1] -3  5  3  6  7       3
     1 [3  -1  -3] 5  3  6  7       3
     1  3 [-1  -3  5] 3  6  7       5
     1  3  -1 [-3  5  3] 6  7       5
     1  3  -1  -3 [5  3  6] 7       6
     1  3  -1  -3  5 [3  6  7]      7


    提示：

    你可以假设 k 总是有效的，在输入数组不为空的情况下，1 ≤ k ≤ 输入数组的大小。
*/

/*
    窗口大小是固定的，想起了之前的一个最小栈的题
    但是这里的窗口更像是一个队列，考虑一下是否能够这么应用
    
    这个单调队列应该怎么实现呢？
    
    评论区的做法是一个双向队列，c++中用vector即可模拟，
    
    *队列中记录的是对应元素的下标，这样就可和滑动窗口边界来比较
    *看当前队列头的元素是否还在窗口内
    
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.empty()||k==0)
            return nums;
        vector<int> res;
        vector<int> fakeQueue;
        int l=0,r=0;
        while(r<nums.size())
        {
            // 维护双向队列
            while(!fakeQueue.empty() && nums[fakeQueue.back()]<nums[r])
            {
                fakeQueue.pop_back();
            }
            fakeQueue.push_back(r);
            while(fakeQueue[0]<l)
                fakeQueue.erase(fakeQueue.begin());          
            if(r-l+1==k)
            {
                res.push_back(nums[fakeQueue[0]]);
                r++;
                l++;
            }
            else
                r++;
        }
        return res;
    }
};