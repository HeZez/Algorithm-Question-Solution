/*
    n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
    上图为 8 皇后问题的一种解法。

    给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。

    每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。

    示例:

    输入: 4
    输出: [
     [".Q..",  // 解法 1
      "...Q",
      "Q...",
      "..Q."],

     ["..Q.",  // 解法 2
      "Q...",
      "...Q",
      ".Q.."]
    ]
    解释: 4 皇后问题存在两个不同的解法。
*/
/*
    皇后问题应该要求不同的皇后不在同一行，同一列，也不能在对角线上
    这种题还是不太会，解法来自国外leetcode大佬
    解法1：直接检查每一个位置的有效性
    
*/
/*
// 解法一
class Solution {
private:
    void solveNQueensCore(vector<vector<string>> &res, vector<string> &nQueen, int row, int& n)
    {
        // 递归边界
        if(row==n)
        {
            res.push_back(nQueen);
            return ;
        }
        for(int col=0;col!=n;col++)
        {
            if(isValid(nQueen, row, col, n))
            {
                nQueen[row][col]='Q';
                solveNQueensCore(res, nQueen, row+1, n);
                nQueen[row][col]='.';
            }
        }
    }
    
    bool isValid(vector<string> &nQueen, int row, int col, int& n)
    {
        // 首先判断同一列上有没有多个皇后
        for(int i=0;i<row;i++)
        {
            if(nQueen[i][col]=='Q')
                return false;
        }
        // 检查右上斜对角线是否有Q
        for(int i=row-1, j=col+1; i>=0&&j<n ; i--,j++)
        {
            if(nQueen[i][j]=='Q')
                return false;
        }
        // 检查左上斜对角线是否有Q
        for(int i=row-1, j=col-1; i>=0&&j>=0 ; i--,j--)
        {
            if(nQueen[i][j]=='Q')
                return false;
        }
        return true;
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> nQueen(n, string(n, '.'));
        solveNQueensCore(res, nQueen, 0, n);
        return res;
    }
};
*/

//解法二：
/*
    大佬的第二种解法，耗时更低  认为需要判断的有三种情况  同一列  左对角线和右对角线
    同一列用n个值来表示是否有Q， 对角线用2*n-1个值来表示 来表示 从这个例子中可以看出来n=3时， 对角线一共有5条
    接下来，[i,j]这个位置（0,0表示原点），列是j，45度对角线的序号是i+j 135度对角线的序号是n-1+i-j（这都怎么想到的？）
    比如[1,1]这个位置， 列很简单 45度序号是1+1=2 135度序号是3-1+1-1=2
    之后思路和第一种解法类似，不过减小了搜索空间
    
/**    | | |                / / /             \ \ \
  *    O O O               O O O               O O O
  *    | | |              / / / /             \ \ \ \
  *    O O O               O O O               O O O
  *    | | |              / / / /             \ \ \ \ 
  *    O O O               O O O               O O O
  *    | | |              / / /                 \ \ \
  *   3 columns        5 45° diagonals     5 135° diagonals    (when n is 3)
  */

class Solution {
private:
    void solveNQueensCore(vector<vector<string>> &res, 
                          vector<int> &colFlag, vector<int> &flag_45, vector<int> &flag_135,
                          vector<string> &nQueen, int row, int& n)
    {
        // 递归边界
        if(row==n)
        {
            res.push_back(nQueen);
            return ;
        }
        for(int col=0;col!=n;col++)
        {
            if(colFlag[col]&&flag_45[row+col]&&flag_135[n-1+row-col])
            {
                nQueen[row][col]='Q';
                colFlag[col]=flag_45[row+col]=flag_135[n-1+row-col]=0;
                solveNQueensCore(res, colFlag, flag_45, flag_135, nQueen, row+1, n);
                nQueen[row][col]='.';
                colFlag[col]=flag_45[row+col]=flag_135[n-1+row-col]=1;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> nQueen(n, string(n, '.'));
        vector<int> colFlag(n, 1);
        vector<int> Flag45(2*n-1, 1);
        vector<int> Flag135(2*n-1, 1);
        solveNQueensCore(res, colFlag, Flag45, Flag135, nQueen, 0, n);
        return res;
    }
};