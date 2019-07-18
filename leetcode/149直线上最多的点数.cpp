/*
    给定一个二维平面，平面上有 n 个点，求最多有多少个点在同一条直线上。

    示例 1:
    输入: [[1,1],[2,2],[3,3]]
    输出: 3
    解释:
    ^
    |
    |        o
    |     o
    |  o  
    +------------->
    0  1  2  3  4
    
    示例 2:
    输入: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
    输出: 4
    解释:
    ^
    |
    |  o
    |     o        o
    |        o
    |  o        o
    +------------------->
    0  1  2  3  4  5  6
*/
/*
    使用什么样的方式判断直线在同一条直线上？
    任意两点都可以构成一条直线
    斜率相同可能是平行线
    一个点在一条直线上代表着它满足这条直线的解析式
    这种点的问题，分治应该可解
    
    去国外leetcode看了一下，有一个方法也是顺次遍历每个点和其他节点的可能直线
    每次用一个map来记录当前点到其他点的直线斜率
    ，之后找最大的结果，但是 由于浮点数精度的问题，用double做key能做到百分百准确吗？
    如果直接用double做key 对于样例[[0,0],[94911151,94911150],[94911152,94911151]]
    精度可能不足以表达最准确的斜率，结果是2 输出是3
    
    为了解决精度问题，有人在评论区提出了可以用string代替double来作为key
*/
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int res=0;
        for(int i=0;i<points.size();i++)
        {
            unordered_map<string, int> map;
            int samePoint=0;
            int maxSlope=0;
            int locMax=0;
            for(int j=i+1;j<points.size();j++)
            {
                // 可能有相同的点
                if(points[i][0]==points[j][0]&&points[i][1]==points[j][1])
                    samePoint++;
                else if(points[i][0]==points[j][0])
                    maxSlope++;
                else
                {
                    int xDiff=points[j][0]-points[i][0];
                    int yDiff=points[j][1]-points[i][1];
                    // 求两个差值的最大公约数  __gcd这个函数是c++自带的求最大公约数函数
                    int g=std::__gcd(xDiff,yDiff);
                    xDiff=xDiff/g;
                    yDiff=yDiff/g;
                    // 固定符号
                    if(yDiff<0)
                    {
                        yDiff=-yDiff;
                        xDiff=-xDiff;
                    }
                    // c++字符流的使用 学到了
                    stringstream strSlope;
                    strSlope<<xDiff<<","<<yDiff;
                    map[strSlope.str()]++;
                    locMax=max(locMax, map[strSlope.str()]);
                }
                locMax=max(locMax, maxSlope);
            }
            
            res=max(res, locMax+samePoint+1);
        }
        return res;
    }
};