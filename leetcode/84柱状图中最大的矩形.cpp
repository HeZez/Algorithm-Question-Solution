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
    单调栈解法的具体含义：
    首先说单调栈是怎么个东西，顾名思义也就是栈中存储的数据从底到顶是升序或者降序的，而且每一个数据都会进入到栈中
    举个例子，一个升序的单调栈 当前情况为1 3 4 5 ，当前遍历到的数据为2
    这时单调栈会怎么呢？
    其会将3 4 5 从栈中弹出，以保证当2进入到栈里的时候整个栈依旧是升序的
    这个特性刚好可以被用来寻找包含当前bar的矩形的左右边界
    
    当前bar的矩形的左右边界的特点是什么呢？ 是从当前bar向左右延伸，第一个小于当前bar高度的bar的位置就是边界
    单调栈可以很好地满足这个想法，栈中数据，栈顶的下面的数据就是左侧比栈顶低的第一个位置，
    而当新数据进来的时候，如果新数据bar的高度比栈顶bar高度要大，那么直接入栈，
    如果更小，也就是说这是包含栈顶bar最大矩形的右侧的边界，由此可以计算包含栈顶bar的最大矩形面积
    
    
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
        /*
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
        */
        stack<int> s;  //栈中存储的是bar的下标
        heights.push_back(0);  // 在后面插入一个0以便结束
        s.push(0);
        for(int i=1;i<heights.size();i++)
        {
            
                while(!s.empty()&&heights[s.top()]>heights[i])
                {
                    int top=s.top();
                    s.pop();
                    res=max(res, heights[top]* (s.empty()?i:i-s.top()-1) );
                }
            
                s.push(i);
        }
        return res;
    }
};