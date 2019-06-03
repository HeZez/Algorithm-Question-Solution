/*
    给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
    最高位数字存放在数组的首位， 数组中每个元素只存储一个数字。
    你可以假设除了整数 0 之外，这个整数不会以零开头。

    示例 1:

    输入: [1,2,3]
    输出: [1,2,4]
    解释: 输入数组表示数字 123。
    示例 2:

    输入: [4,3,2,1]
    输出: [4,3,2,2]
    解释: 输入数组表示数字 4321。
*/

/*
    主要是注意进位
    一个极端的特例是99 加一变成100 两位变三位了
*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len=digits.size();
        for(int i=len-1;i>=0;i--)
        {
            
            if(digits[i]==9)
            {
                // i=0的时候进位位数就加一了
                if(i==0)
                {
                    digits[i]=0;
                    digits.insert(digits.begin(), 1);
                }
                else
                {
                    digits[i]=0;
                }
            }
            else
            {
                digits[i]+=1;
                break;
            }
        }
        return digits;
    }
};