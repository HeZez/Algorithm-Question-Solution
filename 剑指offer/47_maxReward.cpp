/*
题目描述
在一个 m*n 的棋盘的每一个格都放有一个礼物，
每个礼物都有一定价值（大于 0）。从左上角开始拿礼物，
每次向右或向下移动一格，直到右下角结束。给定一个棋盘，
求拿到礼物的最大价值。例如，对于如下棋盘
*/
/*
    动态规划即可，可以用用原矩阵存储结果，
    m[i][j]存的是当前位置可以拿到的最大奖励
    规定只能向右和向下运动，特殊的情况是边界上
    第一行更新值得时候只选择同行的，因为不存在第0行，没办法从上面到达这个位置
    第一列时同理
*/

class Bonus {
public:
    int getMost(vector<vector<int> > board) {
        // write code here
        if(board.size()==0)
            return 0;
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(i==0&&j==0)
                {
                    continue;
                }
                if(i==0)
                {
                    board[i][j]+=board[i][j-1];
                    continue;
                }
                if(j==0)
                {
                    board[i][j]+=board[i-1][j];
                    continue;
                }
                board[i][j]+=max(board[i-1][j], board[i][j-1]);
            }
        return board[5][5];
    }
};