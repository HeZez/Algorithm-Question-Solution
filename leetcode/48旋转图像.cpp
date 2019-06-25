/*
    给定一个 n × n 的二维矩阵表示一个图像。

    将图像顺时针旋转 90 度。

    说明：

    你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。

    示例 1:
    给定 matrix = 
    [
      [1,2,3],
      [4,5,6],
      [7,8,9]
    ],
    原地旋转输入矩阵，使其变为:
    [
      [7,4,1],
      [8,5,2],
      [9,6,3]
    ]
    
    示例 2:
    给定 matrix =
    [
      [ 5, 1, 9,11],
      [ 2, 4, 8,10],
      [13, 3, 6, 7],
      [15,14,12,16]
    ], 
    原地旋转输入矩阵，使其变为:
    [
      [15,13, 2, 5],
      [14, 3, 4, 1],
      [12, 6, 8, 9],
      [16, 7,10,11]
    ]
*/
/*
    自己实在是太笨了，还是看了评论区
    两种思路，最直白的一种，先转置矩阵，之后镜像对称一下
    第二种，逐圈交换，四个角的元素单独处理，剩下的按照规律交换
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // 第一种方法，转置后镜像对称
        if(matrix.size()<=0||matrix[0].size()<=0)
            return ;
        // 转置
        int temp=0;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=i+1;j<matrix[0].size();j++)
            {
                temp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
        }
        //镜像对称
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size()/2;j++)
            {
                temp=matrix[i][j];
                matrix[i][j]=matrix[i][matrix[0].size()-1-j];
                matrix[i][matrix[0].size()-1-j]=temp;
            }
        }
    
    }
};