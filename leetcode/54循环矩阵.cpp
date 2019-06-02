/*
    给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。
    示例 1:
    输入:
    [
     [ 1, 2, 3 ],
     [ 4, 5, 6 ],
     [ 7, 8, 9 ]
    ]
    输出: [1,2,3,6,9,8,7,4,5]
    示例 2:

    输入:
    [
      [1, 2, 3, 4],
      [5, 6, 7, 8],
      [9,10,11,12]
    ]
    输出: [1,2,3,4,8,12,11,10,9,5,6,7]
*/

/*
    剑指offer上有这道题
*/


class Solution {
private:
    vector<int> result;
    
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        //if()
        if(matrix.empty())
            return result;
        int m=matrix.size();
        int n=matrix[0].size();
        if(m<=0||n<=0)
            return result;
        int start=0;
        while(m>start*2&&n>start*2)
        {
            spiralOrderCore(matrix, start);
            start++;
        }
        
        return result;
    }
    void spiralOrderCore(vector<vector<int>>& matrix, int start)
    {
        int endX=matrix[0].size()-start-1;
        int endY=matrix.size()-start-1;
        // 从左到右打印一行
        for(int i=start;i<=endX;i++)
            result.push_back(matrix[start][i]);
        //从上到下打印一行，右侧的竖行
        if(start<endY)
        {
            for(int i=start+1;i<=endY;i++)
                result.push_back(matrix[i][endX]);
        }
        //从右到左打印一行
        if(start<endX&&start<endY)
        {
            for(int i=endX-1;i>=start;i--)
                result.push_back(matrix[endY][i]);
        }
        //从右到左打印一行
        if(start<endX&&start+1<endY)
        {
            for(int i=endY-1;i>start;i--)
                result.push_back(matrix[i][start]);
        }
    }
};