/*
    给定一个二维网格和一个单词，找出该单词是否存在于网格中。

    单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

    示例:

    board =
    [
      ['A','B','C','E'],
      ['S','F','C','S'],
      ['A','D','E','E']
    ]

    给定 word = "ABCCED", 返回 true.
    给定 word = "SEE", 返回 true.
    给定 word = "ABCB", 返回 false.

*/
/*
    我的想法是dfs+额外矩阵记录当前字母是否使用过  这个方法用了468ms只比32%快 内存用了154m 比40%小  这个方法需要优化
    
    首先是辅助额外矩阵其实可以不使用，在原矩阵上修改可以达到同样的效果。
    同时我发现最最主要的减少时间和空间消耗的步骤是在传递单词这一参数的时候，要使用引用
*/

/*
// 第一版解法
class Solution {
public:
    bool existCore(vector<vector<char>>& board, vector<vector<int >>& flag, string word, 
                   int index, int i, int j)
    {
        // 递归边界
        if(index>=word.size())
            return true;
        if(i<0||i>=board.size()||j<0||j>=board[0].size()||flag[i][j]==0||board[i][j]!=word[index])
            return false;
        flag[i][j]=0;
        bool result=existCore(board, flag, word, index+1, i+1, j)||
            existCore(board, flag, word, index+1, i-1, j)||
            existCore(board, flag, word, index+1, i, j+1)||
            existCore(board, flag, word, index+1, i, j-1);
        flag[i][j]=1;
        return result;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty()||board[0].empty())
            return false;
        int rowLen=board.size();
        int colLen=board[0].size();
        vector<vector<int >> flag(rowLen, vector<int >(colLen, 1));
        bool result=false;
        for(int i=0;i<rowLen;i++)
        {
            for(int j=0;j<colLen;j++)
            {
                if(board[i][j]==word[0])
                    result=existCore(board, flag, word, 0, i, j);
                //成功一个就返回结果
                if(result)
                    return result;
            }
        }
        return false;
    }
};
*/


// 第二版解法
class Solution {
public:
    bool existCore(vector<vector<char>>& board, string& word, 
                   int index, int i, int j, int wordLen, int maxRow, int maxCol)
    {
        // 递归边界
        if(index>=word.size())
            return true;
        if(i<0||i>=maxRow||j<0||j>=maxCol)
            return false;
        if(board[i][j]=='*')
            return false;
        if(board[i][j]!=word[index])
            return false;
        if(index>=wordLen)
            return false;
        char t=board[i][j];
        board[i][j]='*';
        /*
        bool result=existCore(board, word, index+1, i+1, j, wordLen, maxRow, maxCol)||
            existCore(board,  word, index+1, i-1, j, wordLen, maxRow, maxCol)||
            existCore(board,  word, index+1, i, j+1, wordLen, maxRow, maxCol)||
            existCore(board,  word, index+1, i, j-1, wordLen, maxRow, maxCol);
        */
        // 这里优化成了只要有一个是true就不走其他分支
        if(existCore(board, word, index+1, i+1, j, wordLen, maxRow, maxCol))
            return true;
        if(existCore(board, word, index+1, i-1, j, wordLen, maxRow, maxCol))
            return true;
        if(existCore(board, word, index+1, i, j+1, wordLen, maxRow, maxCol))
            return true;
        if(existCore(board, word, index+1, i, j-1, wordLen, maxRow, maxCol))
            return true;
        board[i][j]=t;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty()||board[0].empty())
            return false;
        int rowLen=board.size();
        int colLen=board[0].size();
        bool result=false;
        for(int i=0;i<rowLen;i++)
        {
            for(int j=0;j<colLen;j++)
            {
                
                if(board[i][j]==word[0])
                    result=existCore(board, word, 0, i, j, word.size(), rowLen, colLen);
                if(result)
                    return true;
                    
            }
        }
        return false;
    }
};