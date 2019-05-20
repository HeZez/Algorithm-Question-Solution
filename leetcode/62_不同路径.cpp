class Solution {
    
/*
    题目描述：一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。

    机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

    问总共有多少条不同的路径？
    例如，上图是一个7 x 3 的网格。有多少可能的路径？

    说明：m 和 n 的值均不超过 100。

    示例 1:

    输入: m = 3, n = 2
    输出: 3
    解释:
    从左上角开始，总共有 3 条路径可以到达右下角。
    1. 向右 -> 向右 -> 向下
    2. 向右 -> 向下 -> 向右
    3. 向下 -> 向右 -> 向右
    示例 2:

    输入: m = 7, n = 3
    输出: 28
*/
    
/*
    动态规划，使用一个二维数组m[i][j]来存储终点为(i,j)时的路径个数
    递推方程，mij=m[i-1][j]+m[i][j-1]
        边界  矩阵第一行和第一列除00处值为1 00处值为零  可以理解为当网格只有一行或者一列时  按照规定动作只有一条路径
        递推方程可以这样理解，终点可以从其上面的格子向下走到达，也可以从其左边向右走到达 ，那么终点的路径数就是这两个节        点的路径数加和
*/
public:
    int uniquePaths(int m, int n) {
        int result=0;

        //处理不正常数据
        if(m==1&&n==1)
            return 1;
        if(m<=0||n<=0)
            return 0;
        //用new创建一个二维数组,有两种方法,是等价的  或者使用vector
        //一:
        //int (*p)[inN] = new int[inM][inN];
        //二:
        
        int **p = new int* [m];
        for(int i=0;i<m;i++)
            p[i] = new int[n];
        
        //三
        //注意下面这一行：vector <int后两个 "> "之间要有空格！否则会被认为是重载 "> > "。 
        //vector<vector<int> > p(m,vector<int>(n));
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(i==0||j==0)
                {
                    if(i==0&&j==0)
                        p[i][j]=0;
                    else
                        p[i][j]=1;
                }
                else
                    p[i][j]=p[i-1][j]+p[i][j-1];
            }
        result=p[m-1][n-1];
        
        for(int i=0;i<m;i++)
        {
            delete[] p[i];
        }
        delete[] p;
        
        return result;
    }
};