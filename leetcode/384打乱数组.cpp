/*
    打乱一个没有重复元素的数组。

示例:

    // 以数字集合 1, 2 和 3 初始化数组。
    int[] nums = {1,2,3};
    Solution solution = new Solution(nums);

    // 打乱数组 [1,2,3] 并返回结果。任何 [1,2,3]的排列返回的概率应该相同。
    solution.shuffle();

    // 重设数组到它的初始状态[1,2,3]。
    solution.reset();

    // 随机返回数组[1,2,3]打乱后的结果。
    solution.shuffle();
*/
/*
    实话说这题没太看懂什么意思
    评论中提到了两种方法 最直接的是直接调用stl中的随机排列方法

    评论其中还给出了一个更详尽的洗牌算法思路 就是在第n张牌的位置时  从前n-1张牌中随机选择一张与第n张交换
*/
class Solution {
private:
    vector<int> n;
public:
    Solution(vector<int>& nums) {
        n=nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return n;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> nCopy=n;
        // random_shuffle(nCopy.begin(), nCopy.end());   // stl中的洗牌算法
        
        // 自己实现的洗牌
        for(int i=1;i<nCopy.size();i++)
        {
            int r=rand()%(i+1);    // r是1到i的随机数
            if(i!=r)
            swap(nCopy[r], nCopy[i]);
        }
        return nCopy;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */