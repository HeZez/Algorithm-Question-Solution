/*
    题目描述
    一些恶魔抓住了公主（P）并将她关在了地下城的右下角。地下城是由 M x N 个房间组成的二维网格。我们英勇的骑士（K）最初被     安置在左上角的房间里，他必须穿过地下城并通过对抗恶魔来拯救公主。

    骑士的初始健康点数为一个正整数。如果他的健康点数在某一时刻降至 0 或以下，他会立即死亡。

    有些房间由恶魔守卫，因此骑士在进入这些房间时会失去健康点数（若房间里的值为负整数，则表示骑士将损失健康点数）；其他房     间要么是空的（房间里的值为 0），要么包含增加骑士健康点数的魔法球（若房间里的值为正整数，则表示骑士将增加健康点数）。

    为了尽快到达公主，骑士决定每次只向右或向下移动一步。

    编写一个函数来计算确保骑士能够拯救到公主所需的最低初始健康点数。

    例如，考虑到如下布局的地下城，如果骑士遵循最佳路径 右 -> 右 -> 下 -> 下，则骑士的初始健康点数至少为 7。

    -2 (K)	-3	3
    -5	-10	1
    10	30	-5 (P)
    说明:

    骑士的健康点数没有上限。

    任何房间都可能对骑士的健康点数造成威胁，也可能增加骑士的健康点数，包括骑士进入的左上角房间以及公主被监禁的右下角房间。
*/

/*
    动态规划  dp[m][n]表示骑士到达m,n处所需的最低的初始健康点数
    要求骑士在整个过程中的生命值必须大于0
    我认为要解决这个问题，dp[m][n]不能光存储最低初始健康点，因为存在加血的可能，所以需要记录骑士在当前最低初始血量的基础上当前位置的血量
    关键是怎么处理这个正值 还是存当前血量，假如从0血量开始，如果这个格子为正，这个格子的值最低血量等于上一个格
    这个格子血量为负 进一步判断
    这样需要一个三维数组
    这种思路还是考虑的不够全面   [[1,-3,3],[0,-2,0],[-3,-3,-3]] 这种情况无法通过
    
    
    或者转变思路  提示中说骑士走的是最佳路线，什么是最佳路线，应该是整条路径上负数总和最大的那一条
    （不一定是负值最小的，比如-1 20 -5 -5和-1，-1，-1，-1 后者负值总和更大，但是前者只需要初始2血量即可，后者需要5）
    这种思路是错误的
    所以不看正值，只看负值，先找到一条最佳路径，把路径存储下来，之后再构造解
    
    大佬的做法是倒着进行dp，从公主房间开始倒退
    dp[m][n]=max(1, min(dp[m+1][n], dp[m][n+1])-dungeon[m][n])
    */



