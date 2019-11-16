/*
    中位数是有序列表中间的数。如果列表长度是偶数，中位数则是中间两个数的平均值。

    例如，
    [2,3,4] 的中位数是 3

    [2,3] 的中位数是 (2 + 3) / 2 = 2.5

    设计一个支持以下两种操作的数据结构：

    void addNum(int num) - 从数据流中添加一个整数到数据结构中。
    double findMedian() - 返回目前所有元素的中位数。

    示例：
    addNum(1)
    addNum(2)
    findMedian() -> 1.5
    addNum(3) 
    findMedian() -> 2
    进阶:

    如果数据流中所有整数都在 0 到 100 范围内，你将如何优化你的算法？
    如果数据流中 99% 的整数都在 0 到 100 范围内，你将如何优化你的算法？
*/
/*
    这道题一次面试的时候被问过，说了几种方法 虽然可行，但是一直没答到点子上

    最直接的思路，找中位数，构建一个平衡二叉搜索树，树根部位就是中位数(看奇偶的情况)
    但是由于数据流式输入 调整二叉树开销也不低，所以换一种思路，把整个数据分成两部分

    用两个堆来存储这两部分，左半部分是大顶堆，右半部分是小顶堆，大顶堆的堆顶小于小顶堆的堆顶
    在流式数据录入后，寻找当前数据应该在哪个堆里，插入进去之后，判断两个堆的元素个数大小关系
    因为我们想让两个堆中的元素个数相差不超过一，所以在每次插入元素之后就检查这一条件是否满足，
    如果不满足这一条件就调整两个堆，把某一个堆中多余的数字弹出来，放到另一个堆中
*/
class MedianFinder {
private: 
    priority_queue<int> pql; //默认大顶堆
    priority_queue<int, vector<int>, greater<int>> pqg; //小顶堆
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(pql.empty()||pqg.empty())
            pql.push(num);
        else
        {
            if(pql.top()>=num)
                pql.push(num);
            else
                pqg.push(num);
        }
        // 检查两部分是否平衡
        int temp=0;
        int l1=pqg.size(), l2=pql.size();
        if( abs( l1-l2 )>1 )
        {
            if(pqg.size()>pql.size())
            {
                temp=pqg.top();
                pqg.pop();
                pql.push(temp);
            }
            else
            {
                temp=pql.top();
                pql.pop();
                pqg.push(temp);
            }
        }
    }
    
    double findMedian() {
        int l1=pqg.size(), l2=pql.size();
        double res=0.0;
        if( (l1+l2)%2 )  //奇数个
            res=pqg.size()>pql.size()?pqg.top():pql.top();
        else
        {
            res=double(pqg.top()+pql.top())/2.0 ;
        }
        return res;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */