/*
    题目描述
    输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，
    所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
*/

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int aLength=array.size();
        vector<int> result;
        //此题要求奇数和奇数 偶数和偶数之间的相对顺序不能发生变化
        //一个方法是使用额外的内存，创建一个和原数组一样大小的数组
        //统计偶数的个数，之后扫面原数组，按照顺序将数字填入正确的位置
        //或者不用统计个数，扫描两遍原数组，一次扫描奇数，一次扫描偶数
        for(int i=0;i<aLength;i++)
        {
            if(array[i]%2!=0)
                result.push_back(array[i]);
        }
        for(int i=0;i<aLength;i++)
        {
            if(array[i]%2==0)
                result.push_back(array[i]);
        }
        array=result;
    }
};