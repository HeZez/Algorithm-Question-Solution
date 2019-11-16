/*
    给定一个整数数组  nums，求出数组从索引 i 到 j  (i ≤ j) 范围内元素的总和，包含 i,  j 两点。

    示例：

    给定 nums = [-2, 0, 3, -5, 2, -1]，求和函数为 sumRange()

    sumRange(0, 2) -> 1
    sumRange(2, 5) -> -1
    sumRange(0, 5) -> -3
    说明:

    你可以假设数组不可变。
    会多次调用 sumRange 方法。
*/
/*
    最直接的方法是直接去算加和
    因为sum会被多次调用，所以直接直接算加和效率太低
    可以用一个数组sum存前i个数的加和
    之后i到j 可以用sum[j]-s[i-1]
*/
class NumArray {
private: vector<int> myNums;
public:
    NumArray(vector<int>& nums) {
        myNums=nums;
    }
    
    int sumRange(int i, int j) {
        int res=0;
        for(int k=i;k<=j;k++)
            res+=myNums[k];
        return res;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */