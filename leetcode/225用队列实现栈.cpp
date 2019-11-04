/*
    使用队列实现栈的下列操作：

    push(x) -- 元素 x 入栈
    pop() -- 移除栈顶元素
    top() -- 获取栈顶元素
    empty() -- 返回栈是否为空
    注意:

    你只能使用队列的基本操作-- 也就是 push to back, peek/pop from front, size, 和 is empty 这些操作是合法的。
    你所使用的语言也许不支持队列。 你可以使用 list 或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。
    你可以假设所有操作都是有效的（例如, 对一个空的栈不会调用 pop 或者 top 操作）。 
*/

/*
    正常可能是用双队列辅助完成操作
    看了个评论区一个单队列的操作 服了。。。。。
*/

class MyStack {
private: queue<int> q;
public:
    /** Initialize your data structure here. */

    MyStack() {
        queue<int> q;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        // 用一个单一的队列，把队列尾之前的元素，从尾部插入到队列中
        int size=q.size()-1;
        for(int i=0;i<size;i++)
        {
            q.push(q.front());
            q.pop();
        }
        int res=q.front();
        q.pop();
        return res;
    }
    
    /** Get the top element. */
    int top() {
        // 因为前面只使用了一个队列 这样的话不能调换顺序， 直接调api了。。。。。。
        return q.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */