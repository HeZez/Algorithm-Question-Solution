static const auto __ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        double result;
        /*
        if((m+n)&1)
            result=findKth(nums1, 0, nums2, 0, (m+n+1)/2);
        else
            result=(findKth(nums1, 0, nums2, 0, (m+n+1)/2)+findKth(nums1, 0, nums2, 0, (m+n+2)/2))/2.0;
            */
        // 或者这里可以直接findKth(nums1, 0, nums2, 0, (m+n+1)/2)+findKth(nums1, 0, nums2, 0, (m+n+2)/2))/2.0
        // 因为如果m+n是奇数 (m+n+1)/2和(m+n+2)/2)相等，两数相加再除以2还是本身
        result=(findKth(nums1, 0, nums2, 0, (m+n+1)/2)+findKth(nums1, 0, nums2, 0, (m+n+2)/2))/2.0;
        return result;
    }
private:
    // 参数说明 nums1:第一个数组 i:数组1起始位置，nums2：第二个数组，j:数组2起始位置，k:要找到的第k个元素，注意k是第几个 不是数组下标
    double findKth(vector<int>& nums1, int i, vector<int>& nums2, int j, int k)
    {
        if(i>=nums1.size())
            return nums2[j+k-1]; //中位数不在nums1里
        if(j>=nums2.size())
            return nums1[i+k-1]; //中位数不在nums2里
        if(k==1)
            return min(nums1[i], nums2[j]);
        int val1=(i+k/2-1<nums1.size())?nums1[i+k/2-1]:INT_MAX;
        int val2=(j+k/2-1<nums2.size())?nums2[j+k/2-1]:INT_MAX;
        if(val1<val2)
            return findKth(nums1, i+k/2, nums2, j, k-k/2);
        else
            return findKth(nums1, i, nums2, j+k/2, k-k/2);
    }
};