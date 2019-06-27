/*
    给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

求在该柱状图中，能够勾勒出来的矩形的最大面积。

 



以上是柱状图的示例，其中每个柱子的宽度为 1，给定的高度为 [2,1,5,6,2,3]。

 



图中阴影部分为所能勾勒出的最大矩形面积，其面积为 10 个单位。

 

示例:

输入: [2,1,5,6,2,3]
输出: 10
*/
/*
    印象里在哪里做过这道题，但是记不清楚了，重新思考了一下
    柱状图中能够形成，其矩形的大小高取决于当前最低的高度，长度取决于周围比最低柱高的柱的个数
    
    那就遍历每一个柱作为最低的柱，以此构建矩形，保留最大的矩形面积结果
    用循环的方式来寻找左右边界，比较直观，不过这种方式在一些极端情况下退化严重，会超时
    
    在找左右边界的时候应该使用单调栈
    
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.empty())
            return 0;
        int height=0;
        int count=1;  //记录矩形长度
        int res=0;
        /*
        // 遍历的方法，极端情况会超时
        for(int i=0;i<heights.size();i++)
        {
            height=heights[i];
            count=1;
            // 用循环的方式来寻找左右边界，比较直观，不过这种方式在一些极端情况下退化严重，会超时
            for(int l=i-1; l>=0; l--)
            {
                if(heights[l]>=heights[i])
                    count++;
                else
                    break;
            }
            for(int r=i+1; r<heights.size(); r++)
            {
                if(heights[r]>=heights[i])
                    count++;
                else
                    break;
            }
            int temp=height*count;
            if(temp>res)
                res=temp;
        }
        */
        // 基于单调栈的方法
        stack<int> s;
        // 向heights后面添加一个0
        heights.push_back(0);
        s.push(0);
        for(int i=0;i<heights.size();i++)
        {
            //  这个单调栈的意思就是，里面存的单调递增的数据
            //  在出栈的时候计算面积，也就是说，heights[s.top()]>heights[i]的时候，
            //  i是右侧第一个比top位置低的高度，单调栈，top的前一个元素就是左边界
            while(!s.empty()&&heights[s.top()]>heights[i])
            {
                int top=s.top();
                s.pop();
                res=max(res, heights[top] * (s.empty()? i : i-s.top()-1 ));
            }
            s.push(i);
        }
        return res;
    }
};