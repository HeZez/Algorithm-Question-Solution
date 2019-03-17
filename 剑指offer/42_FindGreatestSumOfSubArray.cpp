/*
    题目描述
    HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。
    今天测试组开完会后,他又发话了:在古老的一维模式识别中,常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。
    但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？
    例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。
    给一个数组，返回它的最大连续子序列的和，你会不会被他忽悠住？(子向量的长度至少是1)
*/
/*
    思考几种情况首先初始化累加SUM和为INT_MIN，接下来用一个变量temp来存储当前的子数组和
    如果temp<=0,这说明下一个数字加上之前的累加和是比这个数字本身还小的，所以累加和应该从这个数字开始重新计算
    在每次处理完当前数字后，比较temp和SUM，保留大的那一个
    或者采用动态规划的思想，写出递归方程，含义与这种方法相同
    f(i) = {
                array[i]  i=0||f(i-1)<=0
                f(i-1)+array[i]  i!=0&&f(i-1)>0
            }
*/

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int result=INT_MIN;
        int temp=0;
        if(array.size()==0)
            return result;
        for(int i=0;i<array.size();i++)
        {
            if(temp<=0)
                temp=array[i];
            else
                temp+=array[i];
            if(temp>result)
                result=temp;
        }
        return result;
    }
};