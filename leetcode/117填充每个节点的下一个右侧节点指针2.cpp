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
    
    用队列的话可能不算常数空间
    既然递归不算额外空间  那就用递归实现吧
*/
class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)
            return root;
        /*
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
        */
        
        
        // 递归的话 只处理当前节点 左子节点
        if(root->left)
        {
            // 由于不是满二叉树，左子树的next指针可能有几种情况
            // 1.指向当前节点右子树 2 如果右子树不存在 那就指向root的next的左子树或者右子树， 
            // 3.如果root没有next 那就指向NULL
            if(root->right)
                root->left->next=root->right;
            else
            {
                // 注意这里要找next并不是只找一次就可以了
                // 可能出现root->next没有子节点 但root->next->next有子节点的情况 所以要循环判断
                // 因为next这个节点的默认值就是null 所以要是找不到合适的下一个节点 不用设置就好了
                Node* node=root->next;
                while(node)
                {
                    if(node->left)
                    {
                        root->left->next=node->left;
                        break;
                    }
                    else if(node->right)
                    {
                        root->left->next=node->right;
                        break;
                    }
                    node=node->next;
                }
            }
        }
        // 右子节点
        if(root->right)
        {
            Node* node=root->next;
            while(node)
            {
                    if(node->left)
                    {
                        root->right->next=node->left;
                        break;
                    }
                    else if(node->right)
                    {
                        root->right->next=node->right;
                        break;
                    }
                    node=node->next;
            }
        }
        // 这里递归的时候要先右后左
        connect(root->right);
        connect(root->left);
        return root;
    }
};