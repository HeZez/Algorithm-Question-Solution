/*
    给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。

    例如，给定三角形：

    [
         [2],
        [3,4],
       [6,5,7],
      [4,1,8,3]
    ]
    自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。

    说明：

    如果你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题，那么你的算法会很加分。
*/
/*
    其实可以直接改老三角上的数字，在最后一行把到达每个数字的最短路径求出来，再在其中找一个最小的
    不使用额外空间，但是改变了原始三角形的数值
    
    这题用动态规划似乎解不了，但是....也可能我没想到
    或者层层记录结果，记录所有最后一层数字的最小路径和，之后再从中找最小的那个
    因为三角形总行数和最后一行数字的个数相同，所以应该符合额外空间O(n)的要求
    这种做法也能看做是动态规划吗？
    怎样在使用N个额外空间的时候消除前面数据被覆盖对后面造成的干扰？
    如果正向的遍历在每一层中正向遍历， 由于dp[j]和dp[j-1]和dp[j]有关，如果dp[j-1]被覆盖结果自然不正确
    可以倒着遍历解决这一问题
*/

class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.empty()||triangle[0].empty())
            return 0;
        int n=triangle.size();
        vector<int> pathSum(n, 0);
        pathSum[0]=triangle[0][0];
        for(int i=1;i<triangle.size();i++)
        {
            // 单独处理首尾
            pathSum[i]=triangle[i][i]+pathSum[i-1];
            // 倒着遍历
            for(int j=i-1;j>0;j--)
            {
                pathSum[j]=triangle[i][j]+min(pathSum[j-1], pathSum[j]);
            }
            pathSum[0]=triangle[i][0]+pathSum[0];
        }
        // 找最小
        int res=INT_MAX;
        for(int i=0;i<pathSum.size();i++)
        {
            if(pathSum[i]<res)
                res=pathSum[i];
        }
        return res;
    }
    
};