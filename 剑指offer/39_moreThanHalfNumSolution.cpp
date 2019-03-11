/*
    题目描述
    数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
    例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。
    如果不存在则输出0。
*/

/*
    可以使用摩尔投票法来解决，设置一个计数器和记忆元素，遍历数组，当计数器为0时，将当前遍历的元素赋给记忆元素，计数器为1.
    当计数器不为0时，当前遍历元素与记忆元素相同，计数器加一，否则减一。
    需要注意的是，如果数组中存在超过半数的元素，记忆元素存储的就是这个数字，但如果数组中不存在这样的数字，那么记忆元素存储的就不是正确答案
    所以在得到记忆元素后要再次遍历一遍数组来确认得到的是否是正确结果。
*/
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int result;
        int count=0;
        for(int i=0;i<numbers.size();i++)
        {
            if(count==0)
            {
                result=numbers[i];
                count++;
            }
            else if(numbers[i]==result)
                count++;
            else
                count--;
        }
        int times=0;
        for(int i=0;i<numbers.size();i++)
        {
            if(result==numbers[i])
                times++;
        }
        if(times<=numbers.size()/2)
            result=0;
        return result;
    }
};