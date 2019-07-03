/*
    n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。

    上图为 8 皇后问题的一种解法。

    给定一个整数 n，返回 n 皇后不同的解决方案的数量。

    示例:

    输入: 4
    输出: 2
    解释: 4 皇后问题存在如下两个不同的解法。
    [
     [".Q..",  // 解法 1
      "...Q",
      "Q...",
      "..Q."],

     ["..Q.",  // 解法 2
      "Q...",
      "...Q",
      ".Q.."]
    ]
*/
/*
    用n皇后1的解法把所有解找出来，之后看看有多少个......
    解法是用三个数组，分别记录同一列，45度对角线，135度对角线上存不存在q
    位置(i,j)的45度对角线序号i+j  135度对角线序号n-1+i-j
 */

class Solution {
public:
    vector<vector<string>> res;
    
    void totalNQueensCore(int& n, int row, vector<int>& col, vector<int>& col_45, 
                          vector<int>& col_135, vector<string>& nQueen)
    {
        // 递归边界
        if(row==n)
        {
            res.push_back(nQueen);
            return ;
        }
        for(int i=0;i<nQueen[row].size();i++)
        {
            if(col[i]&&col_45[row+i] && col_135[n-1+row-i])
            {
                col[i]=0;
                col_45[row+i]=0; 
                col_135[n-1+row-i]=0;
                nQueen[row][i]='Q';
                totalNQueensCore(n, row+1, col,  col_45, col_135, nQueen);
                col[i]=1;
                col_45[row+i]=1; 
                col_135[n-1+row-i]=1;
                nQueen[row][i]='.';
            }
        }
    }
    
    int totalNQueens(int n) {
        vector<int> col(n, 1);
        vector<int> col_45(2*n-1, 1);
        vector<int> col_135(2*n-1, 1);
        vector<string> nQueen(n, string(n, '.'));
        totalNQueensCore(n, 0, col, col_45, col_135, nQueen);
        
        return res.size();
    }
};