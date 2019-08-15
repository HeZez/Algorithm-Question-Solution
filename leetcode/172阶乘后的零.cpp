/*
    给定一个整数 n，返回 n! 结果尾数中零的数量。

    示例 1:
    输入: 3
    输出: 0
    解释: 3! = 6, 尾数中没有零。
    
    示例 2:
    输入: 5
    输出: 1
    解释: 5! = 120, 尾数中有 1 个零.
    说明: 你算法的时间复杂度应为 O(log n) 。
*/
/*
    关键是怎样做到O(log n)
    二分算乘积？
    
    按照大佬们的思路，可以看这些数中有多少个5来确定0的个数
    因为0出现是2*5=10这样的过程产生的，也就是偶数和含有5为因数的数字相乘结果都含有0
    偶数要比含5为因子的数字更多，所以只考虑含有5为因子的数字的个数即可
*/
class Solution {
public:
    int trailingZeroes(int n) {
        int res=0;
        while(n>=5)
        {
            res+=n/5;
            n/=5;
        }
        return res;
    }
};