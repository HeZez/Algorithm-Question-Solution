/*
    给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
    在杨辉三角中，每个数是它左上方和右上方的数的和。

    示例:

    输入: 5
    输出:
    [
         [1],
        [1,1],
       [1,2,1],
      [1,3,3,1],
     [1,4,6,4,1]
    ]

*/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for(int i=1;i<=numRows;i++)
        {
            vector<int> temp;
            for(int j=1;j<=i;j++)
            {
                if(j==1||j==i)
                    temp.push_back(1);
                else
                {
                    temp.push_back(result[i-2][j-2]+result[i-2][j-1]);
                }
            }
            result.push_back(temp);
        }
        return result;
    }
};