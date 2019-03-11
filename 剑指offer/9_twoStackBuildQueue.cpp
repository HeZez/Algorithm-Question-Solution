/*
    题目描述
    用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
*/

class Solution
{
    /*
        两个栈，
        插入元素向栈1中压入元素
        出队列时：
            当栈2为空时，将栈1的元素弹出并压入栈2中，弹出栈顶元素
            当栈2不为空时，弹出栈2栈顶元素
    */
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        int temp;
        if(!stack2.empty())
        {
            temp=stack2.top();
            stack2.pop();
            return temp;
        }
        else
        {
            while(!stack1.empty())
            {
                temp=stack1.top();
                stack2.push(temp);
                stack1.pop();
            }
            temp=stack2.top();
            stack2.pop();
            return temp;
        }
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};