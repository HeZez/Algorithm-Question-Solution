/*
    老师想给孩子们分发糖果，有 N 个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分。

    你需要按照以下要求，帮助老师给这些孩子分发糖果：

    每个孩子至少分配到 1 个糖果。
    相邻的孩子中，评分高的孩子必须获得更多的糖果。
    那么这样下来，老师至少需要准备多少颗糖果呢？

    示例 1:
    输入: [1,0,2]
    输出: 5
    解释: 你可以分别给这三个孩子分发 2、1、2 颗糖果。
    
    示例 2:
    输入: [1,2,2]
    输出: 4
    解释: 你可以分别给这三个孩子分发 1、2、1 颗糖果。
        第三个孩子只得到 1 颗糖果，这已满足上述两个条件。
*/
/*
    这个问题，每个孩子分到的具体糖果数会和孩子所在的位置和相邻分数有关系，所以不能排序打乱其相对的结构
    可能是？dp  
    或者新进来一个位置，如果当前分数比上一个位置高，糖果数等于上一个位置糖果数+1
    如果当前分数比上一个位置低，则更新前面的位置直到一个峰顶
    
    这样做应该可以得到结果，但是由于每一个遍历的过程中可能会存在向回更新值得过程
    如果整个序列递减，从前向后遍历，整个算法会退化为O(N^2)
    测试样例中有一个2w的递减序列就会超时
    
    按照大佬的思想，上面我自己的想法其实可以在正反两次遍历中实现
    贪心算法，用两个数组记录左右两次遍历的结果，单向遍历的时候就是如果分数递增就+1
    每个位置选两个方向遍历结果中的较大值
*/
class Solution {
public:
    int candy(vector<int>& ratings) {
        /*
        // 自己的想法，应该有解，但是极端情况下会退化到O(N^2)，会超时
        if(ratings.empty())
            return 0;
        vector<int> num(ratings.size(), 1);
        for(int i=1;i<ratings.size();i++)
        {
            if(ratings[i]>ratings[i-1])
            {
                num[i]=num[i-1]+1;
            }
            else
            {
                num[i]=1;
                int j=i;
                while(j>=1)
                {
                    if(num[j]>=num[j-1]&&ratings[j-1]>ratings[j])
                        num[j-1]++;
                    else
                        break;
                    j--;
                }
            }
        }
        int res=0;
        for(int i=0;i<num.size();i++)
            res+=num[i];
        return res;
        */
        if(ratings.empty())
            return 0;
        vector<int> left(ratings.size(), 1), right(ratings.size(), 1);
        int result=0;
        for(int i=1;i<ratings.size();i++)
        {
            if(ratings[i]>ratings[i-1])
                left[i]=left[i-1]+1;
        }
        for(int i=ratings.size()-2;i>=0;i--)
        {
            if(ratings[i]>ratings[i+1])
                right[i]=right[i+1]+1;
            result+=max(left[i],right[i]);
        }
        result+=max(left[ratings.size()-1],right[ratings.size()-1]);
        return result;
    }
};