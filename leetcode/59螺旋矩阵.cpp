/*
    给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。

    示例:

    输入: 3
    输出:
    [
     [ 1, 2, 3 ],
     [ 8, 9, 4 ],
     [ 7, 6, 5 ]
    ]

*/
/*
    我写的解法和 54.螺旋矩阵 解法类似
*/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int> > res(n,vector<int>(n,0));
        int start=0;
        int num=1;
        while(start<2*n)
        {
            //con从左到右一行
            for(int i=start; i<n-start; i++)
                res[start][i]=num++;
            // 从上到下一列
            for(int i=start+1;i<n-start; i++)
                res[i][n-1-start]=num++;
            //从右到左一行
            for(int i=n-2-start;i>=start; i--)
                res[n-1-start][i]=num++;
            //从下到上一列
            for(int i=n-2-start;i>start; i--)
                res[i][start]=num++;
            start++;
        }
        
        return res;
    }
    

};