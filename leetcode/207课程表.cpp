/*
    现在你总共有 n 门课需要选，记为 0 到 n-1。

    在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们: [0,1]

    给定课程总量以及它们的先决条件，判断是否可能完成所有课程的学习？

    示例 1:

    输入: 2, [[1,0]] 
    输出: true
    解释: 总共有 2 门课程。学习课程 1 之前，你需要完成课程 0。所以这是可能的。
    示例 2:

    输入: 2, [[1,0],[0,1]]
    输出: false
    解释: 总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0；并且学习课程 0 之前，你还应先完成课程 1。这是不可能的。
    说明:

    输入的先决条件是由边缘列表表示的图形，而不是邻接矩阵。详情请参见图的表示法。
    你可以假定输入的先决条件中没有重复的边。
    提示:

    这个问题相当于查找一个循环是否存在于有向图中。如果存在循环，则不存在拓扑排序，因此不可能选取所有课程进行学习。
    通过 DFS 进行拓扑排序 - 一个关于Coursera的精彩视频教程（21分钟），介绍拓扑排序的基本概念。
    拓扑排序也可以通过 BFS 完成。
*/
/*
    根据提示就是找一个有向图中有没有环
    并且这道题的数据给的不是邻接矩阵 而是图的边缘列表
    对于图的dfs和bfs我一直掌握得不太好，在这里直接看了一下大佬的解法，并做了一下解释
    
    两种大的思路，一是进行拓扑排序
    二是根据边列表创建图邻接矩阵，之后dfs进行拓扑排序

    第一种这里代码给出的是基于kahn算法的拓扑排序
    其思路是这样的，首先 用一个邻接表记录每一个节点能够到达的下一个节点
    之后用一个数组来记录每一个节点的入度
    用一个队列来记录入度为0的节点， 每一次取队列头部的节点，之后将其能够到达的节点的入度减一，如果减一之后入度为0，则放入队列
    如果没有节点的入度为0，那么说明图中肯定有环
    另外一种有环的情况是环上单独有一个分支，这个分支的头是入度为0的，分支的尾部接在环上的一个节点x上
    这个x的入度不会被减到0，因为除了分支上的节点，其余能够进入x的节点都在环上，不会被加入到队列中
    一个节点的入度能够被减到0，说明能够到达他的前驱节点都是安全的没有环 进而该节点也是安全的
    记录这样安全的节点数是否等于课程数即可
    
    第二种 基于dfs的拓扑排序
    
*/
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        /*
        // 第一种思路kahn算法实现拓扑排序
        vector<vector<int>> adj(numCourses, vector<int>());
        // 记录节点的入度
        vector<int> degree(numCourses, 0);
        for(auto edge: prerequisites)
        {
            // 注意 题里给出来的边 [0, 1] 表示的是1指向0这样一条边，也就是1->0
            adj[edge[1]].push_back(edge[0]);  // 这是在记录这个节点可以到达哪些节点
            degree[edge[0]]++;   // 这是在记录节点入度
        }
        queue<int> q;
        // 把所有入度为0的节点都放到一个队列中
        for(int i=0;i<numCourses;i++)
            if(degree[i]==0)  q.push(i);
        
        while(!q.empty())
        {
            int cur=q.front();
            q.pop();
            numCourses--;
            for(auto next:adj[cur])
            {
                if(--degree[next]==0)     // 如果减一后入度为0 则该节点安全可以加入到队列中
                    q.push(next);  
            }
        }
        return  numCourses==0;
        */
        
        // 构建邻接表
        vector<vector<int>> adj(numCourses, vector<int>());
        for(auto edge: prerequisites)
        {
            // 注意 题里给出来的边 [0, 1] 表示的是1指向0这样一条边，也就是1->0
            adj[edge[1]].push_back(edge[0]);  // 这是在记录这个节点可以到达哪些节点
        }
        vector<bool> visited(numCourses, false);  // 用一个map来记录某一节点是否访问过
        vector<bool> finish(numCourses, false);  // finish中存的是不在环上的安全节点
        // 这里必须要有这个finish 如果仅用是否访问过来判断 会出差错
        for(int i=0;i<numCourses;i++)
        {
            if(!dfs(adj, visited, finish, i))
                return false;
        }
        return true;
    }
    bool dfs(vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& finish,int num)
    {
        // 这说明这个节点已经判断过不在环上了 可以直接返回 finish要先判断
        // 因为正常的深度遍历存在访问两次同一个节点的可能
        if(finish[num])  
            return true;
        // 如果这个节点尚不是安全节点，又再一次访问到了它，说明出现了环
        else if(visited[num])  
            return false;
        else
            visited[num]=true;
        for(auto next: adj[num])
        {
            if(!dfs(adj, visited, finish, next))
                return false;
        }
        finish[num]=true;
        return true;
    }
};