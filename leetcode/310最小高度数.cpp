/*
    对于一个具有树特征的无向图，我们可选择任何一个节点作为根。图因此可以成为树，在所有可能的树中，具有最小高度的树被称为最小高度树。给出这样的一个图，写出一个函数找到所有的最小高度树并返回他们的根节点。

格式

该图包含 n 个节点，标记为 0 到 n - 1。给定数字 n 和一个无向边 edges 列表（每一个边都是一对标签）。

你可以假设没有重复的边会出现在 edges 中。由于所有的边都是无向边， [0, 1]和 [1, 0] 是相同的，因此不会同时出现在 edges 里。

示例 1:

输入: n = 4, edges = [[1, 0], [1, 2], [1, 3]]

        0
        |
        1
       / \
      2   3 

输出: [1]

示例 2:

输入: n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]

     0  1  2
      \ | /
        3
        |
        4
        |
        5 

输出: [3, 4]
说明:

 根据树的定义，树是一个无向图，其中任何两个顶点只通过一条路径连接。 换句话说，一个任何没有简单环路的连通图都是一棵树。
树的高度是指根节点和叶子节点之间最长向下路径上边的数量。
*/
/*
    暴力思路 遍历每个节点作为根节点，对每个根节点dfs，记录最小的高度
    注意这里是所有最小的结果
    主要注意的是给出的是一个边集合 而且是无向边 比较棘手

    一个比较好的思路是，找到整个图中最长的一条链，如果是奇数个节点 结果就是最中间的一个节点
    节点数是偶数个，结果就是中间的两个节点
    如果我们一层一层的去掉外层的叶子节点，最后剩下的一个或两个节点就是我们想要的结果
    实现上类似拓扑排序
*/
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> result;
        vector<vector<int>> neighbor(n, vector<int> ());    // 邻接矩阵
        queue<int> q;
        vector<int> degree(n,0);     // 节点度
        for(auto item: edges)
        {
            neighbor[item[0]].push_back(item[1]);  // 构造邻接矩阵
            neighbor[item[1]].push_back(item[0]);
            degree[item[0]]++;    // 构造节点度
            degree[item[1]]++;
        }
        for(int i=0;i<n;i++)
        {
            if(degree[i]<=1)
            {
                q.push(i);
            }
        }
        int num=n, leaf=0, node=0;   //用来记录剩余节点的个数
        while(num>2)
        {
            leaf=q.size();
            num-=leaf;
            for(int i=0;i<leaf;i++)
            {
                node=q.front();
                q.pop();
                for(auto item: neighbor[node])
                {
                    if((--degree[item])==1)
                        q.push(item);
                }
            }
        }
        // 构造解集
        while(!q.empty())
        {
            result.push_back(q.front());
            q.pop();
        }

        return result;
    }
};