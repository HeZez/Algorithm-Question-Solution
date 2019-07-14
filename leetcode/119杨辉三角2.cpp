/*
    给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。

    在杨辉三角中，每个数是它左上方和右上方的数的和。

    示例:

    输入: 3
    输出: [1,3,3,1]
    进阶：

    你可以优化你的算法到 O(k) 空间复杂度吗？
*/
/*
    可以直接把整个杨辉三角给求出来，但是这样太直接了
    怎样直接求出第K行呢？
    或者用O（K）的额外空间，但是在这个空间上完成全部的迭代
    在O(K)的空间上完成整个递推的过程,使用两个临时变量来保存临时结果
    
    解法相当于倒着生长
*/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex+1, 0);
        result[0]=1;
        for(int i=0; i<rowIndex+1; i++)
        {
            for(int j=i; j>=1; j--)
            {
                result[j]+=result[j-1];
            }
        }
        return result;
    }
};