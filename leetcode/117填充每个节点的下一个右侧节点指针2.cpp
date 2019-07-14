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
    给定一个二叉树

    struct Node {
      int val;
      Node *left;
      Node *right;
      Node *next;
    }
    填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

    初始状态下，所有 next 指针都被设置为 NULL。



    示例：

    输入：{"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":null,"right":null,"val":4},"next":null,"right":{"$id":"4","left":null,"next":null,"right":null,"val":5},"val":2},"next":null,"right":{"$id":"5","left":null,"next":null,"right":{"$id":"6","left":null,"next":null,"right":null,"val":7},"val":3},"val":1}

    输出：{"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":{"$id":"4","left":null,"next":{"$id":"5","left":null,"next":null,"right":null,"val":7},"right":null,"val":5},"right":null,"val":4},"next":{"$id":"6","left":null,"next":null,"right":{"$ref":"5"},"val":3},"right":{"$ref":"4"},"val":2},"next":null,"right":{"$ref":"6"},"val":1}

    解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，如图 B 所示。


    提示：

    你只能使用常量级额外空间。
    使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。
*/
/*
    这一题和116的区别应该就是 116是满二叉树，而这个不是
    因为116我的解法也可以用到这道题上，就直接粘过来了
    不知道两个队列算不算满足常数额外空间
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