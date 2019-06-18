/*
    编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：

    每行中的整数从左到右按升序排列。
    每行的第一个整数大于前一行的最后一个整数。
    示例 1:

    输入:
    matrix = [
      [1,   3,  5,  7],
      [10, 11, 16, 20],
      [23, 30, 34, 50]
    ]
    target = 3
    输出: true
    示例 2:

    输入:
    matrix = [
      [1,   3,  5,  7],
      [10, 11, 16, 20],
      [23, 30, 34, 50]
    ]
    target = 13
    输出: false
*/
/*
    有点烦，直接顺序查找的话时间复杂度是O(N)，所以我们要用的方法时间复杂度一定要比这个低，
    排过序了，那就二分，主要是怎么处理多行这种情况
    或者查看最左侧一列或者最右侧一列，确定target在哪一行之间
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()||matrix[0].empty())
            return false;
        int rowLen=matrix.size();
        int colLen=matrix[0].size();
        int row=-1;
        if(target>matrix[rowLen-1][colLen-1])
            return false;
        for(int i=rowLen-1;i>=0;i--)
        {
            if(i!=0)
            {
                if(matrix[i][colLen-1]==target)
                    return true;
                else if(matrix[i][colLen-1]>target&&matrix[i-1][colLen-1]<target)
                {
                    row=i;      // 确定所在行
                    break;
                }
            }
            else
            {
                row=i;
                break;
            }
        }
        for(int j=0;j<colLen;j++)
        {
            if(matrix[row][j]==target)
                return true;
        }
        return false;
    }
};