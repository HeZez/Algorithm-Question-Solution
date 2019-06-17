/*
    给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

    说明：你不能倾斜容器，且 n 的值至少为 2。

    图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。

    示例:

    输入: [1,8,6,2,5,4,8,3,7]
    输出: 49

*/
/*
    为什么这种双指针移动的方法不会错过最优解呢？
    盛水的多少取决于两个指针对应高度中较小的那一个乘以两个指针的距离
    如果值大的指针向内移动，升水高度会小于等于当前的高度，两个指针之间的距离还缩小了，那么盛水的量就变少了
    这是一种贪心的思想吗？  其实我还是没有想明白为什么这么做不会错过最优值
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        // 我的思路是从两侧同时向中间遍历，分别为left right，然后选择两个中较短的那一个向中间移动一位，另一个不动
        // 直到两端相遇
        int left=0;
        int right=height.size()-1;
        int water_height=0;
        int result=0;
        while(left!=right)
        {
            water_height=(height[left]<=height[right])?height[left]:height[right];
            result=max(result,(right-left)*water_height);
            if(height[left]<=height[right])
                left++;
            else
                right-=1;
        }
        return result;
    }
};