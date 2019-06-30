/*
    给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

    上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢 Marcos 贡献此图。

    示例:

    输入: [0,1,0,2,1,0,1,3,2,1,2,1]
    输出: 6

*/
/*
    从示意图中，我的最直接理解是，找两个peek，中间接的水是较低的peek乘以宽度，减去这个面积中有柱子的部分
    我觉得这种想法可能会在极端情况下退化到N^2,先试一试
    还要注意边界的处理，在最两端的时候需要单独处理: 这种方法考虑的不够全面，有错误
    
    国外leetode大佬的解答：
    从两端向中间找：我认为这种方法的思想是这样的，从两端开始找，记录两端出现过的最高高度，
    两端中间夹的高度有三种情况，一是中间存在比两端都高的柱子，二中间柱子比两端都低，三呈阶梯状比一个高比一个低
    这三种情况，都可以找两端中较低的那一个，按照累加的方式来计算积水量
    例如：
    第一种情况，2005003，先从2这一端开始，直到遇到5，左侧最高高度变成5，于是开始算右侧，直到两端指针相遇
    
    第二种情况：2001003，从较低的2这一端开始，直到右侧
    
    第三种情况：2003004，与上面类似，
    
    从这几种情况中可以看出来，优先考虑最高高度较低的那一侧。
*/
class Solution {
public:
    /*
    int trap(vector<int>& height) {
        
        // 这种写法考虑到的情况不够全面
        if(height.size()<=2)
            return 0;
        int peak1=0;
        int peak2=0;
        int res=0;
        int temp=0;
        // 先把最开始的peak1找出来,最开始的时候只要出现递减就是peak
        while(temp<height.size()-1)
        {
            if(height[temp]>height[temp+1])
            {
                peak1=temp++;
                break;
            }
            temp++;
        }
        for(int i=temp;i<height.size()-1; )
        {
            // 找peak2 中间的peak要求比两侧都高
            while(i<height.size()-1)
            {
                if(height[i]>height[i-1]&&height[i]>height[i+1])
                {
                    peak2=i++;
                    break;
                }
                i++;
            }
            // 考虑 peak2<=peak1的情况,一般出现在最后
            if(peak2>peak1)
            {
                res+=(peak2-peak1-1) * min(height[peak1], height[peak2]);
                for(int j=peak1+1;j<=peak2-1;j++)
                    res-=height[j];
                peak1=peak2;
            }
        }
        
        // 处理最后一个边界 看看最后一个数是不是增长的
        if(height[height.size()-1]>height[height.size()-2])
        {
            peak2=height.size()-1;
            res+=(peak2-peak1-1) * min(height[peak1], height[peak2]);
            for(int j=peak1+1;j<=peak2-1;j++)
                res-=height[j];
        } 
        return res;
    }
    */
    int trap(vector<int>& height) {
        if(height.size()<=2)
            return 0;
        int i=0,j=height.size()-1;
        int maxleft=0,maxright=0;
        int res=0;
        while(i<=j)
        {
            if(height[i]<=height[j])
            {
                if(height[i]>maxleft)
                    maxleft=height[i];
                else
                    res+=maxleft-height[i];
                i++;
            }
            else
            {
                if(height[j]>maxright)
                    maxright=height[j];
                else
                    res+=maxright-height[j];
                j--;
            }
        }
        return res;
    }
};