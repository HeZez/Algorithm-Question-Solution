/*
    运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据   put 。

    获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。
    写入数据 put(key, value) - 如果密钥不存在，则写入其数据值。当缓存容量达到上限时，它应该在写入新数据之前删除最近最少     使用的数据值，从而为新的数据值留出空间。
    
    你是否可以在 O(1) 时间复杂度内完成这两种操作？

    示例:

    LRUCache cache = new LRUCache( 2  //缓存容量  );

    cache.put(1, 1);
    cache.put(2, 2);
    cache.get(1);       // 返回  1
    cache.put(3, 3);    // 该操作会使得密钥 2 作废
    cache.get(2);       // 返回 -1 (未找到)
    cache.put(4, 4);    // 该操作会使得密钥 1 作废
    cache.get(1);       // 返回 -1 (未找到)
    cache.get(3);       // 返回  3
    cache.get(4);       // 返回  4
*/
/*
    创建Cache的时候的给出存储元素个数，之后存放和获取的时候，操作很像map中的key和value
    在删除老元素的时候，要求删除最近最少使用的，这个“最近最少使用”应该怎么理解
    特别是O(1)时间复杂度实现最近最少使用
    如果不用考虑这一限制，可以用链表来模拟队列
    新进来的元素放到队列尾，被访问的数据放到队列尾，满了的时候将队列头去掉
    但是在链表和队列中查找元素是O(N)时间复杂度 不符合要求
    想要O(1)完成查找还是要结合hash表
    
    看了大佬的写法hash_map的value值可以是List的迭代器，学到了
    c++的list底层是用双向链表实现的，解决了使用单链表在本题中会出现的一些问题
*/

class LRUCache {
public:
    int size=0;
    unordered_map<int, int> LRU;
    unordered_map<int, list<int>::iterator> fastAccess;   // 对key和链表中的节点建立映射，O(1)访问
    list<int> l;
    
    LRUCache(int capacity) {
        size=capacity;
    }
    
    int get(int key) {
        if(LRU.find(key)==LRU.end())
            return -1;
        updateList(key);
        return LRU[key];
    }
    
    void put(int key, int value) {
        if(LRU.find(key)==LRU.end()&&LRU.size()==size)
        {
            deleteNode();
        }
        updateList(key);
        LRU[key]=value;
    }
    
    void updateList(int key)
    {
        if(LRU.find(key)!=LRU.end())
            l.erase(fastAccess[key]);
        l.push_front(key);
        fastAccess[key]=l.begin();
    }
    void deleteNode()
    {
        LRU.erase(l.back());
        fastAccess.erase(l.back());
        l.pop_back();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */