/*
题目描述
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。
假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。
（注意：这两个序列的长度是相等的）
*/

// 思路 用一个辅助栈来模拟这个过程

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        int length1=pushV.size();
        int length2=popV.size();
        //if(length1!=length2||(length1==0&&length2==0))
        //    return false;
        stack<int> helpStack;
        bool result=false;
        int flag=0;   // 用来记录入栈顺序数组的下标
        // 一个元素想要出栈，肯定要先入栈
        // 根据入栈顺序，该元素之前的元素肯定已经入栈
        for(int i=0;i<length2;i++)
        {
            while(helpStack.empty()||helpStack.top()!=popV[i])
            {
				if(flag>=length1)    
                    return false;
                helpStack.push(pushV[flag]);
                flag++;
                // 为什么这里是大于不是大于等于？
                // 因为当flag=length-1的时候 对应最后一个入栈元素
                // 之后flag++ flag=length1了 但是这时还不一定需要返回false
                // 以为可能这最后一个元素就和需要pop的元素相同了
                // 只有当再进行一次循环 flag再次+1 才返回false
                // 不过还有一个疑问是 当flag=length1的时候 pushV[flag]应该出现数组越界
                // 但是程序并没有出错 
				// 把这个if判断放到push操作之前，判断条件和我认为的一致
                // if(flag>length1)    
                //    return false;
            }
            helpStack.pop();
        }
        if(helpStack.empty())
            result=true;
        else
            result=false;
        return result;
    }
};