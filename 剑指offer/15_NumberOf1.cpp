/*
    题目描述
    输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
*/
/*
    两个思路 第一个：用一个无符号数字1来和原数字的二进制最后一位做与运算，之后把1左移一位，与原数字的二进制倒数第二位做与运算，以此类推
    第二个：用一个数字n-1与原数字n做与运算会把二进制中最右边的一个1变成0，多次这样做知道n变为0，操作的次数就是二级制中1的个数
*/


class Solution {
public:
     int  NumberOf1(int n) {
         /*
         // 第一种方法
         unsigned int flag=1;
         int result=0;
         while(flag)
         {
             if(n&flag)
                 result++;
             flag=flag<<1;
         }
         */
         // 第二种方法
         int result=0;
         while(n)
         {
             result++;
             n=(n-1)&n;
         }
         return result;
     }
};