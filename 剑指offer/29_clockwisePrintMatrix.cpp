/*
    顺时针打印矩阵
    题目描述
        输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
        例如，如果输入如下4 X 4矩阵： 
    1 2 3 4
    5 6 7 8
    9 10 11 12
    13 14 15 16
        则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
*/
/*
    本身不难思考，可以通过画图的方式来得知整个流程是怎么样的，需要一点耐心并考虑一些边界情况
    1.首先是正常的四周一圈的情况，共上下左右四条边，按照顺时针顺序确定其下标变化情况
    2.其次是矩形只有两行多列或多行两列的情况，这时这个矩形在输出时退化为只有两条边就可以表达出来
    3.一行多列或多行一列的情况，这时只有一条边，注意这种情况的边界条件 以防重复打印
    4.只有一个元素rowStart rowEnd colStart colEnd这四个值相等
    
    循环终止条件是rowStart<=rowEnd colStart<=colEnd
*/

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        int rowStart=0;
        int colStart=0;
        int rowEnd=row-1;
        int colEnd=col-1;
        vector<int> result;
        if(row==0||col==0)
            return result;
        while(rowEnd>=rowStart&&colEnd>=colStart)
        {
            //printCore(result, matrix, rowStart, rowEnd, colStart, colEnd);
            //从左到右打印一行
            for(int i=colStart;i<=colEnd;i++)
                result.push_back(matrix[rowStart][i]);
            // 从上到下打印一行
            if(rowStart<rowEnd)
            {
                for(int i=rowStart+1;i<=rowEnd;i++)
                    result.push_back(matrix[i][colEnd]);
            }
            //从右到左打印一行
            if(colEnd>colStart&&rowEnd>rowStart)
            {
                for(int i=colEnd-1;i>=colStart;i--)
                    result.push_back(matrix[rowEnd][i]);
            }
            //从下到上打印一行
            if(rowEnd>rowStart+1&&colStart<colEnd)
            {
                for(int i=rowEnd-1;i>=rowStart+1;i--)
                    result.push_back(matrix[i][colStart]);
            }
            rowStart++;
            colStart++;
            rowEnd--;
            colEnd--;
        }
        return result;
    }
};