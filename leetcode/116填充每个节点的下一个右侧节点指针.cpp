/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
/*
    给定一个完美二叉树，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：
    struct Node {
      int val;
      Node *left;
      Node *right;
      Node *next;
    }
    填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

    初始状态下，所有 next 指针都被设置为 NULL。
*/
/*
    我认为用队列辅助广搜，之后该指针就行了，因为这个树节点的定义里有next这个指针项，比较方便
    需要两个队列，进行分层次遍历，这个方法能过，但是效率一般 之比55%的快，用了两个队列，空间也比较高
    或者在之前的类似问题里见过有人使用一个level变量来进行记录层数（只是见过，没想到怎么实现）
*/
class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)
            return root;
        queue<Node*> q1;
        queue<Node*> q2;
        q1.push(root);
        Node* temp;
        while(!q1.empty()||!q2.empty())
        {
            while(!q1.empty())
            {
                temp=q1.front();
                q1.pop();
                if(temp->left)
                    q2.push(temp->left);
                if(temp->right)
                    q2.push(temp->right);
                if(!q1.empty())
                    temp->next=q1.front();
                else
                    temp->next=NULL;
            }
            while(!q2.empty())
            {
                temp=q2.front();
                q2.pop();
                if(temp->left)
                    q1.push(temp->left);
                if(temp->right)
                    q1.push(temp->right);
                if(!q2.empty())
                    temp->next=q2.front();
                else
                    temp->next=NULL;
            }
        }
        return root;
    }
};