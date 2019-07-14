/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
/*
    给定无向连通图中一个节点的引用，返回该图的深拷贝（克隆）。图中的每个节点都包含它的值 val（Int） 和其邻居的列表（list[Node]）。

    示例：


    输入：
    {"$id":"1","neighbors":[{"$id":"2","neighbors":[{"$ref":"1"},{"$id":"3","neighbors":[{"$ref":"2"},{"$id":"4","neighbors":[{"$ref":"3"},{"$ref":"1"}],"val":4}],"val":3}],"val":2},{"$ref":"4"}],"val":1}

    解释：
    节点 1 的值是 1，它有两个邻居：节点 2 和 4 。
    节点 2 的值是 2，它有两个邻居：节点 1 和 3 。
    节点 3 的值是 3，它有两个邻居：节点 2 和 4 。
    节点 4 的值是 4，它有两个邻居：节点 1 和 3 。


    提示：

    节点数介于 1 到 100 之间。
    无向图是一个简单图，这意味着图中没有重复的边，也没有自环。
    由于图是无向的，如果节点 p 是节点 q 的邻居，那么节点 q 也必须是节点 p 的邻居。
    必须将给定节点的拷贝作为对克隆图的引用返回。
*/
/*
    最直观的想法遍历一遍图，用一个hashmap来存储图的信息，之后根据图信息重建图
    感觉有些繁琐，但应该能实现
    
    或者，这道题其实用BFS 或者 DFS都可以做到，关键是如何避免遍历重复的节点
    可以用一个set来实现去重的目标
*/
class Solution {
    
public:
    /*
    Node* cloneGraph(Node* node) {
        if(node==NULL)
            return NULL;
        // BFS解法
        // 这个map存储的是原图与新图节点之间的映射
        // key是老图节点 value是新创建图的节点
        unordered_map<Node*, Node*> um;
        Node* copy=new Node(node->val, {});
        um[node]=copy;
        queue<Node*> q;
        q.push(node);
        while(!q.empty())
        {
            Node* cur=q.front();
            q.pop();
            for(auto next: cur->neighbors)
            {
                if(um.find(next)==um.end())
                {
                    um[next]=new Node(next->val, {});
                    q.push(next);
                }
                um[cur]->neighbors.push_back(um[next]);
            }
        }
        return copy;
    }
    */
    
    
    // 这个map存储的是原图与新图节点之间的映射
    // key是老图节点 value是新创建图的节点
    unordered_map<Node*, Node*> um;
    
    
    Node* cloneGraph(Node* node) {
        if(node==NULL)
            return NULL;
        // DFS解法
        if(um.find(node)==um.end())
        {
            um[node]=new Node(node->val, {});
            for(auto next: node->neighbors)
            {
                um[node]->neighbors.push_back(cloneGraph(next));
            }
        }
        return um[node];
    }
    
};