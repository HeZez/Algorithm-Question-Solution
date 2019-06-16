/*
    给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。

    找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。

    示例:

    X X X X
    X O O X
    X X O X
    X O X X
    运行你的函数后，矩阵变为：

    X X X X
    X X X X
    X X X X
    X O X X
    
    解释:
    被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。
*/
/*
    自己的想法，建一个矩阵来存每个位置的O是否应该被填充 关键是怎么找
    
    评论区中的观点 解法类似海岛问题，先从边界上的O开始深度优先遍历，将与边界上O相连的O都改成某一其他符号
    之后遍历整个矩阵 修改结果
*/
class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j,int row, int col)
    {
        // 递归边界
        if(i<0||j<0||i>=row||j>=col||board[i][j]!='O')
            return ;
        board[i][j]='*';
        dfs(board, i-1, j, row, col);
        dfs(board, i+1, j, row, col);
        dfs(board, i, j-1, row, col);
        dfs(board, i, j+1, row, col);  
        return ;
    }
    void solve(vector<vector<char>>& board) {
        if(board.empty())
            return ;
        int row=board.size();
        int col=board[0].size();
        if(row<=2||col<=2)
            return ;
        //修改矩阵
        for(int i=0;i<row;i++)
        {
            dfs(board, i, 0, row, col);
            dfs(board, i, col-1, row, col);
        }
        for(int j=0;j<col;j++)
        {
            dfs(board, 0, j, row, col);
            dfs(board, row-1, j, row, col);
        }
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(board[i][j]=='O')
                    board[i][j]='X';
                if(board[i][j]=='*')
                    board[i][j]='O';
            }
        }
        return ;
    }
};