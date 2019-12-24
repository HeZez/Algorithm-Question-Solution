/*
    给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。

    示例 1:
    输入: coins = [1, 2, 5], amount = 11
    输出: 3 
    解释: 11 = 5 + 5 + 1

    示例 2:
    输入: coins = [2], amount = 3
    输出: -1
    说明:
    你可以认为每种硬币的数量是无限的。
*/
/*
    标准贪心 需要考虑一下没有可行解的情况
    想的有问题 不是标准贪心，可能是dp
    因为并不是所有的样例中的硬币都很规则 比如
    [186,419,83,408]
    6249
    这样的样例 如果按照贪心来拿的话 很有可能没有解  但其实是可以凑出最终结果的 很惭愧 这一点也是看到了报错的样例
    之后才想到的

    或者是搜索 递归搜索所有的可能组合  之后找到最小的那个  这样的话 理论上可行 但是上面的那个样例的解是20
    这样搜索起来太耗时了 会超时

    知识都还给老师了... 这道题可以看成完全背包问题  dp dfs bfs都可以解决
    
    动态规划的解法 可以是一个一维的dp表 dp[i]=n 表示金钱数为i的时候的最小硬币数为n个
    于是 dp[i]=min(dp[i],dp[i-coins[j]]+1)  j = [0, coins.size()-1]
*/
class Solution {
public:
    int result=INT_MAX;
    int coinChange(vector<int>& coins, int amount) {
        /*
        // 错误的想法
        if(coins.empty())
            return -1;
        sort(coins.begin(), coins.end());
        int flag=coins.size()-1;
        int temp=amount;
        int result=0;
        while(temp>0)
        {
            if(flag<0)
                return -1;
            if(coins[flag]<=temp)
            {
                temp-=coins[flag];
                result++;
            }
            else
            {
                while(flag>=0&&coins[flag]>temp)
                {
                    flag--;
                }
            }
        }
        return result;
        */

        /*
        // dfs解法先降序排序
        sort(coins.begin(), coins.end());
        reverse(coins.begin(), coins.end());
        coinChangeCore(coins, amount, 0, 0);
        return (result==INT_MAX)?-1:result;
        */

        // dp自底向上解法
        return dpSolution(coins, amount);
    }
    void coinChangeCore(vector<int>& coins, int amount, int temp, int pos)
    {
        // dfs 想想怎么剪枝
        // 参数解释 coins列表 amount 剩余要匹配的金额 当前硬币数
        // 递归边界
        if(amount<0)
            return ;
        if(amount==0)
        {
            result=(temp<result)?temp:result;
            return ;
        }
        for(int i=pos;i<coins.size();i++)
        {
            // 剪枝
            //因为是降序排序的 如果在不超过当前最小硬币数的时候使用当前硬币无法凑够剩余零钱 后面的也不可能 直接剪枝
            if( result!=INT_MAX && (result-temp)*coins[i]<amount )
                break;   
            // 剪枝 当前硬币不符合要求
            if( coins[i]>amount )
                continue;
            coinChangeCore(coins, amount-coins[i], temp+1, i);
        }
    }

    int dpSolution(vector<int>& coins, int amount)
    {
        /*
        // 自底向上  感觉比较傻大黑粗 时间和空间复杂度不会太优秀
        vector<int> dp(amount+1, INT_MAX);
        dp[0]=0;
        for(int i=1;i<=amount;i++)
        {
            for(int j=0;j<coins.size();j++)
            {
                if(i-coins[j]>=0&&dp[i-coins[j]]!=INT_MAX)
                    dp[i]=min(dp[i], dp[i-coins[j]]+1 );
                else
                    continue;
            }
        }
        return dp[amount]==INT_MAX?-1:dp[amount];
        */
    }
};