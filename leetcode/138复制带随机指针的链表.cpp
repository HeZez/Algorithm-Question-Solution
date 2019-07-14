/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
/*
    给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。
    要求返回这个链表的深拷贝。 

    示例：

    输入：
    {"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}

    解释：
    节点 1 的值是 1，它的下一个指针和随机指针都指向节点 2 。
    节点 2 的值是 2，它的下一个指针指向 null，随机指针指向它自己。


    提示：
    你必须返回给定头的拷贝作为对克隆列表的引用。
*/
/*
    感觉和133克隆图比较类似，需要一个map来进行原链表节点和拷贝链表节点的映射
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)
            return NULL;
        unordered_map<Node*, Node*> um;
        Node* copyHead=new Node(head->val, NULL, NULL);
        Node* temp=head;
        um[head]=copyHead;
        while(temp!=NULL)
        {    
            if(temp->next!=NULL&um.find(temp->next)==um.end())
                um[temp->next]=new Node(temp->next->val, NULL, NULL);
            
            if(temp->random!=NULL&um.find(temp->random)==um.end())
                um[temp->random]=new Node(temp->random->val, NULL, NULL);
                
            um[temp]->next=um[temp->next];
            um[temp]->random=um[temp->random];
            temp=temp->next;
        }
        return copyHead;
    }
};