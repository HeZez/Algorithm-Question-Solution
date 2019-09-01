/*
    在二维平面上计算出两个由直线构成的矩形重叠后形成的总面积。

    每个矩形由其左下顶点和右上顶点坐标表示，如图所示。

    示例:

    输入: -3, 0, 3, 4, 0, -1, 9, 2
    输出: 45
    说明: 假设矩形面积不会超出 int 的范围。
*/
/*
    个人思路 首先要考虑两个矩形是否相交
    如果相交的话，两个矩形的顶点坐标，共有四个x坐标，四个y坐标
    分别对这四个坐标进行排序 中间的那两个坐标就是确定相交矩形的坐标
    
    判断是否相交的话，可以用坐标是否相交来确定 如果四个点分别为(x1 y1) (x2 y2) (x3 y3) (x4 y4)
    即(x3<x1<x4 or x3<x2<x4) and (y3<y1<y4 or y3<y2<y4) 这样的判断要考虑相互的关系
    
    更正常的是这样判断 分别判断上下 左右边沿的大小关系 是否符合要求
*/
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        // 先判断是否相交
        // 因为相关的位置判断 两个矩形1 2是确定位置的
        int result=0;
        int intersect=0;
        //vector<int> xList(4, 0);
        //vector<int> yList(4, 0);
        //xList[0]=A;xList[1]=C;xList[2]=E;xList[3]=G;
        //yList[0]=B;yList[1]=D;yList[2]=F;yList[3]=H;
        if( !(A>=G || C<=E || H<=B || D<=F) )
        {
            // 相交
            //sort(xList.begin(), xList.end());
            //sort(yList.begin(), yList.end());
            intersect=(min(C,G)-max(A, E))*(min(D,H)-max(B, F));
            result=(C-A)*(D-B);
            result=result-intersect;
            result=result+(G-E)*(H-F);
            return result;
        }
        // 不相交 返回两个矩形面积加和
        return (C-A)*(D-B)+(G-E)*(H-F);
    }
};