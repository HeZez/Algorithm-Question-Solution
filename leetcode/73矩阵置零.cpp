/*
    给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法。

    示例 1:

    输入: 
    [
      [1,1,1],
      [1,0,1],
      [1,1,1]
    ]
    输出: 
    [
      [1,0,1],
      [0,0,0],
      [1,0,1]
    ]
    示例 2:

    输入: 
    [
      [0,1,2,0],
      [3,4,5,2],
      [1,3,1,5]
    ]
    输出: 
    [
      [0,0,0,0],
      [0,4,5,0],
      [0,3,1,0]
    ]
    进阶:

    一个直接的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
    一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
    你能想出一个常数空间的解决方案吗？
*/

/*
    要求原地修改 根据提示，可以将每一行和每一列的元素先置0 作为这一行或者这一列置零的标志
    之后再扫描一遍
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        if(m==0||n==0)
            return ;
        bool rowFlag=false;
        bool colFlag=false;
        //先判断一下第一行和第一列有没有零元素 需不需要置零
        for(int i=0;i<m;i++)
        {
            if(matrix[i][0]==0)
            {
                // 第一列需要置零
                colFlag=true;
                break;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(matrix[0][i]==0)
            {
                // 第一行需要置零
                rowFlag=true;
                break;
            }
        }
        // 先把每一行和每一列的第一个元素置零
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        // 之后根据置零位做处理  注意这个时候做处理要先不动第一行和第一列，否则的话信息就丢了
        for(int i=m-1;i>=1;i--)
        {
            for(int j=n-1;j>=1;j--)
            {
                if(matrix[i][0]==0 || matrix[0][j]==0)
                    matrix[i][j]=0;
            }
        }
        
        // 最后处理第一行和第一列
        if(rowFlag)
        {
            for(int i=0;i<n;i++)
                matrix[0][i]=0;       // 第一行需要置零
        }
        if(colFlag)
        {
            for(int i=0;i<m;i++)
                matrix[i][0]=0;       // 第一列需要置零
        }
    }
};