class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m=dungeon.size();
        int n=dungeon[0].size();
        if(m<=0||n<=0)
            return 0;
        int **dp=new int* [m+1];
        for(int i=0;i<m+1;i++)
            dp[i]=new int[n+1];
        // 初始化边界值为maxint  防止越界
        for(int i=0;i<m+1;i++)
            dp[i][n]=INT_MAX;
        for(int j=0;j<n+1;j++)
            dp[m][j]=INT_MAX;
        
        //dp开始
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(i==m-1&&j==n-1)
                {
                    dp[i][j]=dungeon[i][j]>0?1:1-dungeon[i][j];
                    continue;
                }
                dp[i][j]=max(1, min(dp[i+1][j], dp[i][j+1])-dungeon[i][j]);
            }
        }
        return dp[0][0];
    }
    
    
    /*
	// 我最开始的思路 很繁琐 而且有覆盖不到的情况
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m=dungeon.size();
        int n=dungeon[0].size();
        if(m<=0||n<=0)
            return 0;
        int temp1=0;
        int temp2=0;
        //创建三维数组
        int ***dp=new int**[m];
        for(int i=0;i<m;i++)
        {
            dp[i]=new int*[n];
            for(int j=0;j<n;j++)
                dp[i][j]=new int[2];       //第一个位置存最低初始值， 第二个位置存当前血量
        }
            
        // 初始化值
        if(dungeon[0][0]>0)
        {
            dp[0][0][0]=1;
            dp[0][0][1]=dungeon[0][0];
        }
        else
        {
            dp[0][0][0]=-dungeon[0][0]+1;
            dp[0][0][1]=dungeon[0][0];
        }
        for(int i=1;i<m;i++)
        {
            if(dungeon[i][0]>=0)
            {
                dp[i][0][0]=dp[i-1][0][0];
                dp[i][0][1]=dungeon[i][0]+dp[i-1][0][1];
            }
            else
            {
                if(dungeon[i][0]+dp[i-1][0][1]>0)
                {
                    dp[i][0][0]=dp[i-1][0][0];
                    dp[i][0][1]=dungeon[i][0]+dp[i-1][0][1];
                }
                else
                {
                    dp[i][0][0]=-(dungeon[i][0]+dp[i-1][0][1])+1;
                    dp[i][0][1]=dungeon[i][0]+dp[i-1][0][1];
                }
            }
        }
        // 初始化第一行
        for(int i=1;i<n;i++)
        {
            if(dungeon[0][i]>=0)
            {
                dp[0][i][0]=dp[0][i-1][0];
                dp[0][i][1]=dungeon[0][i]+dp[0][i-1][1];
            }
            else
            {
                if(dungeon[0][i]+dp[0][i-1][1]>0)
                {
                    dp[0][i][0]=dp[0][i-1][0];
                    dp[0][i][1]=dungeon[0][i]+dp[0][i-1][1];
                }
                else
                {
                    dp[0][i][0]=-(dungeon[0][i]+dp[0][i-1][1])+1;
                    dp[0][i][1]=dungeon[0][i]+dp[0][i-1][1];
                }
            }
        }
        
        //dp开始
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                // 用temp1存向下走进入该方格的结果 temp2存向右进入该方格的结果
                if(dungeon[i][j]>0)
                {
                    temp1=dp[i-1][j][0];
                    temp2=dp[i][j-1][0];
                }
                else
                {
                    if(dungeon[i][j]+dp[i-1][j][1]>0)
                        temp1=dp[i-1][j][0];
                    else
                        temp1=-(dungeon[i][j]+dp[i-1][j][1])+1>dp[i-1][j][0]?-(dungeon[i][j]+dp[i-1][j][1])+1:dp[i-1][j][0];
                    if(dungeon[i][j]+dp[i][j-1][1]>0)
                        temp2=dp[i][j-1][0];
                    else
                        temp2=-(dungeon[i][j]+dp[i][j-1][1])+1>dp[i][j-1][0]?-(dungeon[i][j]+dp[i][j-1][1])+1:dp[i][j-1][0];
                }          
                if(temp1<temp2)
                {
                    //向下走
                    dp[i][j][0]=temp1;
                    dp[i][j][1]=dungeon[i][j]+dp[i-1][j][1];
                }
                else if(temp1>temp2)
                {
                    //向右走
                    dp[i][j][0]=temp2;
                    dp[i][j][1]=dungeon[i][j]+dp[i][j-1][1];
                }
                
                else
                {
                    //二者相等  选当前血量更大的那个
                    if(dungeon[i][j]+dp[i][j-1][1]>dungeon[i][j]+dp[i-1][j][1])
                    {
                        dp[i][j][0]=temp1;
                        dp[i][j][1]=dungeon[i][j]+dp[i-1][j][1];
                    }
                    else
                    {
                        dp[i][j][0]=temp2;
                        dp[i][j][1]=dungeon[i][j]+dp[i][j-1][1];
                    }
                }
            }
        }
        return dp[1][1][0];
        //return 0;
    }
    */
};