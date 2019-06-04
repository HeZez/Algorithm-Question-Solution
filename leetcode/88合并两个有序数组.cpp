/*
    给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。
    说明:

    初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
    你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
    示例:

    输入:
    nums1 = [1,2,3,0,0,0], m = 3
    nums2 = [2,5,6],       n = 3

    输出: [1,2,2,3,5,6]
*/

/*
    这个问题如果从前向后插入，代价会比较大，
    一个优化的方法是从后向前插，找到两个数组有效的最后一位，之后比较大小，倒着插到nums1的后面
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m<0||n<0)
            return ;
        int p1=m-1;
        int p2=n-1;
        for(int i=m+n-1;i>=0;i--)
        {
            if(p1<0||p2<0)
            {
                if(p1<0)
                {
                    nums1[i]=nums2[p2];
                    p2--;
                }
                else
                {
                    nums1[i]=nums1[p1];
                    p1--;
                }
            }
            else
            {
                if(nums1[p1]>nums2[p2])
                {
                    nums1[i]=nums1[p1];
                    p1--;
                }
                else
                {
                    nums1[i]=nums2[p2];
                    p2--;
                }
            }
        }
    }
};