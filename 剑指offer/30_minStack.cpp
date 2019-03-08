/*
    题目描述
    定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
*/
/*
    因为要在O(1)的时间复杂度找到栈中的最小元素
    解决思路为使用两个栈来进行存储，一个栈进行正常操作，另一个栈辅助存储最小元素
    当一个元素进栈时，正常进栈1，与栈2top进行比较，如果比top小，进栈2 否则栈2的top元素再次进栈
    保证两个栈长度相同，栈2的top一直是栈1中当前最小元素
*/


class Solution {
public:
    void push(int value) {
        if(s2.empty())
        {
            s1.push(value);
            s2.push(value);
        }
        else
        {
            s1.push(value);
            if(value<s2.top())
                s2.push(value);
            else
                s2.push(s2.top());
        }
    }
    void pop() {
        if(!s1.empty()&&!s2.empty())
        {
            s1.pop();
            s2.pop();
        }
    }
    int top() {
        //if(!s1.empty())
        return s1.top();
    }
    int min() {
        //if(!s2.empty())
        return s2.top();
    }
private:
    stack<int> s1;
    stack<int> s2;
};