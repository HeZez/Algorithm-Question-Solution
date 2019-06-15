/*
    给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
    设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。
    注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

    示例 1:
    输入: [7,1,5,3,6,4]
    输出: 7
    解释: 在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
         随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6-3 = 3 。
    示例 2:
    输入: [1,2,3,4,5]
    输出: 4
    解释: 在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
         注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。
         因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
         
    示例 3:
    输入: [7,6,4,3,1]
    输出: 0
    解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
*/
/*
     制定一个策略，贪心，当在价格低谷的时候买入，上升峰顶的时候卖出
     
     评论区大佬的方法是。这个问题可以拆开看，因为可以当天卖当天买
     所以只要当天的价格大于等于昨天的价格就可以卖出，进而逐天计算 实现起来更简单
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result=0;
        int len=prices.size();
        if(len<=1)
            return result;
        int lowPos=0;
        for(int i=1;i<len;i++)
        {
            if(i==len-1)  //最后的边界
            {
                if(prices[i]<=prices[i-1]) // 低谷
                    lowPos=i;
                if(prices[i]>=prices[i-1])
                    result+=(prices[i]-prices[lowPos]);
                break;
            }
            else
            {
                if(prices[i]<=prices[i-1]&&prices[i]<=prices[i+1]) // 低谷
                    lowPos=i;
                if(prices[i]>=prices[i-1]&&prices[i]>=prices[i+1])  // 峰顶
                {
                    //可能出现连续的多个封顶值相同的时候 判断一下
                    if(prices[i]==prices[i-1])
                        continue;
                    else
                        result+=(prices[i]-prices[lowPos]);
                }
            }
        }
        return result;
    }
};