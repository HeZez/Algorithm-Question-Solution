/*
    给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。

    示例 1:
    输入: [1,2,3,4,5,6,7] 和 k = 3
    输出: [5,6,7,1,2,3,4]
    解释:
    向右旋转 1 步: [7,1,2,3,4,5,6]
    向右旋转 2 步: [6,7,1,2,3,4,5]
    向右旋转 3 步: [5,6,7,1,2,3,4]
    
    示例 2:
    输入: [-1,-100,3,99] 和 k = 2
    输出: [3,99,-1,-100]
    解释: 
    向右旋转 1 步: [99,-1,-100,3]
    向右旋转 2 步: [3,99,-1,-100]
    说明:

    尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
    要求使用空间复杂度为 O(1) 的 原地 算法。
*/
/*
    暴力移动在大数据量的情况下会超时
    用额外数组可以在O(n)时间复杂度解决 但是空间复杂度也是O(n)
    
    O(n)时间复杂度和 O(1)空间复杂度的方法有这么几种
    1. 翻转的方法： 先把整个数组翻转，之后再分别翻转前k个和后n-k个数
    2. 替换的方法 根据移动k步 其实可以把整个数组分为几个部分
    
        举例 1 2 3 4 5 6 k=2
        从1开始每次移动k步  包括 1-3-5-1 超过长度部分取余 又回到了1
        回到了原始起点后，先前前进一步 从2开始 有2-4-6-2 又回到了2
        
        可以按照这样的划分轮替每部分的元素，每个元素都换一遍位置 用一个变量记录换位置元素的个数
        达到要求时停止
*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();  // k可能比nums的大小还大
        /*
        // 翻转的方法
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
        */
        
        // 替换的方法
        int count = 0;  //count用来记录被移动位置元素的个数
        int next=0;
        int pre=0;
        int temp=0;
        for(int start=0;count<nums.size();start++)
        {
            next=start;
            pre=nums[start];
            do
            {
                next=(next+k)%nums.size();
                temp=nums[next];
                nums[next]=pre;
                pre=temp;
                count++;
            }while(next!=start);
        }
    }
};